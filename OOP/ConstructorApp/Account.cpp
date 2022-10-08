#include "Account.h"
#include "CommonHeaders.h"

Account :: Account(int pAccNo, string pName, double pBalance) :accNo(pAccNo), name(pName), balance(pBalance) {
	cout << "Account created" << endl;
}


void Account ::Deposit(double pAmount) {
	if (pAmount < 0) {
		cout << "\nAmount to be deposited cannot be lesser than 0" << endl;
	}
	else {
		balance += pAmount;
		cout << "\nDeposit successful"
			<< "\nCurrent account balance is : " << balance
			<< endl;
	}
}

int Account::getAccNo() {
	return accNo;
}
double Account::getBalance() {
	return balance;
}
string Account::getName() {
	return name;
}