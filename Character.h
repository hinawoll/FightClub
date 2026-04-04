#ifndef FIGHTCLUB_CHARACTER_H
#define FIGHTCLUB_CHARACTER_H

#include <string>
#include "Skill.h"


class Character {
private:
    std::string name;
    Skill skills[2];
    int hp;
    int wins;
    int losses;

public:
    //constructor
    Character();
    Character(std::string name, Skill skills1, Skill skills2, int hp, int wins, int losses);

    //getter
    std::string getName() const;
    Skill getSkill(int index) const;//skills[index]
    int getHp() const;
    // int getMaxHp() const;
    int getWin() const;
    int getLoss() const;

    void takeDamage(int amount);
    bool isAlive() const;
    void addWin();
    void addLoss();

    void resetHp();

};

#endif //FIGHTCLUB_CHARACTER_H