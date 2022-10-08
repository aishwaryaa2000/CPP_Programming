// ConstructorApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonHeaders.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"


void printdetails(Account& acc) {
    cout << "\n\n-----Account Details-----" << endl;
    cout << "Account no is : "<< acc.getAccNo()
        << "\nName is : " << acc.getName()
        << "\nBalance is : "<<acc.getBalance()
        << endl;
}

int main()
{
    SavingsAccount acc1 = { 101,"Saving acc",1000 };
    CurrentAccount acc2 = { 102,"Current acc",5000 };
    printdetails(acc1);
    printdetails(acc2);
    acc2.Deposit(1000);
    acc2.withdraw(9000);
    printdetails(acc2);

    return EXIT_SUCCESS;
}
/*
If a class has abstract method=pure virtual method then the class becomes abstract automatically
and you cannot instantiate an abstract class
pure virtual HAS TO BE overidden else error
virtual may be overidden

accountPolymorphism

*/