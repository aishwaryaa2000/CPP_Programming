#include "Account.h"

Account::Account(int pAccNo, string pName, double pBalance)
{
	cout << "Account created with 3 parameters";
	accNo = pAccNo;
	name = pName;
	balance = pBalance;
}

Account::Account()
{
	name = "";
	accNo = 0;
	balance = 0;
}


Account::Account(int pAccNo, string pName)
{
	cout << "Account created with 2 parameters"<<endl;
	accNo = pAccNo;
	name = pName;
	balance = 1000;	
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
		balance = balance - pAmount;
		cout << "Withdrawal successful" << endl
			<< "Account balance is : "
			<< balance << endl;
	}
}

void Account::Deposit(double pAmount)
{
	if (pAmount < 0) {
		cout << "Deposit amount cannot be lesser than 0" << endl;
	}
	else {
		balance = balance + pAmount;
		cout << "Deposit successful" << endl
			<< "Account balance is : "
			<< balance << endl;

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

bool Account::IsNotEmpty()
{
	if (name == "") {
		return false;
	}
		return true;
}

Account::~Account()
{
	cout << "Deactivated";
}

