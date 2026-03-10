#include "Liquid.h"
#include <iostream>
#include <sstream>

using namespace std;

void Liquid::Init(string name, double density)
{
    setName(name);
    setDensity(density);
}

void Liquid::Display() const
{
    cout << "name = " << name << endl;
    cout << "density = " << density << endl;
}

void Liquid::Read()
{
    string name;
    double density;

    cout << "name = ? ";
    cin >> name;

    cout << "density = ? ";
    cin >> density;

    Init(name, density);
}

string Liquid::toString() const
{
    stringstream sout;
    sout << "name = " << name << endl;
    sout << "density = " << density << endl;
    return sout.str();
}