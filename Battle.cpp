#include "Battle.h"
#include "Character.h"
#include "Skill.h"
#include <iostream>
using namespace std;

//Constructor
Battle::Battle(Character* p1, Character* p2) {
    this->player1 = p1;
    this->player2 = p2;
    this->currentTurn = 1;
}

//prüft, ob jemand schon tod ist
bool Battle::isBattleOver() const {
    if (player1 == nullptr || player2 == nullptr) {
        return true;
    }
    if (!player1->isAlive() || !player2->isAlive()) {
        return true;
    }
    return false;
}
//
Character* Battle::getWinner() const {
    if (player1 == nullptr || player2 == nullptr) {
        return nullptr;
    }
    if (player1->isAlive() && !player2->isAlive()) {
        return player1;
    }
    if (player2->isAlive() && !player1->isAlive()) {
        return player2;
    }
    return nullptr;
}


void Battle::executeTurn() {
    Character* attacker;
    Character* defender;

    if (currentTurn == 1) {
        attacker = player1;
        defender = player2;
    } else {
        attacker = player2;
        defender = player1;
    }
    cout << "\n" << attacker->getName() << "'s turn." << endl;
    cout << "Choose skill (1 or 2): ";
    cout << "\n1. " << attacker->getSkill(0)->getName();
    cout << "\n2. " << attacker->getSkill(1)->getName() << endl;

    int choice;
    cout << "Choose skill (1 or 2): ";
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "\nInvalid choice. Please enter 1 or 2: ";
        cin >> choice;
    }

    Skill* skill = attacker->getSkill(choice - 1);


    cout << attacker->getName() << " uses " << skill->getName() << "!" << endl;

    skill->use(*attacker, *defender);

    cout << attacker->getName() << " HP: " << attacker->getHp() << endl;
    cout << defender->getName() << " HP: " << defender->getHp() << endl;

    //Runde wechseln
    if (currentTurn == 1) {
        currentTurn = 2;
    } else {
        currentTurn = 1;
    }
}

void Battle::startBattle() {
    if (player1 == nullptr || player2 == nullptr) {
        std::cout << "Battle konnte nicht gestartet werden.\n";
        return;
    }
    cout << "\nBattle starts: " << player1->getName() << " vs " << player2->getName() << endl;

    while (!isBattleOver()) {
        executeTurn();
    }

    Character* winner = getWinner();

    if (winner == player1) {
        player1->addWin();
        player2->addLoss();
    }else if(winner == player2){
        player2->addWin();
        player1->addLoss();
    }
    if (winner != nullptr) {
        cout << "Winner: " << winner->getName() << endl;
    }

}



