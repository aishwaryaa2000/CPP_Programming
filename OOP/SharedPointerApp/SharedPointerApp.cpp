// SharedPointerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>

using namespace std;

void printDetails(shared_ptr<int[]> nos, int size) {
    cout << "\nPointer value : " << nos << endl;
    for (int i = 0; i < size; i++) {
        cout << nos[i] << " ";
    }
}
int main()
{

    shared_ptr<int[]> numbers = make_shared<int[]>(5);
    //auto numbers =  make_shared<int[]>(5);
    //integer array : numbers is a shared pointer

    numbers[0] = 10;
    numbers[1] = 20;
    cout << "\nPointer value : " << numbers << endl;
    shared_ptr<int[]> another_numbers = numbers;
    cout << "\nPointer value : " << another_numbers << endl;
    printDetails(another_numbers, 5);
    //All the three variables will have the same address and point to the same address-like an alias
    return EXIT_SUCCESS;
}
