// ClassObject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonHeaders.h"
#include "Bar.h"




int main()
{

    //Stack allocation
    Bar f1;
    f1.setBarValue(200);
    f1.setBarValue(-100);
    f1.setBarValueUsingThis(300);

    //Heap allocation
    Bar* f2 = nullptr;
    f2 = new Bar();
    f2->setBarValue(500);
    //for f2 destructor is not automatically invoked
    delete f2;

    return EXIT_SUCCESS;

}
