#pragma once
#include "D1.h"
#include "D2.h"

class D3 : public D1, protected D2 {
    int d3;
public:
    D3(int b1_val, int b2_val, int d1_val, int b3_val, int d2_val, int d3_val);
    ~D3();
    void show_D3();
};