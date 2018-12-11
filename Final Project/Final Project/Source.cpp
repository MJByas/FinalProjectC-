//Michael Byas

//Final Project

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

struct stats {														// struct for class stats that will be needed
	int hp;
	string abi;
} Warrior, Mage, Thief;

void luck ();

int main() {
	struct stats;
	string name;
	int charClass;
	int choices[40];

	cout << "Hello wanderer! What is your name? " << endl;			// Introduction
	cin >> name;
	cout << "That's a strange name." << endl << endl;
	Sleep(100);
	do {
		cout << "What is your specialy?" << endl
			<< "1. Warrior" << endl
			<< "2. Mage" << endl
			<< "3. Thief" << endl;
		cin >> charClass;
		if (charClass <= 0 || charClass > 3)
			cout << "I didn't ask for anything but those 3." << endl;
	} while (charClass <= 0 || charClass > 3);

	if (charClass == 1) {
		cout << "Oh I should've guessed from the armor!" << endl;
		Warrior.hp = 10;
		Warrior.abi = "Gigaslash";
	}
	else if (charClass == 2) {
		cout << "I love seeing mages cast fireballs!" << endl;
		Mage.hp = 5;
		Mage.abi = "Fireball";
	}
	else {
		cout << "No stealing from me now!" << endl;
		Thief.hp = 7;
		Thief.abi = "Smoke bomb";
	}
}

void luck () {														// Random number generator with a seed of 0
	srand(time(0));
	int roll;
	int guess;
	roll = rand() % 10 + 1;
	do {															// Loop that resets the guess until you choose a desired value
		cout << "Guess a number between 1 to 10 :";
		cin >> guess;
		if (guess <= 0 || guess > 10)
			cout << "I said between 1 and 10!" << endl;
	} while (guess <= 0 || guess > 10);

	if (guess == roll)
		cout << "I guess you got lucky today, kid." << endl
		<< "I'll let you pass." << endl;
	else
		cout << "I knew you weren't good enough." << endl
		<< "Find another way across." << endl;
	
}