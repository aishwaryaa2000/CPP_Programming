#include "SavingsAccount.h"
#include "CommonHeaders.h"

SavingsAccount::SavingsAccount(int pAccNo, string pName, double pBalance) :Account(pAccNo, pName, pBalance) {
	cout << "Savings acc created" << endl;
}

void SavingsAccount::withdraw(double pAmount)
{
	int minimumBalance = 1000;
	if(pAmount<0) {
		cout << "\nAmount to be withdrawn cannot be lesser than 0" << endl;
	}
	else if (balance - pAmount > minimumBalance) {
		balance -= pAmount;
		cout << "\nWithdrawal successfull" << endl;
		cout << "Current account balance is : " << balance << endl;
	}
	else {
		cout << "Cannot withdraw as balance will become less than 1000" << endl;
	}
}
