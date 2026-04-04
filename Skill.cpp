#include "Skill.h"
#include "Character.h"

Skill::Skill() {
    name = "Unknown";
    damage = 0;
}
//constructor mit parameter
Skill::Skill(std::string name, int damage) {
    this->name = name;//this->name:このオブジェクトのメンバ変数name　name:引数としてのname
    this->damage = damage;
}

//getter
std::string Skill::getName() const {
    return name;
}
int Skill::getDamage() const {
    return damage;
}

//skillを使う関数
void Skill::use(Character& opponent) const {
    opponent.takeDamage(damage);//相手にダメージを与える
}