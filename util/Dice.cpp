//
// Created by extremer on 16.06.20.
//

#include <ctime>
#include <cstdlib>
#include "Dice.h"

int Dice::getRandomNumber(int lowerBound, int upperBound) {
    return lowerBound + rand() % (upperBound-lowerBound);
}

int Dice::getRandomNumber(int upperBound) {
    return getRandomNumber(0, upperBound);
}
