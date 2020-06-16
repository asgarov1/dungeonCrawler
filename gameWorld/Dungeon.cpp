//
// Created by Javid Asgarov on 16.06.20.
//

#include <iostream>
#include "Dungeon.h"

Dungeon::Dungeon() {
    initialise(0);
}

void Dungeon::reinitialise(int round) {
    fields.clear();
    initialise(round);
}


void Dungeon::initialise(int round) {
    for (int i = 0; i < height; ++i) {
        std::vector<Field> rowOfFields;
        for (int j = 0; j < width; ++j) {
            Field field(round);
            rowOfFields.emplace_back(field);
        }
        fields.emplace_back(rowOfFields);
    }
}



int Dungeon::getHeight() const {
    return height;
}

int Dungeon::getWidth() const {
    return width;
}

Field Dungeon::getField(int x, int y) {
    return fields.at(y).at(x);
}

bool Dungeon::checkIfEmpty() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (fields.at(i).at(j).getType() != Type::Empty) {
                return false;
            }
        }
    }
    return true;
}

void Dungeon::display(int x, int y) {
    for (int i = 0; i < height; ++i) {
        std::cout << "|";
        for (int j = 0; j < width; ++j) {
            Type type = fields.at(i).at(j).getType();
            std::string temp = " ";
            if (y == i && x == j) { temp = "-"; }
            std::cout << temp;
            if (type == Type::Danger) {
                std::cout << "D";
            } else if (type == Type::Bonus) {
                std::cout << "B";
            } else {
                std::cout << "0";
            }
            std::cout << temp << "|";
        }
        std::cout << std::endl;
    }
}

void Dungeon::emptyField(int x, int y) {
    fields.at(y).at(x).setType(Type::Empty);
}
