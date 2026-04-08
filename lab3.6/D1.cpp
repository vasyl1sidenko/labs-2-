#include "D1.h"
#include <iostream>
using namespace std;

D1::D1(int b1_val, int b2_val, int d1_val) : B1(b1_val), B2(b2_val), d1(d1_val) {}
D1::~D1() {}

void D1::show_D1() {
    cout << "class D1:" << endl;
    show_B1();
    show_B2();
    cout << "show_D1()" << endl << "D1::d1 = " << d1 << endl << endl;
}