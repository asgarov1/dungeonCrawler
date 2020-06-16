//
// Created by Javid Asgarov on 16.06.20.
//

#include <cstdlib>
#include "Dice.h"

/**
 * Generates random number (upper bound not inluded)
 * @param lowerBound
 * @param upperBound
 * @return
 */
int Dice::getRandomNumber(int lowerBound, int upperBound) {
    return lowerBound + rand() % (upperBound-lowerBound);
}

/**
 * Overloaded version of the random number method
 * @param upperBound
 * @return
 */
int Dice::getRandomNumber(int upperBound) {
    return getRandomNumber(0, upperBound);
}
