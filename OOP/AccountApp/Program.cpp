// AccountApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonHeaders.h"
#include "Account.h"
Account allAccounts[5];
int noOfAccounts = 0;

void createAccount() {
    int pAccNo;
    string pName;
    char ch;
    double pBalance;
    cout << "\nEnter account number"<<endl;
    cin >> pAccNo;
    cout << "Enter your name"<<endl;
    cin >> pName;
    cout << "Do you wish to enter initial balance else it will be set to 1000? (Y/N) : ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y') {
        cout << "\nEnter balance" << endl;
        cin >> pBalance;
        Account acc(pAccNo, pName, pBalance);
        allAccounts[noOfAccounts] = acc;
    }
    else {
        Account acc(pAccNo, pName);
        allAccounts[noOfAccounts] = acc;
    }
    noOfAccounts++;

}

void printDetails(Account pAllAccounts[5]) {

    cout << "\n-------ALL ACCOUNTS ---------"<<endl;
    Account currentAcc;
    for (int i = 0; i < noOfAccounts; i++) {
        currentAcc = pAllAccounts[i];
        cout << "Account number : " << currentAcc.getAccountNo()
            <<"Name of acc holder : " << currentAcc.getName()
            << endl << "Balance is : " << currentAcc.getBalance()
            << endl;

    }
}

void printDetails(Account pAccount) {

    cout << "\n-------ACCOUNTS DETAILS---------" << endl;
        cout<< "Account number : " << pAccount.getAccountNo()
            << endl <<"Name of acc holder : " << pAccount.getName()
            << endl << "Balance is : " << pAccount.getBalance()
            << endl;

}

Account& whoIsRichestAccHolder(Account pAllAccounts[5]) {
    /*
    Account& richest = pAllAccounts[0];
    cout << &richest<<endl;
    cout << &pAllAccounts[0];
    for (int i = 1; i < noOfAccounts; i++) {
        if (richest.getBalance() < pAllAccounts[i].getBalance()) {
            richest = pAllAccounts[i];
            cout << &richest;
        }

    }
    */
    /*Here richest is an alias to pAllAccounts[0] so whenever inside if we do richest=pAllAccounts[i]
    then our pAllAccounts[0] will get modified to pAllAcoounts[i] which is not desirable.
    Because our 1st element of array will get changed 
    */


    double amount = pAllAccounts[0].getBalance();
    int index;
    for (int i = 1; i < noOfAccounts; i++) {
        if (amount < pAllAccounts[i].getBalance()) {
            amount = pAllAccounts[i].getBalance();
            index = i;

        }
    }

    return pAllAccounts[index];

    /*for (int i = 0; i < noOfAccounts; i++) {
        Account& richest = pAllAccounts[i];
        if (amount == richest.getBalance()) {
            return richest;
        }
    }*/

}

Account& searchAccount() {
    int accNoToSearched;
    cout << "\nEnter the account number : ";
    cin >> accNoToSearched;
    for (int i = 0; i < noOfAccounts; i++) {
        Account& currentAcc = allAccounts[i];
        if (accNoToSearched == currentAcc.getAccountNo()) {
            return currentAcc;
        }
    }
    cout << "Account not found" << endl;
    Account nullAcc;
    return  nullAcc;

}

int main()
{
    cout << "BANKING SYSTEM!\n";
    int choice;
    while (true) {
        cout << "\n\n1-Create an account" << endl
             << "2-Withdraw from an account" << endl
             << "3-Deposit into an account" << endl
             << "4-Print details of a particular account" << endl
             << "5-Print details of all account holders" << endl
             << "6-Print who is the richest account holder" << endl
             << "7-EXIT"<<endl
             << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
        {
            Account& currentAcc = searchAccount();
            if (currentAcc.IsNotEmpty()) {
                double pAmount;
                cout << "Enter the amount to be withdrawn : ";
                cin >> pAmount;
                currentAcc.Withdraw(pAmount);
            }
        }
            break;
        case 3:
        {
            Account& currentAcc = searchAccount();
            if (currentAcc.IsNotEmpty()) {
                double pAmount;
                cout << "Enter the amount to be deposited : ";
                cin >> pAmount;
                currentAcc.Deposit(pAmount);
            }
        }
            break;
        case 4:
        {
            Account& currentAcc = searchAccount();
            if (currentAcc.IsNotEmpty()) {
                printDetails(currentAcc);
            }
        }
            break;
        case 5:
            printDetails(allAccounts);

            break;
        case 6:
        {
            Account& richest = whoIsRichestAccHolder(allAccounts);
            printDetails(richest);
        }
            break;
        case 7:
            return EXIT_SUCCESS;
        default:
            cout << "Wrong choice" << endl;
        }
    }

}



/*
When a variable is declared in one case, the next case is technically still in the same scope
so you could reference it there but if you hit that case without hitting this one first you
would end up calling an uninitialised variable. This error prevents that.

All you need to do is either define it before the switch statement
or use curly braces { } to make sure it goes out of scope before exiting a specific case.
*/