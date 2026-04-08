#include "B2.h"
#include <iostream>
using namespace std;

B2::B2(int x) : b2(x) {}
B2::~B2() {}

void B2::show_B2() {
    cout << "class B2:" << endl;
    cout << "show_B2()" << endl << "B2::b2 = " << b2 << endl << endl;
}