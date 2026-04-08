#include "D3.h"
#include <iostream>
using namespace std;

D3::D3(int b1_val, int b2_val, int d1_val, int b3_val, int d2_val, int d3_val) 
    : D1(b1_val, b2_val, d1_val), D2(b3_val, d2_val), d3(d3_val) {}
D3::~D3() {}

void D3::show_D3() {
    cout << "class D3:" << endl;
    show_D1();
    show_D2();
    cout << "show_D3()" << endl << "D3::d3 = " << d3 << endl << endl;
}