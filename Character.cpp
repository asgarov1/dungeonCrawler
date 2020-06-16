//
// Created by Javid Asgarov on 16.06.20.
//

#include <iostream>
#include "Character.h"
#include "util/Dice.h"


Character::Character(const Dungeon &dungeon) {
    placeOnRandomCoordinates(dungeon.getWidth(), dungeon.getHeight());
}

void Character::placeOnRandomCoordinates(int xLimit, int yLimit) {
    coordinateX = Dice::getRandomNumber(xLimit);
    coordinateY = Dice::getRandomNumber(yLimit);
}

bool Character::move(char direction, Dungeon *dungeon) {
    updateCoordinate(direction, dungeon->getWidth(), dungeon->getHeight());
    return interactWithField(dungeon);
}

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

int Character::getCorrespondingAttribute(Attribute attribute) {
    if (attribute == Attribute::Strength) {
        return strength;
    } else if (attribute == Attribute::Agility) {
        return agility;
    } else {
        return intelligence;
    }
}

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

int Character::getCoordinateX() const {
    return coordinateX;
}

int Character::getCoordinateY() const {
    return coordinateY;
}

void Character::displayStats() {
    std::cout << "Strength: " << strength;
    std::cout << ", Intelligence: " << intelligence;
    std::cout << ", Agility: " << agility;
    std::cout << ", Life: " << lifePoints;
    std::cout << ", StrengthXP: " << strengthXP;
    std::cout << ", IntelligenceXP: " << intelligenceXP;
    std::cout << ", AgilityXP: " << agilityXP << std::endl;
}
