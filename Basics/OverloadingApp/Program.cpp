// OverloadingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//If you want to define a function after main() then give func declaration before main()
void printDetails(int intValue);
void printDetails(float floatValue);
void printDetails(double doubleValue);
void printDetails(string strValue);
void printDetails(char charValue);
void printDetails(bool boolValue);

int main()
{
    //6 overloading
    printDetails(10);
    printDetails(10.5f);
    printDetails(10.55);
    string str = "Hello";
    printDetails(str);
    printDetails('#');
    printDetails(10 > 5);

}

void printDetails(int intValue) {
    cout << "Displaying integer overload(1) "
        << intValue
        << endl;
}

void printDetails(float floatValue) {
    cout << "Displaying float overload(2) "
        << floatValue
        << endl;
}

void printDetails(double doubleValue) {
    cout << "Displaying double overload(3) "
        << doubleValue
        << endl;
}

void printDetails(string strValue) {
    cout << "Displaying string overload(4) "
        << strValue
        << endl;
}

void printDetails(char charValue) {
    cout << "Displaying character overload(5) "
        << charValue
        << endl;
}

void printDetails(bool boolValue) {
    cout << "Displaying bool overload(6) "
        << boolValue
        << endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
