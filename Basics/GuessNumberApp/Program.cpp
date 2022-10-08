// GuessNumberApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "guessGameService.h"

using std::cout;
using std::endl;

int main()
{
    cout << "WELCOME TO THE RANDOM NUMBER GUESSING GAME \n"
        << "YOU ONLY HAVE 5 CHANCES TO GUESS THE NUMBER!" << endl
        << "--------------------------------------------" << endl;

    playGame();

    cout << "EXITING FROM THE GAME";

    return EXIT_SUCCESS;
}
