#include "Character.h"

Character::Character() {
    name = "Unknown";
    skills[0] = nullptr;
    skills[1] = nullptr;
    hp = 30;
    maxHp = 30;
    wins = 0;
    losses = 0;
}

Character::Character(std::string name, Skill* skill1, Skill* skill2, int hp) {
    this->name = name;
    this->skills[0] = skill1;
    this->skills[1] = skill2;
    this->hp = hp;
    this->maxHp = hp;//maxHpが引数にないから
    this->wins = 0;
    this->losses = 0;
}

//getter
std::string Character::getName() const {
    return name;
}
Skill* Character::getSkill(int index) const {
    //wenn die index eine ungültige Anzahl ist
    if (index < 0 || index > 1) {
        return nullptr;
    }
    return skills[index];
}
int Character::getHp() const {
    return hp;
}
int Character::getMaxHp() const {
    return maxHp;
}

int Character::getWin() const {
    return wins;
}
int Character::getLoss() const {
    return losses;
}

void Character::takeDamage(int amount) {//amount:どのくらいダメージを受けるか
    if (amount < 0) {// <= ist auch moeglich
        return;
    }
    hp -= amount;
    if (hp < 0) {
        hp = 0;
    }
}
void Character::heal(int amount) {
    if (amount < 0) {
        return;
    }

    hp += amount;

    //damit hp maxHp nicht überschreitet
    if (hp > maxHp) {
        hp = maxHp;
    }
}
bool Character::isAlive() const{
    if (hp > 0) {
        return true;
    }
    return false;
}
void Character::addWin(){
    wins++;
}
void Character::addLoss() {
    losses++;
}

void Character::resetHp() {
    hp = maxHp;
}