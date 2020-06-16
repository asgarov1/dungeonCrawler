//
// Created by Javid Asgarov on 16.06.20.
//

#include "Field.h"
#include "../util/Dice.h"

Field::Field(int difficultyIncrease) {
    int numberOfEnums = 3;
    type = static_cast<Type>(Dice::getRandomNumber(numberOfEnums));
    attribute = static_cast<Attribute>(Dice::getRandomNumber(numberOfEnums)+1);

    if (type == Type::Danger) {
        value = Dice::getRandomNumber(7, 17);
        value += difficultyIncrease;
    } else if (type == Type::Bonus) {
        value = Dice::getRandomNumber(1, 10);
    }
}

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
