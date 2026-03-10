#pragma once
#include <string>
#include "Liquid.h"

using namespace std;

class Solution
{
private:
    Liquid liquid;
    double concentration;

public:
    Liquid getLiquid() const { return liquid; }
    double getConcentration() const { return concentration; }

    void setLiquid(Liquid liquid) { this->liquid = liquid; }

    void setConcentration(double concentration)
    {
        if (concentration >= 0)
            this->concentration = concentration;
    }

    void Init(Liquid liquid, double concentration);
    void Read();
    void Display() const;
    string toString() const;
};
