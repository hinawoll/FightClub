cmake_minimum_required(VERSION 4.0)
project(FightClub)

set(CMAKE_CXX_STANDARD 20)

add_executable(FightClub main.cpp
        Character.cpp
        Character.h
        Skill.cpp
        Skill.h
        Battle.cpp
        Battle.h
        GameManager.cpp
        GameManager.h)
