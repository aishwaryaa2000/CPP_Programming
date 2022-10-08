#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(int pAccNo, string pName, double pBalance) :Account(pAccNo, pName, pBalance) {
	cout << "Current acc created" << endl;
}

void CurrentAccount::withdraw(double pAmount)
{
	if (pAmount < 0) {
		cout << "\nAmount to be withdrawn cannot be lesser than 0" << endl;
	}
	else if(balance - pAmount >= -overDraftLimit) {
		balance -= pAmount;
		cout << "\nWithdrawal successfull" << endl;
		cout << "Current account balance is : " << balance << endl;
	}
	else {
		cout << "Cannot withdraw as balance will become less than 1000" << endl;
	}
	
}
