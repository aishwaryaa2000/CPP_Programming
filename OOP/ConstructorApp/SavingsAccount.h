#pragma once
#include "Account.h"
class SavingsAccount:public Account
{
public:
	SavingsAccount(int pAccNo, string pName, double pBalance);
	void withdraw(double pAmount);

};

