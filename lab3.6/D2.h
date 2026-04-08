#pragma once
#include "B3.h"

class D2 : private B3 {
    int d2;
public:
    D2(int b3_val, int d2_val);
    ~D2();
    void show_D2();
};