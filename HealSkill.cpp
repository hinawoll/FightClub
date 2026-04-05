#include "HealSkill.h"
#include "Character.h"

HealSkill::HealSkill(std::string name, int heal)
    : Skill(name) {
    this->healAmount = heal;
}

void HealSkill::use(Character& user, Character& opponent) const {
    user.heal(healAmount);
}