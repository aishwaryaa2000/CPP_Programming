#include "Transaction.h"

Transaction::Transaction(double pAmount, string pDate, string pType) : amount(pAmount),date(pDate),type(pType)
{
	cout << "Transaction done" << endl;
}

double Transaction::getAmount()
{
	return amount;
}

string Transaction::getDate()
{
	return date;
}

string Transaction::getType()
{
	return type;
}
