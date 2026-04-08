#pragma once
#include "B1.h"
#include "B2.h"

class D1 : public B1, private B2 {
    int d1;
public:
    D1(int b1_val, int b2_val, int d1_val);
    ~D1();
    void show_D1();
};