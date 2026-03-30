#pragma once
#include <iostream>
#include <string>
using namespace std;

class Liquid
{
protected:
    string name;
    double density;

public:
    Liquid(string n = "", double d = 0);
    Liquid(const Liquid& l);

    string getName() const;
    double getDensity() const;

    void setName(string n);
    void setDensity(double d);

    void changeDensity(double d);

    operator string() const;

    friend ostream& operator<<(ostream& out, const Liquid& l);
    friend istream& operator>>(istream& in, Liquid& l);
};