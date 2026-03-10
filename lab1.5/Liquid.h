#pragma once
#include <string>
using namespace std;

class Liquid
{
private:
    string name;
    double density;

public:
    string getName() const { return name; }
    double getDensity() const { return density; }

    void setName(string name) { this->name = name; }

    void setDensity(double density)
    {
        if (density > 0)
            this->density = density;
    }

    void Init(string name, double density);
    void Read();
    void Display() const;
    string toString() const;
};