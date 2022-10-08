// RandomNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include<iostream>
#include "time.h"

using namespace std;

void printRandomNumberPseudo()
{
    /*usually feeding the srand the same seed every time
    because loop is going to take less than 1 second*/
    srand(time(NULL));
    cout << 1 + (rand()%100)<<endl;
}

void printRandomNumber()
{
    cout << 1 + (rand() % 100) << endl;
}

int main()
{
    cout << "Random number generator V1"<<endl;
    for (int i = 0; i <= 5; i++)
    {
        printRandomNumberPseudo();
    }

    /*
    You should use srand once, at the beginning.
    Each possible seed corresponds to a specific set of pseudorandom numbers,
    which are always the same when that seed is used
    */
    cout << "Random number generator V2"<<endl;
    srand(time(NULL));
    for (int i = 0; i <= 5; i++)
    {
        printRandomNumber();
    }

}