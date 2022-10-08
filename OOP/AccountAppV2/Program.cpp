// AccountApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonHeaders.h"
#include "Account.h"

vector<shared_ptr<Account>> manyAccounts;

enum choice { createAcc=1, withdraw, deposit, displaySingleAcc,displayAllAcc,printRichest,exitApp };

void printDetails(vector<shared_ptr<Account>> pAllAccounts) {

    cout << "\n-------------ALL ACCOUNTS ----------------" << endl;
    cout << std::left
        << std::setw(15)
        << "ACCNO"
        << std::left
        << std::setw(20)
        << "NAME"
        << std::left
        << std::setw(15)
        << "BALANCE"
        << endl;
    shared_ptr<Account> currentAcc;
    for (int i = 0; i < manyAccounts.size(); i++) {
        currentAcc = pAllAccounts[i];
        cout << std::left
            << std::setw(15)
            << currentAcc->getAccountNo()
            << std::left
            << std::setw(20)
            << currentAcc->getName()
            << std::left
            << std::setw(15)
            << currentAcc->getBalance()
            << endl;


    }
}

void printDetails(shared_ptr<Account> pAccount) {

    cout << "\n------------ACCOUNTS DETAILS--------------" << endl;
    cout << std::left
        << std::setw(15)
        << "ACCNO"
        << std::left
        << std::setw(20)
        << "NAME"
        << std::left
        << std::setw(15)
        << "BALANCE"
        << endl
        << std::left
        << std::setw(15)
        << pAccount->getAccountNo()
        << std::left
        << std::setw(20)
        << pAccount->getName()
        << std::left
        << std::setw(15)
        << pAccount->getBalance()
        << endl;

}


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
        auto a1 = make_shared<Account>(pAccNo, pName, pBalance);
        manyAccounts.push_back(a1);


    }
    else {
        auto a1 = make_shared<Account>(pAccNo, pName);
        manyAccounts.push_back(a1);

    }

}

shared_ptr<Account> whoIsRichestAccHolder(vector<shared_ptr<Account>> pAllAccounts) {

    double amount =  pAllAccounts[0]->getBalance();
    int index=0;
    for (int i = 1; i < manyAccounts.size(); i++) {
        if (amount < pAllAccounts[i]->getBalance()) {
            amount = pAllAccounts[i]->getBalance();
            index = i;

        }
    }

    return manyAccounts[index];

}
shared_ptr<Account> searchAccount() {
    int accNoToSearched;
    cout << "\nEnter the account number : ";
    cin >> accNoToSearched;
    for (int i = 0; i < manyAccounts.size(); i++) {
        shared_ptr<Account> currentAcc = manyAccounts[i];
        if (accNoToSearched == currentAcc->getAccountNo()) {
            return currentAcc;
        }
    }
    
    cout << "\nAccount does not exists" << endl;
    return  nullptr;

}

int main()
{
    cout << "BANKING SYSTEM!\n";
    int userInput;
    while (true) {
        cout << "\n\n1-Create an account" << endl
             << "2-Withdraw from an account" << endl
             << "3-Deposit into an account" << endl
             << "4-Print details of a particular account" << endl
             << "5-Print details of all account holders" << endl
             << "6-Print who is the richest account holder" << endl
             << "7-EXIT"<<endl
             << "Enter your choice : ";
        cin >> userInput;
        switch (userInput) {
        case createAcc:
            createAccount();

            break;

        case withdraw:
        {
            shared_ptr<Account> currentAcc = searchAccount();
            if (currentAcc) {
                double pAmount;
                cout << "Enter the amount to be withdrawn : ";
                cin >> pAmount;
                currentAcc->Withdraw(pAmount);
            }
        }

            break;

        case deposit:
        {
            shared_ptr<Account> currentAcc = searchAccount();
            if (currentAcc) {
                double pAmount;
                cout << "Enter the amount to be deposited : ";
                cin >> pAmount;
                currentAcc->Deposit(pAmount);
            }
        }

            break;

        case displaySingleAcc:
        {
            shared_ptr<Account> currentAcc = searchAccount();
            if (currentAcc) {
                printDetails(currentAcc);
            }
        }

            break;

        case displayAllAcc:
            printDetails(manyAccounts);

            break;

        case printRichest:
        {
            shared_ptr<Account> richest = whoIsRichestAccHolder(manyAccounts);
            printDetails(richest);
        }
            break;

        case exitApp:
            return EXIT_SUCCESS;

        default:
            cout << "Wrong choice" << endl;
        }
    }

}
