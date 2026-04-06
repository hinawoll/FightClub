#ifndef FIGHTCLUB_ATACKSKILL_H
#define FIGHTCLUB_ATACKSKILL_H
#include "Skill.h"

//Kindklasse1
class AttackSkill : public Skill {
private:
    int damage;

public:
    AttackSkill(std::string name, int damage);

    void use(Character& user, Character& opponent) const override;//override: der Inhalt dieser Funktion wird in der Kindklasse geschrieben

    std::string getDescription() const override;

};


#endif //FIGHTCLUB_ATACKSKILL_H

