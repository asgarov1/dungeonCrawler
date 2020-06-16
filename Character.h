//
// Created by extremer on 16.06.20.
//

#ifndef DUNGEONCRAWLER_CHARACTER_H
#define DUNGEONCRAWLER_CHARACTER_H


#include "gameWorld/Dungeon.h"

class Character {
    int lifePoints = 100;
    int strength = 5;
    int agility = 5;
    int intelligence = 5;

    int strengthXP = 0;
    int agilityXP = 0;
    int intelligenceXP = 0;

    int winningPoints = 0;

    int coordinateX{};
    int coordinateY{};
public:
    void placeOnRandomCoordinates(int xLimit, int yLimit);

    bool move(char direction, Dungeon *dungeon);

    void updateCoordinate(char direction, int xLimit, int yLimit);

    bool interactWithField(Dungeon *dungeon);

    int getCorrespondingAttribute(Attribute attribute);

    void increaseCorrespondingXP(Attribute attribute);

    explicit Character(const Dungeon& dungeon);

    int getCoordinateX() const;

    int getCoordinateY() const;

    void displayStats();
};


#endif //DUNGEONCRAWLER_CHARACTER_H
