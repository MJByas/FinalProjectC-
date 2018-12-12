//Michael Byas

//Final Project

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

struct stats {														// struct for class stats that will be needed
	int hp;
	string abi;
} Warrior, Mage, Thief;

void luck (int& a, int& b);

int main() {
	struct stats;
	string name;
	int charClass;
	int choices[40];

	cout << "Hello wanderer! What is your name? " << endl;			// Introduction
	cin >> name;
	cout << "That's a strange name." << endl << endl;
	Sleep(100);
	do {									// This is the code block for choosing your class
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
		Warrior.SnkAtk = "# Your attack fails because you're loud and you are hit";
		Warrior.HOAtk = "# You charge your enemy with a mighty blow and defeat him";
		Warrior.hp = 10;
	}
	else if (charClass == 2) {
		cout << "I love seeing mages cast fireballs!" << endl;
		Mage.SnkAtk = "# You charge up your fireball and throw it directly at the enemy";
		Mage.HOAtk = "# You are attacked mid spell charge and injured";
		Mage.hp = 6;
	}
	else {
		cout << "No stealing from me now!" << endl;
		Thief.SnkAtk = "# You sneak up on the enemy and cut them down from behind with your dagger";
		Thief.HOAtk = "# You charge the enemy but you don't pierce his armor and he throws you back";
		Thief.hp = 8;
	}
	cout << "Anyways let's move to the first location. We need to take this camp back from the orcs." << endl;
	cout << "Wanna sneak up and attack or head on attack?" << endl
		<< "1. Head on attack" << endl
		<< "2. Sneak attack" << endl;
	cin >> choices[0];
	switch (choices[0]) {
	case 1:
		if (charClass == 1)
			cout << Warrior.HOAtk << endl
			<< "You beat him in just one hit!" << endl << endl;
		else if (charClass == 2) {
			cout << Mage.HOAtk << endl
				<< "# Ulfang takes out the orc attacking you from behind" << endl
				<< "You need time to charge up your spells, mage." << endl << endl;
			Mage.hp - 2;
		}
		else {
			cout << Thief.HOAtk << endl
				<< "# You get back up after hitting your head and stab the orc in" << endl
				<< "# a weak spot with your dagger, thus killing him" << endl
				<< "Nice bounce back thief." << endl << endl;
			Thief.hp - 2;
		}
	case 2: 
		if (charClass == 1) {
			cout << Warrior.SnkAtk << endl
				<< "# The orc charges you but you raise your sword just in time to kill him" << endl
				<< "That was a close one, warrior." << endl << endl;
			Warrior.hp - 3;
		}
		else if (charClass == 2)
			cout << Mage.SnkAtk << endl
			<< "# The fireball is so strong it kills both orcs" << endl
			<< "God I love seeing fireballs exlpode!" << endl << endl;
		else
			cout << Thief.SnkAtk << endl
			<< "# Ulfang takes out his orc in a similar fashion" << endl
			<< "You are one pretty sneaky thief." << endl << endl;
	}
	cout << "We've taken the camp back" << endl
		<< "We need to rest here for the night" << endl
		<< "# You two rest for the night to gein some energy" << endl
		<< "# You awake to see a wandering gambler down the road" << endl << endl;
	cout << "Hello! My name is Tonpa." << endl
		<< "I see you're injured and I would like to make a wager." << endl << endl;
	cout << "What's in it for me and this wanderer?" << endl << endl;
	cout << "I will heal any wounds to both of you. The catch is that " << endl
		<< "if you lose I take half your health." << endl << endl;
	cout << "What do you say wanderer? Take on his bet?: " << endl;
	do {
		cout << "1. Yes" << endl
			<< "2. No" << endl << endl;
		cin >> choices[1];
		if (choices[1] <= 0 || choices[1] > 2)
			cout << "YES OR NO?" << endl;
	} while (choices[1] <= 0 || choices[1] > 2);
	luck(guess, roll);
	switch (choices[1]){
	case 1:	
		if (guess == roll) {
			if (charClass == 1)
				Warrior.hp = 10;
			else if (charClass == 2)
				Mage.hp = 6;
			else
				Thief.hp = 8;
			}
		else {
			if (charClass == 1)
				(Warrior.hp / 2);
			else if (charClass == 2)
				(Mage.hp / 2);
			else
				(Thief.hp / 2);
		}
	case 2:
		if (charClass == 1)
			(Warrior.hp / 2);
		else if (charClass == 2)
			(Mage.hp / 2);
		else
			(Thief.hp / 2);

	}
	
}

void luck (int& a, int& b) {														 // Random number generator with a seed of 0
	srand(unsigned(0));
	b = rand() % 10 + 1;
	do {															// Loop that resets the guess until you choose a desired value
		cout << "Guess a number between 1 to 10 :";
		cin >> a;
		if (a <= 0 || a > 10)
			cout << "I said between 1 and 10!" << endl;
	} while (a <= 0 || a > 10);

	if (a == b)
		cout << "I guess you got lucky today." << endl
		<< "I'll restore your health. " << endl;
	else
		cout << "I knew you weren't good enough." << endl
		<< "Say goodbye to your half your health" << endl;
}
