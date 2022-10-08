// PassByReferenceApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void updateMarkToZeroV1(int pMark) {
	//Pass by value-pMark is a copy of mark
	pMark = 0;
}

void updateMarkToZeroV2(int& pMark) {
	//pMark is a ref variable i.e a alias and not a ptr
	//So changes in the values are reflected
	pMark = 0;
	cout << "Address of pMark inside pass by alias is "
		 << &pMark << endl;
}

int main()
{
	int mark = 100;
	updateMarkToZeroV1(mark);
	cout << "Marks after update V1 is "
		<< mark << endl;
	
	updateMarkToZeroV2(mark);
	cout << "Marks after update V2 is "
		 << mark <<" address of mark is "<<&mark<<endl;

	return EXIT_SUCCESS;

}
