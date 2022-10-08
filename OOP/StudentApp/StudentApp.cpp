// StudentApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>  
#include<vector>  


using namespace std;

class Address {
public:
    string city;
    string state;
    int pin;

    Address(string pCity, string pState, int pPin) {
        city = pCity;
        state = pState;
        pin = pPin;
    }

    string ToString() {
        string addressString = city + " " + state + " " + to_string(pin);
        return addressString;
    }

    ~Address() {
        cout << "\nDestructor address";
    }

    Address& operator = (const Address& toCopy) {
        cout << "operator = overloading" << endl;
        this->city = toCopy.city;
        this->state = toCopy.state;
        this->pin =  0 * toCopy.pin;
        return *this;
    }

    Address(Address& toCopy) {
        cout << "\nUser defined copy constructor" << endl;
        this->city = toCopy.city;
        this->state = toCopy.state;
        this->pin = toCopy.pin;
    }
};

class Student {
public :
    int rollNo;
    string name;
    shared_ptr<Address> add;

    Student(int rno, string pname, shared_ptr<Address> a) {
        rollNo = rno;
        name = pname;
        add = a;
    }

    shared_ptr<Address> GetAddress() {
        return add;
    }

    string ToString() {

    }

    ~Student() {
        cout << "\nDestructor student";
    }


};

void printDetails(Student &s) {
    shared_ptr<Address> address = s.GetAddress();

    cout << "Roll no is : " << s.rollNo
        << "\nName is : " << s.name
        << "\nAddress is : " << (*address).ToString()<<endl;

}

int main()
{
        // Shared_ptr<Address> addOfSid = make_shared<Address>("Mumbai","Maharashtra",400706)
        auto addOfAishwarya = make_shared<Address>("Mumbai", "Maharashtra", 400706);
        cout << "City  is : " << (*addOfAishwarya).ToString() << endl;
        cout << "City  is : " << addOfAishwarya->ToString() << endl;
        string name = "Aishwarya";
        Student sid = { 101,name,addOfAishwarya };
        printDetails(sid);

        auto a1= make_shared<Address>("mumbai", "maha", 90021);
        auto a2 = make_shared<Address>("palakkad", "kerala", 90121);
        auto a3 = make_shared<Address>("jammu", "kashmir", 9121);
        vector<shared_ptr<Address>> manyAddress;
        manyAddress.push_back(a1);
        manyAddress.push_back(a2);
        manyAddress.push_back(a3);

        for (auto item : manyAddress) {
            cout << "Address using * derefencing is " << (*item).ToString() << endl;
            cout << "Address using -> is  " << item->ToString() << endl;
            cout << "State using -> is " << item->state << endl;

        }


}
