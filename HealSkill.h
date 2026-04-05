#ifndef FIGHTCLUB_HEALSKILL_H
#define FIGHTCLUB_HEALSKILL_H
#include "Skill.h"


//Kindklasse2
class HealSkill : public Skill {
private:
    int healAmount;

public:
    HealSkill(std::string name, int heal);

    void use(Character& user, Character& opponent) const override;
};


#endif //FIGHTCLUB_HEALSKILL_H