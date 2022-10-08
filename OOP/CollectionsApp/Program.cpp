// CollectionsApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<set>
#include<map>

using namespace std;

void case1() {

    //Doubly linked list//CRUD
    list<string> locations = { "Mumbai","Pune","Delhi","Delhi" };

    /*iterator begin() - start end() - after the last element
    for (auto item : locations) {
        cout << "Item is : " << item << endl;
    }
    */
    //Order remains the same,duplicates are not removed
    for (auto itr = locations.begin(); itr != locations.end(); ++itr) {
        cout << *(itr) << endl;
    }
}

void case2() {
    set<string> locations = { "Mumbai","Pune","Delhi","Delhi" };
    locations.insert("Kochin");
    locations.insert("Mumbai");
    locations.insert("Mumbai");
    //order becomes ascending and duplicates are removed as it is stored in tree
    for (auto itr = locations.begin(); itr != locations.end(); ++itr) {
        cout << *(itr) << endl;
    }
}

void case3() {
    map<string, string> dictionary = {
                                    {"MH","Maharashtra"},
                                    {"KA","Karanataka"},
                                    {"KA","Karanataka"},
                                    {"KB","sample"},
                                    {"KL","Kerala"}
    };

    for (pair<string, string> p : dictionary) {
        cout << "Key is : " << p.first
            << " Value is : " << p.second
            << endl;
    }

    for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr) {
        cout << itr->first << " : " << itr->second << endl;
    }

}

int main()
{
    map<int, int> dieFreqeuncy;
    int numberOnDie;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        numberOnDie =  1 + (rand() % 6);
        //cout << numberOnDie << endl;
        dieFreqeuncy[numberOnDie]++;
    }

    for (pair<int, int> p : dieFreqeuncy) {
        cout << "Number is : " << p.first
            << " Frequency is : " << p.second
            << endl;
    }

    for (auto itr = dieFreqeuncy.begin(); itr != dieFreqeuncy.end(); ++itr) {
        cout << itr->first << " -> " << itr->second << endl;
    }
}
