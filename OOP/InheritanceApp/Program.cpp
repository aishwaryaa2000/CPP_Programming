// InheritanceApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Man {

public:
    Man() {
        cout << "Man created" << endl;
    }
    void read() {
        cout << "Man is reading books" << endl;
    }

    //virtual methods can be overriden so run time polymorphism
    virtual void play() {
        cout << "Man is playing" << endl;
    }

    virtual ~Man() {
        cout << "Man destroyed"<<endl;
    }
};

class Boy : public Man {
public:
    Boy() {
        cout << "Boy created" << endl;
    }
    void eat() {
        cout << "Boy is eating" << endl;
    }
    void play() {
        cout << "Boy is playing" << endl;
    }
    ~Boy() {
        cout << "Boy destroyed" << endl;
    }
};

class Infact : public Man {
public:
    Infact() {
        cout << "Infact created" << endl;
    }
    void play() {
        cout << "Infact is playing" << endl;
    }
    ~Infact() {
        cout << "Infact destroyed" << endl;
    }
};

class Kid : public Man {
public:
    Kid() {
        cout << "Kid created" << endl;
    }
    void play() {
        cout << "Kid is playing" << endl;
    }
    ~Kid() {
        cout << "Kid destroyed" << endl;
    }
};
void caseStudy1() {
    cout << "Inside case study 1" << endl;

    Man x;
    x.read();
    x.play();

    
}
void caseStudy2() {
    cout << "Inside case study 2" << endl;

    Boy y;
    y.play(); //Boy's play
    y.read();
    y.eat();

}

void caseStudy3() {
    cout << "Inside case study 3" << endl;

    Man* x; //Nullptr expects an object of Man type or subclass of man
    x = new Man();
    x->read();
    x->play();
}
void caseStudy4() {
    cout << "Inside case study 4" << endl;
    Man* x; //Nullptr expects an object of Man type or subclass of man
    x = new Boy(); // runtime object creation
    //what is the type of x? Man
    ///and only methods of Man will be accessible
    x->read();
    x->play();//Man play is called - static binding
   // x->eat(); will not be accessible
}

void atThePark(Man* m) { //Man* m is lvalue and expects object of man or subclass of Man
    cout << "At the park" << endl;
    //Datatype of m is man so Man's play is called.This is static binding
    m->play();
    delete m; //destructor will be called here
}

void atThePark(Man&& m) { 
    //parameter has && bcoz we are passing a rvalue 
    //Man is the datatype of m so at run tim whichever subclass is called but method of man is called
    //static binding
    cout << "At the park in ref" << endl;
    m.play();
}


void caseStudy5() {
    cout << "Inside case study 5" << endl;
    //Boy b;
    //atThePark(&b);
    atThePark(new Man()); //new Man() rvalue
    atThePark(new Boy()); //new Boy() rvalue
    atThePark(new Kid()); //new Kid() rvalue
    atThePark(new Infact()); //new Infact() rvalue



}

void caseStudy6() {
    cout << "Inside case study 6" << endl;
    /*
    Man m; //lvalue
    Boy y; //lvalue
    Kid k; //lvalue
    Infact i; //lvalue
    */

    atThePark(Man());  //rvalue
    atThePark(Boy()); 
    atThePark(Kid()); 
    atThePark(Infact()); 

}

int main()
{
   //caseStudy
   //caseStudy4();
   caseStudy5();
   //caseStudy6();
    

    return EXIT_SUCCESS;
}

/*
int x =10
x=lvalue is addressable in storage memory
10=rvalue

int x;
x = 100;
int y = 200;
int& yref = y;
yref = 100;
int& ref = 200; reference variable cannot point to rvalue i.e 200
so use int&& ref = 200;
*/