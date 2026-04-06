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
    if (player1 == nullptr || player2 == nullptr) {
        return;
    }
    Character* attacker;
    Character* defender;

    if (currentTurn == 1) {
        attacker = player1;
        defender = player2;
    } else {
        attacker = player2;
        defender = player1;
    }

    cout << "\n--------------------" << endl;
    cout << attacker->getName() << "'s turn." << endl;
    showHp();

    for (int i = 0; i < 2; i++) {
        if (attacker->getSkill(i) != nullptr) {
            cout << i + 1 << ". "
                 << attacker->getSkill(i)->getName()
                 << " - "
                 << attacker->getSkill(i)->getDescription()
                 << endl;
        } else {
            cout << i + 1 << ". None" << endl;
        }
    }

    int choice;
    cout << "Choose skill (1 or 2): ";

    while (true) {
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Choose again: ";
            continue;
        }

        if (choice != 1 && choice != 2) {
            cout << "\nInvalid choice. Please enter 1 or 2: ";
            continue;
        }

        break;
    }

    Skill* skill = attacker->getSkill(choice - 1);


    cout << attacker->getName() << " uses " << skill->getName() << "!" << endl;

    skill->use(*attacker, *defender);

    showHp();

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

void Battle::showHp() const{
    cout << player1->getName() << " HP: " << player1->getHp() << endl;
    cout << player2->getName() << " HP: " << player2->getHp() << endl;
}



