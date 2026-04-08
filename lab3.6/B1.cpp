#include "B1.h"
#include <iostream>
using namespace std;

B1::B1(int x) : b1(x) {}
B1::~B1() {}

void B1::show_B1() {
    cout << "class B1:" << endl;
    cout << "show_B1()" << endl << "B1::b1 = " << b1 << endl << endl;
}