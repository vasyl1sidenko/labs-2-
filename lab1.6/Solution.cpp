#include "Solution.h"
#include <iostream>
#include <sstream>

using namespace std;

// Методи вкладеного класу Liquid 

void Solution::Liquid::Init(string name, double density)
{
    setName(name);
    setDensity(density);
}

void Solution::Liquid::Read()
{
    string name;
    double density;

    cout << "name = ? ";
    cin >> name;

    cout << "density = ? ";
    cin >> density;

    Init(name, density);
}

void Solution::Liquid::Display() const
{
    cout << "name = " << name << endl;
    cout << "density = " << density << endl;
}

string Solution::Liquid::toString() const
{
    stringstream sout;
    sout << "name = " << name << endl;
    sout << "density = " << density << endl;
    return sout.str();
}

// Методи класу Solution 

void Solution::Init(Liquid liquid, double concentration)
{
    setLiquid(liquid);
    setConcentration(concentration);
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

void Solution::Display() const
{
    cout << "Liquid:" << endl;
    liquid.Display();
    cout << "concentration = " << concentration << endl;
}

string Solution::toString() const
{
    stringstream sout;
    sout << "Liquid:" << endl;
    sout << liquid.toString();
    sout << "concentration = " << concentration << endl;
    return sout.str();
}