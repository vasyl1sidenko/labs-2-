#pragma once
#include <string>
using namespace std;

class Solution
{
public:
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