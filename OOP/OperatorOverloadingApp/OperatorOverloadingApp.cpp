// OperatorOverloadingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//DTO --> Data Transfer Object
//by default it is public-struct

class Student {
    friend ostream& operator<<(ostream& stream, const Student& student);

private:
    int foo=33;

public:

    string firstName, lastName;
    double cgpa;

    Student(string firstName, string lastName) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->cgpa = 0;
    }

    Student(string firstName, string lastName,double cgpa) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->cgpa = cgpa;
    }

    Student(Student& toCopy) {
        cout << "\ncopy this obj to current (this)" << endl;
        this->firstName = toCopy.firstName;
        this->lastName = toCopy.lastName;
        this->cgpa = 100* toCopy.cgpa;

    }
    string getFullName() {
        return firstName + " , " + lastName;
    }

    ~Student() {
        cout << "\nDestructor"<<endl;
    }


    Student& operator = (const Student& toCopy) {
        //changing the meaning of = in dravid=sachin
        cout << "operator = " << endl;
        this->firstName = toCopy.firstName;
        this->lastName = toCopy.lastName;
        this->cgpa = 10 * toCopy.cgpa;
        return *this;
    }



};

//a friend func can access private members

//into the buffer for cout
ostream& operator<<(ostream& stream, const Student& student) {
    stream << student.firstName
        << student.lastName
        << student.cgpa
        << student.foo;
    return stream;

}

int main()
{
    // cout << "Hello World!\n";
    Student sachin = { "Sachin", "Tendulkar" ,10 };
    cout << sachin.firstName
        << sachin.lastName
        << endl << sachin.getFullName();

    Student dravid = { "Rahul", "Dravid" ,9 };

    cout << "\nUsing variable declaration and initialising then copy cons is called";
    Student s3 = sachin;//copy cons called
    cout << s3.cgpa << endl;
    cout << dravid.cgpa;


    cout << "\nSimply initializing an already existing memory space so no copy cons called"<<endl;
    cout << "\nOverloading the = operator" << endl;
    dravid = sachin;    //copy constructor is not called
    //tocopy has s1 in operator()
    //Student& operator = (const Student& toCopy) 
    cout << dravid.firstName << endl;
    cout << dravid.cgpa<<endl;

    cout << "Operator << overloading \n";
    cout << sachin;
}