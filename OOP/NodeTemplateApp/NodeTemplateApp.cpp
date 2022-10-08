// NodeTemplateApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<class T>
class Node {
private:
    T data;
    shared_ptr<Node> next;

public:
    void setData(T data) {
        this->data = data;
    }
    T getData() {
        return data;
    }
    void setNext(shared_ptr<Node> n) {
        next = n;
    }
    shared_ptr<Node> getNext() {
        return next;
    }

    ~Node() {
        cout << "Node is destroyed" << endl;
    }

};

template<class T>
void printDetails(shared_ptr<Node<T>> node) {
    
    cout << "\n\nPrinting" << endl;
    while (node != nullptr)
    {
        cout << node->getData() << endl;
        node = node->getNext();
        cout << "Node :: " << node << endl;

    }
}
int main()
{
    /*
    STACK ALLOCATION
    Node<string> n1;
    //T will become string type
    n1.setData("Hello");
    Node<string> n2;
    n2.setData("Aishwarya");
    n1.setNext(n2)
    Node<string> n1;
    */

    //HEAP ALLOCATION
    auto n1 = make_shared<Node<int>>(); //return a pointer
    n1->setData(100);
    auto n2 = make_shared<Node<int>>(); //return a pointer
    n2->setData(200);
    auto n3 = make_shared<Node<int>>(); //return a pointer

    n3->setData(300);
    n1->setNext(n2);
    n2->setNext(n3);
    n3->setNext(nullptr);

    printDetails(n1);
    printDetails(n2);
    printDetails(n3);

    auto n4 = make_shared<Node<string>>(); //return a pointer
    n4->setData("Aishwarya");
    auto n5 = make_shared<Node<string>>(); //return a pointer
    n5->setData("Anand");
    auto n6 = make_shared<Node<string>>(); //return a pointer
    n6->setData("Aayush");

    n4->setNext(n5);
    n5->setNext(n6);
    n6->setNext(nullptr);

    printDetails(n4);
    printDetails(n5);
    printDetails(n6);



    return EXIT_SUCCESS;
}
 