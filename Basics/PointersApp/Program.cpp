// PointersApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "CommonHeaders.h"

void caseStudy1() {

	int mark;//expects an integer value
	mark = 100;

	int* ptrMark = nullptr; 
	ptrMark = &mark;

	//*(ptrMark) will give you the value at which ptrMark is pointing to
	if (ptrMark != nullptr) { 
		//always check if ptr is null or not before deferencing it
		
		cout << "Value of mark via ptr " << *ptrMark
			 << " and address of mark via ptr is " << ptrMark << endl;

		*ptrMark = *ptrMark + 20;
		cout << "Value after changing via deferencing " << mark<<endl;

	}
}

void swapUsingPtr(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void caseStudy2() {
	int no1 = 5;
	int no2 = 10;
	cout << "no1 is " << no1
		 << " and no2 is " << no2
		 << endl;

	swapUsingPtr(&no1, &no2); //pass the ptr

	cout << "After swap func() no1 is " << no1
		<< " and no2 is " << no2
		<< endl;

}

void printNumbers(int pnos[],int size) {


	cout << "\nPrinting inside fun() normarlly" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Element is : " << pnos[i] << endl;
	}

	cout << "\nPrinting inside fun() by deferencing" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Element is : " << *(pnos+i) << endl;
	}

}

void caseStudy3() {

	int nos[] = { 10,20,30,40,50 };
	cout << "Nos is " << nos << endl;
	//Gives address of the array

	cout << "Dereferencing array variable " << *nos;
	//this gives the element at 0th index of the array

	cout << *nos << " " << *(nos + 1) << " " << *(nos + 2) << endl;
	cout << *(nos + 10);
	cout << "\nSize of nos array is "
		 << size(nos) << endl;

	/*
	auto keyword means the type of the variable that is being
	declared will be automatically deducted from its initializer
	*/

	for (int item : nos) {
		cout << "Item value : " << item << endl;
	}

	printNumbers(nos,size(nos));

}

int main()
{
	caseStudy1();
	caseStudy2();
	caseStudy3();
	return EXIT_SUCCESS;
}
