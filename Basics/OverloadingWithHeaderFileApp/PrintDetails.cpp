#include <iostream>
#include "PrintDetails.h"

using namespace std;

void printDetails(int intValue) {
    cout << "Inside integer overload(1) "
        << intValue
        << " size is "
        <<sizeof(intValue)
        << endl;
}

void printDetails(float floatValue) {
    cout << "Inside float overload(2) "
        << floatValue
        << " size is "
        <<sizeof(floatValue)
        << endl;
}

void printDetails(double doubleValue) {
    cout << "Inside double overload(3) "
        << doubleValue
        << " size is "
        <<sizeof(doubleValue)
        << endl;
}

void printDetails(string strValue) {
    cout << "Inside string overload(4) "
        << strValue
        << " size is "
        <<sizeof(strValue)
        << endl;
}

void printDetails(char charValue) {
    cout << "Inside character overload(5) "
        << charValue
        << " size is "
        <<sizeof(charValue)
        << endl;
}

void printDetails(bool boolValue) {
    cout << "Inside bool overload(6) "
        << boolValue
        <<" size is "
        <<sizeof(boolValue)
        << endl;
}