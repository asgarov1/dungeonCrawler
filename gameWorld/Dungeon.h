//
// Created by Javid Asgarov on 16.06.20.
//

#ifndef DUNGEONCRAWLER_DUNGEON_H
#define DUNGEONCRAWLER_DUNGEON_H


#include <vector>
#include "Field.h"

class Dungeon {
    int height = 5;
    int width = 5;

    std::vector<std::vector<Field>> fields;

public:
    Dungeon();

    int getHeight() const;

    int getWidth() const;

    Field getField(int x, int y);

    bool checkIfEmpty();

    void display(int x, int y);

    void initialise(int round);
    void reinitialise(int round);

    void emptyField(int x, int y);
};


#endif //DUNGEONCRAWLER_DUNGEON_H
