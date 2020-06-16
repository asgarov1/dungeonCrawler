cmake_minimum_required(VERSION 3.16)
project(Dungeoncrawler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dungeoncrawler main.cpp gameWorld/Dungeon.cpp gameWorld/Dungeon.h gameWorld/Field.cpp gameWorld/Field.h Character.cpp Character.h gameWorld/Type.h gameWorld/Attribute.h util/Dice.cpp util/Dice.h util/StringUtil.cpp util/StringUtil.h)