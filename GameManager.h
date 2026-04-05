#ifndef FIGHTCLUB_GAMEMANAGER_H
#define FIGHTCLUB_GAMEMANAGER_H
#include "Character.h"
#include "Skill.h"


class GameManager {
private:
    Character characters[10];
    int characterCount;
    Skill* availableSkills[5];
    int skillCount;

public:
    GameManager();
    ~GameManager();

    void startGame( );
    void showMenu() const;
    void createCharacter();
    void setupDefaultSkills();
    void setupDefaultCharacters();
    int selectCharacter() const;
    void startBattle();
    void showAllCharacters() const;
    void showStatistics() const;

    bool handleInputError() const;
};


#endif //FIGHTCLUB_GAMEMANAGER_H