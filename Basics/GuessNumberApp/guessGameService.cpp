#include<iostream>
#include "randomNumberGenerator.h"

using std::cout;
using std::endl;
using std::cin;

bool getGameStatus(int no, int random) {

	if (no > random) {
		cout << "Sorry,Number Entered is Too High" << endl;
		return true;
	}
	else if (no < random) {
		cout << "Sorry,Number Entered is Too Low" << endl;
		return true;
	}

	//game over
	return false;

}

void displayWinOrLose(bool gameIsOn) {
	if (!(gameIsOn)) {
		cout << "\nHurray!You have guessed the number!" << endl;
	}
	else {
		cout << "\nOh no!You lose as you have exhaused your attempts" << endl;;
	}
}

void playGame() {

	int noByUser, attemptsLeft, randomNumber;
	bool gameIsOn; //gameStatus True is Game win
	char ch;

	do {
		gameIsOn = true;
		attemptsLeft = 5;
		randomNumber = GetRandomNumber();
		cout << "Random number has been generated "
			 << randomNumber << endl;

		while (gameIsOn && attemptsLeft) {
			cout << "\nEnter your guess : ";
			cin >> noByUser;
			gameIsOn = getGameStatus(noByUser, randomNumber);
			attemptsLeft--;
			cout << "Attempts left " << attemptsLeft << endl;
		}

		displayWinOrLose(gameIsOn);
		//Single responsibility

		cout << "The random number was " << randomNumber << endl;

		cout << "\nDo you wish to continue the game ? (Y/N) ";
		cin >> ch;

	} while (ch == 'Y' || ch == 'y');

}