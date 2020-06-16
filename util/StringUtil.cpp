//
// Created by Javid Asgarov on 16.06.20.
//

#include "StringUtil.h"

/**
 * Checks to see that the command in legal: W, A, S or D
 * @param input
 * @return boolean
 */
bool StringUtil::isLegalCommand(const std::string &input) {
    return input.find_first_not_of("WASD") == std::string::npos && input.length() == 1;
}
