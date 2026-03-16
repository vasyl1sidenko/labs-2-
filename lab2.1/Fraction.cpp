#include "Fraction.h"
#include <sstream>

Fraction::Fraction()
{
    Init(0, 1);
}

Fraction::Fraction(unsigned int f, unsigned int s)
{
    Init(f, s);
}

Fraction::Fraction(const Fraction& other)
{
    first = other.first;
    second = other.second;
}

unsigned int Fraction::GetFirst() const
{
    return first;
}

unsigned int Fraction::GetSecond() const
{
    return second;
}

void Fraction::SetFirst(unsigned int value)
{
    first = value;
}

void Fraction::SetSecond(unsigned int value)
{
    if (value == 0)
        value = 1;

    second = value;
}

void Fraction::Init(unsigned int f, unsigned int s)
{
    SetFirst(f);
    SetSecond(s);
}

int Fraction::ipart() const
{
    return first / second;
}

Fraction& Fraction::operator=(const Fraction& other)
{
    if (this != &other)
    {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Fraction::operator string() const
{
    stringstream sout;
    sout << first << "/" << second;
    return sout.str();
}

ostream& operator<<(ostream& out, const Fraction& f)
{
    out << string(f);
    return out;
}

istream& operator>>(istream& in, Fraction& f)
{
    unsigned int a, b;

    cout << "first = ";
    in >> a;

    cout << "second = ";
    in >> b;

    f.Init(a, b);
    return in;
}

Fraction& Fraction::operator++()
{
    first++;
    return *this;
}

Fraction& Fraction::operator--()
{
    first--;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    second++;
    return temp;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    second--;
    if (second == 0)
        second = 1;
    return temp;
}

Fraction makeFraction(unsigned int first, unsigned int second)
{
    Fraction f;
    f.Init(first, second);
    return f;
}