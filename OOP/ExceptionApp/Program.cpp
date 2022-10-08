// ExceptionApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <stdexcept>
using namespace std;

void f3() {
    cout << "Inside f3" << endl;
    //throw 100;
    //throw "f3 has thrown an error.f3 has something wrong";//this is of char* type
    string error = "This is an error of string type"; // this is string type
    throw error;
}
void f2() {
    cout << "Inside f2" << endl;
    f3();
    cout << "End of f2" << endl;
}
void f1() {
    cout << "Inside f1" << endl;
    f2();
    cout << "End of f1" << endl;
}

void caseStudy1() {
    try {
        f1();
    }
    catch (const int& value) {
        cout << "error happened because of " << value << endl;
    }
    catch (const string& value) {
        cout << "error happened because of " << value << endl;
    }
    catch (const char* value) {
        cout << "error happened because of : " << value << endl;
    }
}

void cubeEvenNo(int num) {

    if (num % 2 == 0) {
        cout << "Cube is : " << num * num * num<<endl;
    }
    else {

        throw invalid_argument("Number you passsed is odd.Number passed : "+to_string(num));
    }
}

void caseStudy2() {
    try {
        cubeEvenNo(2);
        cubeEvenNo(3);

    }
    catch (const exception& ex) {
        //polymorphic because invalid_argument is the child class
        //exception is the base class
        cout << ex.what();
        //what fun() gives the message passed in the constructor of invalid_argument
    }
}

class oddNumberNotAllowedException : public exception {
public:
    oddNumberNotAllowedException() {

    }

    const char* what() const {
        return "Odd numbers not allowed";
    }
};
void cubeEvenNoV2(int num) {

    if (num % 2 == 0) {
        cout << "Cube is : " << num * num * num << endl;
    }
    else {

       // throw oddNumberNotAllowedException("Number you passsed is odd.Number passed : " + to_string(num));
        throw oddNumberNotAllowedException();

    }
}

int main()
{
    try {
        cubeEvenNoV2(2);
        cubeEvenNoV2(3);

    }
    catch (const exception& ex) {
        //polymorphic because oddNumberNotAllowedException is the child class
        //exception is the base class
        cout << ex.what();
        //what fun() gives the message passed in the constructor of invalid_argument
    }
    catch (...) {
        cout << "Unknown error" << endl;
    }
    cout << "\nEnd of main"<<endl;

    return EXIT_SUCCESS;
}
/*
polymorphic means we have parent ref and child object is passed
so child method is called
*/