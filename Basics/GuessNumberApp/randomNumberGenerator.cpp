#include <ctime>
#include<iostream>

int GetRandomNumber() {

	//gives a random number between 1-100 according to time seed
	srand(time(0));
	int myRandomNumber = 1 + (rand() % 100);

	return myRandomNumber;

}
