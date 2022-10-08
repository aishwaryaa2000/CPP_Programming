#pragma once
#include "CommonHeaders.h"

class Account
{
private:
	int accNo;
	string name;
	double balance;
public:
	Account();
	Account(int pAccNo, string pName, double pBalance);
	Account(int pAccNo, string pName);
	void Withdraw(double pAmount);
	void Deposit(double pAmount);
	int getAccountNo();
	string getName();
	double getBalance();
	~Account();

};

