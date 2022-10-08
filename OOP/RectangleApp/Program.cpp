// RectangleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonHeader.h"
#include "Rectangle.h"

void printDetails(Rectangle& rectangle, const string& description) {
	cout <<"\n"<< description << endl
		<< "\nWidth of rectangle " << rectangle.getWidth()
		<< "\nHeight of rectangle " << rectangle.getHeight()
		<< "\nArea of rectangle " << rectangle.getArea()
		<< endl;
}

int main()
{
	Rectangle big(100, 50);
	printDetails(big, "Big details");

	Rectangle small(20, 30);
	printDetails(small, "Small details");

	Rectangle another = big;
	//our defined copy constructor is called
	//address of another and big is different
	printDetails(another, "another details");


	Rectangle anotherCC(big);
	//our defined copy constructor is called
	printDetails(anotherCC, "another details with copy constructor");


	Rectangle& bigger = small.whoIsBigger(big);
	//the value that is returned by whoIsBigger is big
	//now bigger is an alias so bigger and big are pointing to same memory loc

	printDetails(bigger, "bigger details given by function");


	return EXIT_SUCCESS;
}


/*
When a variable is declared in one case, the next case is technically still in the same scope 
so you could reference it there but if you hit that case without hitting this one first you 
would end up calling an uninitialised variable. This error prevents that.

All you need to do is either define it before the switch statement 
or use curly braces { } to make sure it goes out of scope before exiting a specific case.
*/