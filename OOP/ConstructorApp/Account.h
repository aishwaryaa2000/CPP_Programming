#pragma once
#include "CommonHeaders.h"
class Account
{
private:
	int accNo;
	string name;
protected:
	double balance;
public:
	Account(int pAccNo, string pName, double pBalance);
	void Deposit(double pAmount);
	virtual void withdraw(double pAmount) = 0;
	//pure virtual function
	int getAccNo();
	double getBalance();
	string getName();
};

