#include "Bar.h"
#include "CommonHeaders.h"

Bar::Bar() {
    cout << "\nBar is created" << endl;

}

void Bar::setBarValue(int pBar) {

    if (pBar > 100) {
        bar = pBar;
    }
    cout << "Bar is " << bar<<endl;
}

void Bar::setBarValueUsingThis(int bar) {

    /*internally, it has a this i.e Bar* this
    this will have the owner object of this method i.e f1 or f2
    */
    if (bar > 100) {
        this->bar = bar;
    }
    cout << "Bar is " << bar<<endl;
}

Bar::~Bar()
{
    //called automatically when object of class goes out of scope
    cout << "\nBar is destroyed";

}