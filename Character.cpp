#include "Character.h"

Character::Character() {
    name = "Unknown";
    hp = 30;
    wins = 0;
    losses = 0;
}

Character::Character(std::string name, Skill skills1, Skill skills2, int hp, int wins, int losses) {
    this->name = name;
    this->skills[0] = skills1;
    this->skills[1] = skills2;
    this->hp = hp;
    this->wins = wins;
    this->losses = losses;
}

//getter
std::string Character::getName() const {
    return name;
}
Skill Character::getSkill(int index) const {
    if (index < 0 || index > 1) {
        return skills[0];
    }
    return skills[index];
}
int Character::getHp() const {
    return hp;
};
// int getMaxHp() const;
int Character::getWin() const {
    return wins;
};
int Character::getLoss() const {
    return losses;
};

void Character::takeDamage(int amount) {//amount:どのくらいダメージを受けるか
    if (amount < 0) {// <= ist auch moeglich
        return;
    }
    hp -= amount;
    if (hp < 0) {
        hp = 0;
    }
};
bool Character::isAlive() const{
    if (hp > 0) {
        return true;
    }
    return false;
};
void Character::addWin(){
    wins++;
};
void Character::addLoss() {
    losses++;
};

void Character::resetHp() {
    hp = 30;
}