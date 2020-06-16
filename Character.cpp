//
// Created by Javid Asgarov on 16.06.20.
//

#include <iostream>
#include "Character.h"
#include "util/Dice.h"


/**
 * Constructor
 * @param dungeon is used to define the limits for coordinates
 */
Character::Character(const Dungeon &dungeon) {
    placeOnRandomCoordinates(dungeon.getWidth(), dungeon.getHeight());
}

/**
 * Gets random coordinates with the parameter bounds
 * @param xLimit - is the upper bound for x coordinate
 * @param yLimit - is the upper bound for y coordinate
 */
void Character::placeOnRandomCoordinates(int xLimit, int yLimit) {
    coordinateX = Dice::getRandomNumber(xLimit);
    coordinateY = Dice::getRandomNumber(yLimit);
}

/**
 * Moves the character in the given direction
 * @param direction
 * @param dungeon
 * @return
 */
bool Character::move(char direction, Dungeon *dungeon) {
    updateCoordinate(direction, dungeon->getWidth(), dungeon->getHeight());
    return interactWithField(dungeon);
}

/**
 * Updates the coordinate corresponding to the input
 * If the border is reached player won't move past it
 * @param direction
 * @param xLimit
 * @param yLimit
 */
void Character::updateCoordinate(char direction, int xLimit, int yLimit) {
    if (direction == 'D' && coordinateX < xLimit - 1) {
        coordinateX++;
    } else if (direction == 'A' && coordinateX > 0) {
        coordinateX--;
    } else if (direction == 'S' && coordinateY < yLimit - 1) {
        coordinateY++;
    } else if (direction == 'W' && coordinateY > 0) {
        coordinateY--;
    }
}

/**
 * Interaction with the Field
 * Based on field type different things can happen to the Character
 * @param dungeon
 * @return boolean, true if Character is still alive, false otherwise
 */
bool Character::interactWithField(Dungeon *dungeon) {
    std::cout << std::endl;
    Field field = dungeon->getField(coordinateX, coordinateY);
    if (field.getType() == Type::Empty) {
        return true;
    } else if (field.getType() == Type::Danger) {
        std::cout << "You have stepped on danger! :-0" << std::endl;
        int diceResult = Dice::getRandomNumber(1, 10);
        int characterAttribute = getCorrespondingAttribute(field.getAttribute());

        if (diceResult >= field.getValue() - characterAttribute) {
            std::cout << "You have prevailed! :-)" << std::endl;
            increaseCorrespondingXP(field.getAttribute());
            winningPoints += field.getValue();
        } else {
            std::cout << "Luck failed you! :-L" << std::endl;
            lifePoints -= field.getValue();
        }
    } else if (field.getType() == Type::Bonus) {
        std::cout << "You have found a bonus! =))" << std::endl;
        int fieldValue = field.getValue();
        if (fieldValue == 10) {
            lifePoints = 100;
        } else if (fieldValue > 6) {
            lifePoints += 5;
            if (lifePoints > 100) {
                lifePoints = 100;
            }
        } else {
            increaseCorrespondingXP(field.getAttribute());
        }
    }
    std::cout << "Life left " << lifePoints << ", winning points " << winningPoints << std::endl << std::endl;
    dungeon->emptyField(coordinateX, coordinateY);
    return lifePoints > 0;
}

/**
 * Calculates and returns the correct attribute value of the character
 * @param attribute
 * @return
 */
int Character::getCorrespondingAttribute(Attribute attribute) const {
    if (attribute == Attribute::Strength) {
        return strength;
    } else if (attribute == Attribute::Agility) {
        return agility;
    } else {
        return intelligence;
    }
}

/**
 * Increases the correct XP point of the Character
 * @param attribute
 */
void Character::increaseCorrespondingXP(Attribute attribute) {
    if (attribute == Attribute::Strength) {
        strengthXP++;
        if (strengthXP == 5) {
            strength++;
            strengthXP = 0;
        }
    } else if (attribute == Attribute::Agility) {
        agilityXP++;
        if (agilityXP == 5) {
            agility++;
            agilityXP = 0;
        }
    } else {
        intelligenceXP++;
        if (intelligenceXP == 5) {
            intelligence++;
            intelligenceXP = 0;
        }
    }
}

/**
 * Method that displays the stats of the Character
 */
void Character::displayStats() const {
    std::cout << "Strength: " << strength;
    std::cout << ", Intelligence: " << intelligence;
    std::cout << ", Agility: " << agility;
    std::cout << ", Life: " << lifePoints;
    std::cout << ", StrengthXP: " << strengthXP;
    std::cout << ", IntelligenceXP: " << intelligenceXP;
    std::cout << ", AgilityXP: " << agilityXP << std::endl;
}

//Getters

int Character::getCoordinateX() const {
    return coordinateX;
}

int Character::getCoordinateY() const {
    return coordinateY;
}
