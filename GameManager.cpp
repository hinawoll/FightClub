#include "GameManager.h"
#include <iostream>

#include "AttackSkill.h"
#include "Battle.h"
#include "HealSkill.h"

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

        while (true) {
            cin >> choice;

            if (handleInputError()) {//prüft, ob der Typ der eingabe gültig ist
                continue;
            }

            if (choice < 1 || choice > 5) {
                cout << "Invalid input. Please enter a number from 1 to 5: ";
                continue;
            }

            break;
        }

        if (choice == 1) {
            if (characterCount >= 10) {
                cout << "Character list is full.\n";
            } else {
                createCharacter();
            }
        }
        else if (choice == 2) {
            showAllCharacters();
        }
        else if (choice == 3) {
            if (characterCount < 2) {
                cout << "You need at least 2 characters to start a battle.\n";
            } else {
                startBattle();
            }
        }
        else if (choice == 4) {
            showStatistics();
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
    cout << "4. Show statistics\n";
    cout << "5. Exit\n";
    cout << "Choose: ";
}

void GameManager::createCharacter() {
    string name;
    int choice1, choice2;

    cout << "\nEnter character name: ";
    cin >> name;

    // die Liste von Skills anzeigen
    cout << "\n--- Available Skills ---\n";
    for (int i = 0; i < skillCount; i++) {
        cout << i + 1 << ". " << availableSkills[i]->getName() << "\n";
    }

    // die erste Skill auswählen
    cout << "Choose first skill: ";
    while (true) {
        cin >> choice1;

        if (handleInputError()) {//prüft, ob der Typ der eingabe gültig ist
            continue;
        }

        if (choice1 < 1 || choice1 > skillCount) {
            cout << "Invalid input. Choose again: ";
            continue;
        }
        break;
    }


    // die zweite Skill auswählen
    cout << "Choose second skill: ";

    while (true) {
        cin >> choice2;

        if (handleInputError()) {//prüft, ob der Typ der eingabe gültig ist
            continue;
        }

        if (choice2 < 1 || choice2 > skillCount) {
            cout << "Invalid input. Choose again: ";
            continue;
        }

        if (choice2 == choice1) {
            cout << "Choose a different skill: ";
            continue;
        }

        break;
    }

    // ein Character erstellen
    characters[characterCount] = Character(
        name,
        availableSkills[choice1 - 1],
        availableSkills[choice2 - 1],
        100
    );

    characterCount++;
    cout << "Character created successfully.\n";
}


int GameManager::selectCharacter() const{
    int choice;

    showAllCharacters();

    cout << "Choose character: ";
    while (true) {
        cin >> choice;

        if (handleInputError()) {//prüft, ob der Typ der eingabe gültig ist
            continue;
        }

        if (choice < 1 || choice > characterCount) {
            cout << "Invalid input. Choose again: ";
            continue;
        }

        break;
    }

    return choice - 1;
}

void GameManager::startBattle() {
    cout << "\n--- Battle Start ---\n";

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

    availableSkills[skillCount++] = new AttackSkill("Punch", 10);
    availableSkills[skillCount++] = new AttackSkill("Kick", 12);
    availableSkills[skillCount++] = new AttackSkill("Fireball", 15);
    availableSkills[skillCount++] = new HealSkill("Heal", 20);
}

void GameManager::setupDefaultCharacters() {
    characterCount = 0;

    characters[characterCount++] =//[0]
        Character("Knight", availableSkills[0], availableSkills[1], 100);

    characters[characterCount++] =//[1]
        Character("Wizard", availableSkills[2], availableSkills[3], 100);

    characters[characterCount++] =//[2]
        Character("Warrior", availableSkills[1], availableSkills[0], 100);
}

void GameManager::showAllCharacters() const {
    cout << "\n--- Character List ---\n";
    for (int i = 0; i < characterCount; i++) {
        cout << i + 1 << ". " << characters[i].getName() << endl;
    }
}

void GameManager::showStatistics() const {
    cout << "\n--- Results ---\n";
    for (int i = 0; i < characterCount; i++) {
        cout << characters[i].getName()
        << " | Wins: " << characters[i].getWin()
        << " | Losses: " << characters[i].getLoss()
        << endl;
    }
}

bool GameManager::handleInputError() const{
    if (cin.fail()) {//prüft, ob der Typ geeignet ist
        cin.clear();//die falsche Zustand reparieren
        cin.ignore(1000, '\n');//die falsche Eingabe max. 1000 Zeichen wegschmeißen, bis zum "\n".
        cout << "Invalid input. Please enter a number: ";
        return true;
    }
    return false;
}