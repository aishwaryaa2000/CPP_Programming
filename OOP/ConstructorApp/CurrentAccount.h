#pragma once
#include "Account.h"
#include"CommonHeaders.h"
class CurrentAccount:public Account
{
private:
	int overDraftLimit = 10000;
public:
	CurrentAccount(int pAccNo, string pName, double pBalance);
	void withdraw(double pAmount);
};


