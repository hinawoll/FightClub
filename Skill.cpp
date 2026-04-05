#include "Skill.h"

// コンストラクタ
Skill::Skill(std::string name) {
    this->name = name;
}

// getter
std::string Skill::getName() const {
    return name;
}

