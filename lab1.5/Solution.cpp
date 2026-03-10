#include "Solution.h"
#include <iostream>
#include <sstream>

using namespace std;

void Solution::Init(Liquid liquid, double concentration)
{
    setLiquid(liquid);
    setConcentration(concentration);
}

void Solution::Display() const
{
    cout << "Liquid: " << endl;
    liquid.Display();
    cout << "concentration = " << concentration << endl;
}

void Solution::Read()
{
    Liquid l;
    double concentration;

    cout << "Liquid:" << endl;
    l.Read();

    cout << "concentration = ? ";
    cin >> concentration;

    Init(l, concentration);
}

string Solution::toString() const
{
    stringstream sout;

    sout << "Liquid:" << endl;
    sout << liquid.toString();
    sout << "concentration = " << concentration << endl;

    return sout.str();
}
