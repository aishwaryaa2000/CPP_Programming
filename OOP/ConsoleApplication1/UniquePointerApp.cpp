// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void case1() {
    int* ptr = new int;
    (*ptr) = 10;
    cout << (*ptr) << endl;
    delete ptr;
}

void case2() {
    auto ptr = make_unique<int>();
    *ptr = 100;
    cout << ptr << endl;
    cout << *ptr << endl;
    //ptr arithmetic cannot be done like *ptr++
}


/*notice the& here
without & you will have to move the ownership to nos
beacause numbers is also a unique ptr
*/
void printDetails(unique_ptr<int[]>& nos,int size) {
    for (int i = 0; i < size; i++) {
        cout << nos[i] << " : ";
    }
}

void case3() {
    auto  numbers = make_unique<int[]>(5);
    //numbers is an array of 5 integers with default number as 0 
    //numbers = [0,0,0,0,0]
    numbers[0] = 10;
    numbers[1] = 20;
    cout << numbers << endl;
    //unique pointer numbers &numbers[0]

    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << endl;
    }

    /*
    auto numbersCopy = numbers;
    cannot do this as numbers is an unique ptr

    auto &numbersCopy = numbers; this is giving ref to a ptr

    unique_ptr<int[]>& numbersCopy = numbers; this is giving a ref to a unique ptr
    */

    auto newOwnerOfNumbers = move(numbers);
    //moving the ownership to newOwnerOfNumbers
    if (numbers == nullptr) {
        cout << "Numbers is now null";
    }

    cout << "\nFirst element  : " << newOwnerOfNumbers[0] << endl;
    printDetails(newOwnerOfNumbers, 2);
}

int main()
{
    
    //case1();
    //case2();
    case3();
    

    return EXIT_SUCCESS;
}


/*
For a particular data,only one pointer can point to it-unique ptr
only one owner of the particular data
a ptr points to data d
then move ownership of d from a ptr to b ptr
move ownership 
ptr a will become null
ptr b will start pointing to data d
*/