#ifndef FIGHTCLUB_SKILL_H
#define FIGHTCLUB_SKILL_H
#include <string>

class Character;//declarieren: "die Klasse Character existiert- (Details kommen später)"

class Skill {//←abstrakte Klasse
protected://zugreifbar innerhalb der eigenen Klasse und vererbte Klasse
    std::string name;

public:
    //Constructor
    Skill(std::string name);

    //getter
    std::string getName() const;//const:diese Funktion ändert die Inhalte der Objekt nicht

    //reine virtuelle Funktion 純粋仮想関数
    //der Inhalt dieser Funktion muss in der Kindklasse geschrieben werden
    virtual void use(Character& user, Character& opponent) const = 0;

    //destructor
    virtual ~Skill() {}
};


#endif //FIGHTCLUB_SKILL_H