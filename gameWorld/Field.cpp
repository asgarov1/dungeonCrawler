//
// Created by Javid Asgarov on 16.06.20.
//

#include "Field.h"
#include "../util/Dice.h"

/**
 * Constructor that randomly initializes the Field
 * @param difficultyIncrease
 */
Field::Field(int difficultyIncrease) {
    int numberOfEnums = 3;
    type = static_cast<Type>(Dice::getRandomNumber(numberOfEnums));
    attribute = static_cast<Attribute>(Dice::getRandomNumber(numberOfEnums));

    if (type == Type::Danger) {
        value = Dice::getRandomNumber(7, 17+1);
        value += difficultyIncrease;
    } else if (type == Type::Bonus) {
        value = Dice::getRandomNumber(1, 10+1);
    }
}


// Getters and Setters
Type Field::getType() const {
    return type;
}

Attribute Field::getAttribute() const {
    return attribute;
}

int Field::getValue() const {
    return value;
}

void Field::setType(Type type) {
    Field::type = type;
}
