#ifndef FIGHTCLUB_CHARACTER_H
#define FIGHTCLUB_CHARACTER_H

#include <string>
#include "Skill.h"


class Character {
private:
    std::string name;
    Skill* skills[2];//Skillは抽象クラスで、インスタンス化できないから、ポインタを使う。ポインタなら、Skill型として扱うけど中身は子クラスでもOK。
    int hp;
    int maxHp;
    int wins;
    int losses;

public:
    //constructor
    Character();
    Character(std::string name, Skill* skill1, Skill* skill2, int hp);

    //getter
    std::string getName() const;
    Skill* getSkill(int index) const;//skills[index]
    int getHp() const;
    int getMaxHp() const;
    int getWin() const;
    int getLoss() const;


    void takeDamage(int amount);
    void heal(int amount);

    bool isAlive() const;
    void addWin();
    void addLoss();

    void resetHp();

};

#endif //FIGHTCLUB_CHARACTER_H