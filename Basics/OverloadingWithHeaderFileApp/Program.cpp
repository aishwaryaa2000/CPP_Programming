// OverloadingWithHeaderFileApp.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "PrintDetails.h"

int main()
{
    printDetails(10);
    printDetails(10.5f);
    printDetails(10.55);
    string str = "Hello";
    printDetails(str);
    printDetails('#');
    printDetails(10 > 5);
}
