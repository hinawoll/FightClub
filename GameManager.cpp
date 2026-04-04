#include "GameManager.h"
#include <iostream>
#include "Battle.h"

using namespace std;

GameManager::GameManager(){
    characterCount = 0;
    skillCount = 0;
    setupDefaultSkills();
    setupDefaultCharacters();
}

void GameManager::startGame() {
    int choice = 0;

    while (choice != 5) {
        showMenu();
        cin >> choice;

        while (choice < 1 || choice > 5) {
            cout << "Invalid input. Please enter a number from 1 to 5: ";
            cin >> choice;
        }

        if (choice == 1) {
            if (characterCount >= 10) {
                cout << "Character list is full.\n";
            } else {
                characters[characterCount] = createCharacter();
                characterCount++;
                cout << "Character created successfully.\n";
            }
        }
        else if (choice == 2) {
            for (int i = 0; i < characterCount; i++) {
                cout << i + 1 << ". " << characters[i].getName() << endl;
            }
        }
        else if (choice == 3) {
            if (characterCount < 2) {
                cout << "You need at least 2 characters to start a battle.\n";
            } else {
                startBattle();
            }
        }
        else if (choice == 4) {
            showResult();
        }
        else if (choice == 5) {
            cout << "Game closed.\n";
        }
    }
}


void GameManager::showMenu() const{
    cout << "\n===== Fight Club =====\n";
    cout << "1. Create character\n";
    cout << "2. Show all characters\n";
    cout << "3. Start battle\n";
    cout << "4. Show results\n";
    cout << "5. Exit\n";
    cout << "Choose: ";
}

Character GameManager::createCharacter() {
    string name;
    int choice1, choice2;

    cout << "\nEnter character name: ";
    cin >> name;

    // die Liste von Skills anzeigen
    cout << "\n--- Available Skills ---\n";
    for (int i = 0; i < skillCount; i++) {
        cout << i + 1 << ". " << availableSkills[i].getName() << " (Damage: " << availableSkills[i].getDamage() << ")\n";
    }

    // die erste Skill auswählen
    cout << "Choose first skill: ";
    cin >> choice1;

    while (choice1 < 1 || choice1 > skillCount) {
        cout << "Invalid input. Choose again: ";
        cin >> choice1;
    }

    // die zweite Skill auswählen
    cout << "Choose second skill: ";
    cin >> choice2;

    while (choice2 < 1 || choice2 > skillCount) {
        cout << "Invalid input. Choose again: ";
        cin >> choice2;
    }

    // ein Character erstellen
    Character newCharacter(
        name,
        availableSkills[choice1 - 1],
        availableSkills[choice2 - 1],
        100,
        0,
        0
    );

    return newCharacter;
}


int GameManager::selectCharacter() const{
    int choice;

    for (int i = 0; i < characterCount; i++) {
        cout << i + 1 << ". " << characters[i].getName() << endl;
    }

    cout << "Choose character: ";
    cin >> choice;

    while (choice < 1 || choice > characterCount) {
        cout << "Invalid input. Choose again: ";
        cin >> choice;
    }

    return choice - 1;
}

void GameManager::startBattle() {
    cout << "\n--- Start Battle ---\n";

    if (characterCount < 2) {
        cout << "Not enough characters.\n";
        return;
    }

    //die erste Character auswählen
    cout << "\nChoose first character:\n";
    int index1 = selectCharacter();

    //die zweite Character auswählen
    cout << "\nChoose second character:\n";
    int index2 = selectCharacter();

    // wenn den selben Character ausgwählt wurde
    while (index1 == index2) {
        cout << "Choose a different character.\n";
        index2 = selectCharacter();
    }

    characters[index1].resetHp();
    characters[index2].resetHp();

    // Battle開始
    Battle battle(&characters[index1], &characters[index2]);
    battle.startBattle();
}

void GameManager::setupDefaultSkills() {
    skillCount = 0;

    availableSkills[skillCount++] = Skill("Punch", 10);
    availableSkills[skillCount++] = Skill("Kick", 12);
    availableSkills[skillCount++] = Skill("Fireball", 15);
    availableSkills[skillCount++] = Skill("Headbutt", 8);
}

void GameManager::setupDefaultCharacters() {
    characterCount = 0;

    characters[characterCount++] =
        Character("Knight", availableSkills[0], availableSkills[1], 100, 0, 0);

    characters[characterCount++] =
        Character("Mage", availableSkills[2], availableSkills[3], 100, 0, 0);
}



void GameManager::showResult() {
    cout << "\n--- Results ---\n";
    for (int i = 0; i < characterCount; i++) {
        cout << characters[i].getName() << " | Wins: " << characters[i].getWin() << " | Losses: " << characters[i].getLoss() << endl;
    }
}