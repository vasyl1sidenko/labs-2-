#include "D2.h"
#include <iostream>
using namespace std;

D2::D2(int b3_val, int d2_val) : B3(b3_val), d2(d2_val) {}
D2::~D2() {}

void D2::show_D2() {
    cout << "class D2:" << endl;
    show_B3();
    cout << "show_D2()" << endl << "D2::d2 = " << d2 << endl << endl;
}