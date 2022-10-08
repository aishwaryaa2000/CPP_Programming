// StaticPlayerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

class Player {
public:
    string name;
    int age;
    static int count;

    Player(string pname, int page) : name(pname),age(page) {
        cout << "\nPlayer constructed"<<endl;
        count = count + 1;
    }
    Player(string pname):Player(pname,18) {

    }
    int getCount() { 
        return count;
    }

    static int headCount() {
        //static method is called via class as it is a global method for the class
        //static method can only access static members
        return count;
    }
};
int Player::count = 0;

class Customer {
private:
    int id;
    string name;
    static int idAuto;
public:
    Customer(string pname) :name(pname),id(idAuto) {
        idAuto++;
    }
    int getId() {
        return id;
    }

};

int Customer::idAuto = 1001;

void caseStudy1() {
    Player p1 = { "Aishwarya",20 };
    cout << "Count is : " << p1.getCount() << endl;
    cout << "Calling a static method : "
        << Player::headCount();
    Player p2 = { "Anand",10 };
    cout << "Count is : " << p1.getCount() << endl;
    Player p3 = { "Aayush" };
    cout << "Count is : " << p1.getCount() << endl;

    cout << "Calling a static method : "
        << Player::headCount();
}



int main()
{
    
    Customer c1 = { "Aishwarya" };
    Customer c2 = { "Anand" };
    Customer c3 = { "Aayush" };
    cout << c1.getId() << endl;
    cout << c2.getId() << endl;
    cout << c3.getId() << endl;
    
    cout << "Hello";
    return EXIT_SUCCESS;
}
