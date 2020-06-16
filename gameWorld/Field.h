//
// Created by Javid Asgarov on 16.06.20.
//

#ifndef DUNGEONCRAWLER_FIELD_H
#define DUNGEONCRAWLER_FIELD_H

#include "Type.h"
#include "Attribute.h"

class Field {
    Type type;
    Attribute attribute;
    int value = 1;

public:
    explicit Field(int difficultyIncrease);

    Type getType() const;

    Attribute getAttribute() const;

    int getValue() const;

    void setType(Type type);

};


#endif //DUNGEONCRAWLER_FIELD_H
