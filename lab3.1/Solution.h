#pragma once
#include "Liquid.h"

class Solution : public Liquid
{
private:
    double concentration;

public:
    Solution(string n = "", double d = 0, double c = 0);
    Solution(const Solution& s);

    double getConcentration() const;
    void setConcentration(double c);

    void changeConcentration(double c);

    operator string() const;

    friend ostream& operator<<(ostream& out, const Solution& s);
    friend istream& operator>>(istream& in, Solution& s);
};