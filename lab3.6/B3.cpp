#include "B3.h"
#include <iostream>
using namespace std;

B3::B3(int x) : b3(x) {}
B3::~B3() {}

void B3::show_B3() {
    cout << "class B3:" << endl;
    cout << "show_B3()" << endl << "B3::b3 = " << b3 << endl << endl;
}