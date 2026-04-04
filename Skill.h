#ifndef FIGHTCLUB_SKILL_H
#define FIGHTCLUB_SKILL_H
#include <string>

class Character;//foward declaration 型の存在だけ知ってたらいいので、これでいい
// #include "Character.h" ←Characterの中身まで必要な場合

class Skill {
protected:
    std::string name;
    int damage;

public:
    Skill();
    Skill(std::string name, int damage);//Constructor

    std::string getName() const;//const:「この関数はオブジェクトの中身を変更しません」という宣言。間違って変更するのを防げる
    int getDamage() const;
    void use(Character& opponent) const;//&がないとCharacterがコピーされるかも。でも本物にダメージを与えたいから&を使う|const:「skill自身は変わらない」
};


#endif //FIGHTCLUB_SKILL_H