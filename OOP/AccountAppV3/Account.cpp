#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include "Transaction.h"
#include <ctime>


Account::Account(int pAccNo, string pName, double pBalance)
{
	/*
	std::time_t now = std::time(0);
	char* dt = ctime(&now);
	Tues Aug  23 14:07:41 2022
	*/
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
	string dt= to_string(tPtr->tm_mday) 
				+ "/" + to_string((tPtr->tm_mon)+1) 
				+ "/" + to_string((tPtr->tm_year)+1900);
				
	cout << "Account created with 3 parameters"<<endl;
	accNo = pAccNo;
	name = pName;
	balance = pBalance;
	Transaction t1 = Transaction(pBalance, dt, "Deposit");
	transactionList.push_back(t1);
}

Account::Account()
{
	name = "";
	accNo = 0;
	balance = 0;
}


Account::Account(int pAccNo, string pName)
{
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
	string dt = to_string(tPtr->tm_mday) 
				+ "/" + to_string((tPtr->tm_mon) + 1) 
				+ "/" + to_string((tPtr->tm_year)+1900);
	cout << "Account created with 2 parameters"<<endl;
	accNo = pAccNo;
	name = pName;
	balance = 1000;	
	Transaction t1 = Transaction(balance, dt, "Deposit");
	transactionList.push_back(t1);
}



void Account::Withdraw(double pAmount)
{

	if (pAmount < 0) {
		cout << "Withdrawal amount cannot be lesser than 0" << endl;
	}
	else if(balance-pAmount<1000) {
		cout << "You cannot withdraw this amount as account balance will become less than 1000" << endl;
	}
	else {
		time_t t = time(NULL);
		tm* tPtr = localtime(&t);
		string dt = to_string(tPtr->tm_mday)
					+ "/" + to_string((tPtr->tm_mon) + 1)
					+ "/" + to_string((tPtr->tm_year) + 1900);
		balance = balance - pAmount;
		cout << "Withdrawal successful" << endl
			<< "Account balance is : "
			<< balance << endl;
		Transaction t1 = Transaction(balance, dt, "Withdraw");
		transactionList.push_back(t1);
	}
}

void Account::Deposit(double pAmount)
{
	if (pAmount < 0) {
		cout << "Deposit amount cannot be lesser than 0" << endl;
	}
	else {
		time_t t = time(NULL);
		tm* tPtr = localtime(&t);
		string dt = to_string(tPtr->tm_mday) 
					+ "/" + to_string((tPtr->tm_mon) + 1) 
					+ "/" + to_string((tPtr->tm_year) + 1900);
		balance = balance + pAmount;
		cout << "Deposit successful" << endl
			<< "Account balance is : "
			<< balance << endl;
		Transaction t1 = Transaction(balance, dt, "Deposit");
		transactionList.push_back(t1);

	}
}

int Account::getAccountNo()
{
	return accNo;
}

string Account::getName()
{
	return name;
}

double Account::getBalance()
{
	return balance;
}

void Account::PrintTransactionDetails()
{
	cout << "\n	   TRANSACTION LOG 	 " ;
	cout << "\n-----------------------------------------" << endl;
	cout << std::left
		<< std::setw(15)
		<< "DATE"
		<< std::left
		<< std::setw(15)
		<< "AMOUNT"
		<< std::left
		<< std::setw(15)
		<< "TYPE"
		<< "\n-----------------------------------------" << endl;
		
	for (int i = 0; i < transactionList.size(); i++) {
		cout << std::left
			<< std::setw(15)
			<< transactionList[i].getDate()
			<< std::left
			<< std::setw(15)
			<< transactionList[i].getAmount()
			<< std::left
			<< std::setw(15)
			<< transactionList[i].getType()
			<< endl;
	}
	
}


Account::~Account()
{
	cout << "\nDeactivated";
}

