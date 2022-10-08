// RAIIRule5App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>

using namespace std;

class MyArray {
	
private:
	int array_size;
	int* data = nullptr;

public:
	MyArray(int size):array_size(size) {
		data = new int[array_size] {0};

	}
	MyArray(MyArray& toCopy) {
		array_size = toCopy.array_size;
		data = new int[array_size];
		//Deep copy
		for (int i = 0; i < array_size; i++) {
			data[i] = toCopy.data[i];
		}
	}

	//Move constructor-rvalue&&
	MyArray(MyArray&& toMove) {
		//steal the resources of an object which goes out of scope-memory efficiency increases
		cout << "MOVE CONSTRUCTOR" << endl;
		array_size = toMove.array_size;

		//making it point to the heap
		data = toMove.data;
		toMove.data = nullptr;
		toMove.array_size = 0;
	}	

	//subscript operator
	int& operator[](int i) {
		return data[i];
	}
	//move assignment operator-rvalue&&
	MyArray& operator=(MyArray&& toMove) {
		cout << "MOVE ASSIGNMENT" << endl;
		array_size = toMove.array_size;
		delete[] data;
		data = toMove.data;
		//steal resource
		toMove.data = nullptr;
		toMove.array_size = 0;

		return *this;
	}
	
	//copy assignment operator
	MyArray& operator=(const MyArray& toCopy) {
		array_size = toCopy.array_size;
		int* new_arr = new int[array_size];
		for (int i = 0; i < array_size; i++) {
			new_arr[i] = toCopy.data[i];
		}
		delete[] data;
		data = new_arr;
		return *this;
	}



	int* begin() {
		return data;
	}
	int* end() {
		return data + array_size;
	}

	~MyArray() {
		cout << "Destructor" << endl;
		delete[] data;
	}
};

void case1() {
	MyArray arr1(3);
	arr1[0] = 10;
	arr1[1] = 20;
	arr1[2] = 30;

	for (auto a : arr1) {
		cout << a << endl;
	}
	
	/*
	SHALLOW COPY
	Internally in cpp if I write
	MyArray arr2 = arr1;
	then internally the copy constructor was called wherein the data is MOVED FROM arr1 to arr2
	so any changes to arr2 will get reflected in arr1 and vice-versa


	DEEP COPY
	If I write my own copy constructor then
	data is copied from	arr1 to arr2 which is in different locations
	so any changes to arr2 will NOT get reflected in arr1 and vice-versa

	If we explicitly write a copy constructor then,user defined copy constructor is given more preference
	*/

	//copy constructor called
	MyArray arr2 = arr1;
	arr1[2] = 300;
	for (auto a : arr2) {
		cout << a << endl;
	}
	for (auto a : arr1) {
		cout << a << endl;
	}
}

MyArray  makeArray() {
	MyArray arr(5);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	return arr;
}

void case2() {
	MyArray arr1(3);
	arr1[0] = 10;
	arr1[1] = 20;
	arr1[2] = 30;

	for (auto a : arr1) {
		cout << a << endl;
	}


	// MyArray arr2 = move(arr1); calls move constructor
	//steals resources of arr1 and gives it to arr2.Now arr1 becomes NULL

	MyArray arr2 = makeArray();
	/*This calls the move constructor automatically as compiler knows
	  that the arr returned by the makeArray() has scope limited to the function itself
	  so it steals the resources of arr to arr2
	*/

	for (auto a : arr2) {
		cout << a << endl;
	}
}

void case3() {
	MyArray arr1(3);
	arr1[0] = 10;
	arr1[1] = 20;
	arr1[2] = 30;


	for (auto a : arr1) {
		cout << a << endl;
	}


	MyArray arr2(4);
	arr2[0] = 100;
	arr2[1] = 200;
	arr2[2] = 300;
	arr2[3] = 400;

	arr1 = arr2;//copy assignment

	for (auto a : arr1) {
		cout << a << endl;
	}

	for (auto a : arr2) {
		cout << a << endl;
	}
}

void case4() {
	MyArray arr1(3);
	arr1[0] = 10;
	arr1[1] = 20;
	arr1[2] = 30;

	arr1 = makeArray(); //move assignment

	for (auto a : arr1) {
		cout << a << endl;
	}

}
void display(int no) {
	cout << "In display method : " << no << endl;
}

int main()
{
	MyArray arr1(3);
	arr1[0] = 10;
	arr1[1] = 20;
	arr1[2] = 30;
	cout << "Using  function" << endl;
	for_each(arr1.begin(), arr1.end(), display);
	cout << "Using lambda function" << endl;
	for_each(arr1.begin(), arr1.end(), 
		[](auto i) {	
			cout << "In display method : " << i << endl;
		});

	return EXIT_SUCCESS;
}
