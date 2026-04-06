#include "AttackSkill.h"
#include "Character.h"

AttackSkill::AttackSkill(std::string name, int damage)
    : Skill(name) {
    this->damage = damage;
}

void AttackSkill::use(Character& user, Character& opponent) const {
    opponent.takeDamage(damage);
}

std::string AttackSkill::getDescription() const {
    return "Deals " + std::to_string(damage) + " damage to one enemy.";
}
