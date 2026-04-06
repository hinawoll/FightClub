#ifndef FIGHTCLUB_BATTLE_H
#define FIGHTCLUB_BATTLE_H

class Character;//ポインタだけ使ってるから中身しらなくていいし、#includeより軽くて安全らしい

class Battle {
private:
    Character* player1;
    Character* player2;
    int currentTurn;

public:
    //Constructor
    Battle(Character* p1, Character* p2);

    void startBattle();
    void executeTurn();
    bool isBattleOver() const;
    Character* getWinner() const;
    void showHp() const;
};


#endif //FIGHTCLUB_BATTLE_H