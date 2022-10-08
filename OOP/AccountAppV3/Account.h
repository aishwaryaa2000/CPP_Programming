#pragma once
#include "CommonHeaders.h"
#include "Transaction.h"
class Account
{
private:
	int accNo;
	string name;
	double balance;
	vector<Transaction> transactionList;
public:
	Account();
	Account(int pAccNo, string pName, double pBalance);
	Account(int pAccNo, string pName);
	void Withdraw(double pAmount);
	void Deposit(double pAmount);
	int getAccountNo();
	string getName();
	double getBalance();
	void PrintTransactionDetails();
	~Account();

};

