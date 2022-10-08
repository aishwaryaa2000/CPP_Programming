// DynamicArrayApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonHeaders.h"

void caseStudy1() {

    /* Stores it on heap or freestore 
       new keyword allocates new memory 
       and gives the address
    */
    int* numbers = new int[5];
    int entries = 0;

    while (true) {
        cout << "Enter Number : ";
        cin >> numbers[entries];
        if (cin.fail()) break;
        entries++;
    }

    cout << "\nDisplaying the values" << endl;

    for (int i = 0; i < entries; i++) {
        cout << numbers[i] << " " << endl;
    }


    delete[] numbers;
    /*
    prevents memory leak
    so deallocate the heap memory that was used
    */
}

void caseStudy2() {

    int* numbers = new int[5];
    int entries = 0;

    while (true) {
        cout << "Enter Number : ";
        cin >> numbers[entries];
        if (cin.fail()) break;
        entries++;
        if (entries == 5) {
            /*Create a temp array twice the current size
            copy all elements to temp array
            numbers point should point to new array
            */
            int* tempNumbers = new int[10];
            for (int i = 0; i < entries; i++) {
                tempNumbers[i] = numbers[i];
            }

            delete[] numbers; //deallocate the new int[5]
            numbers = tempNumbers;


        }
    }

    cout << "\nDisplaying the values" << endl;

    for (int i = 0; i < entries; i++) {
        cout << numbers[i] << " " << endl;
    }


    delete[] numbers;
}

void caseStudy3() {

    int* numbers = new int[5];    
    int entries = 0;
    int CuurentSize = 5, newCurrentSize = 5;
    while (true) {
        cout << "Enter Number : ";
        cin >> numbers[entries];
        if (cin.fail()) break;
        entries++;
        if (entries == CuurentSize) {
            /*Create a temp array twice the current size
            copy all elements to temp array
            numbers point should point to new array
            */
            newCurrentSize = 2 * CuurentSize;
            int* tempNumbers = new int[newCurrentSize];
            CuurentSize = newCurrentSize;
            cout << "\nNew Size is " << CuurentSize<<endl;
            for (int i = 0; i < entries; i++) {
                tempNumbers[i] = numbers[i];
            }

            delete[] numbers; //deallocate the new int[5]
            numbers = tempNumbers;


        }
    }

    cout << "\nDisplaying the values" << endl;

    for (int i = 0; i < entries; i++) {
        cout << numbers[i] << " " << endl;
    }


    delete[] numbers;
}


int main()
{
    //caseStudy1();
    //caseStudy2();
    caseStudy3();
}


