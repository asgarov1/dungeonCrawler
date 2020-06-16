//
// Created by extremer on 16.06.20.
//

#include "StringUtil.h"

bool StringUtil::isLegalCommand(const std::string &input) {
    return input.find_first_not_of("WASD") == std::string::npos && input.length() == 1;
}
