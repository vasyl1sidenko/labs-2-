#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

Fraction::Fraction()
{
    whole = 0;
    part = 0;
}

Fraction::Fraction(long wholeValue, unsigned short partValue)
{
    Init(wholeValue, partValue);
}

long Fraction::GetWhole() const
{
    return whole;
}

unsigned short Fraction::GetPart() const
{
    return part;
}

void Fraction::SetWhole(long value)
{
    whole = value;
}

bool Fraction::SetPart(unsigned short value)
{
    if (value <= 99)
    {
        part = value;
        return true;
    }
    else
    {
        part = 0;
        return false;
    }
}

bool Fraction::Init(long wholeValue, unsigned short partValue)
{
    SetWhole(wholeValue);
    return SetPart(partValue);
}

void Fraction::Read()
{
    long w;
    unsigned short p;

    do
    {
        cout << "Whole part = ";
        cin >> w;
        cout << "Fractional part = ";
        cin >> p;
    } while (!Init(w, p));
}

void Fraction::Display() const
{
    cout << toString();
}

string Fraction::toString() const
{
    stringstream sout;
    sout << whole << "." << setw(2) << setfill('0') << part;
    return sout.str();
}

double Fraction::ToDouble() const
{
    if (whole >= 0)
        return whole + part / 100.0;
    else
        return whole - part / 100.0;
}