#pragma once
#include "CommonHeaders.h"
class Transaction
{
	double amount;
	string date;
	string type;
public:
	Transaction(double pAmount, string pDate, string pType);
	double getAmount();
	string getDate();
	string getType();
};

