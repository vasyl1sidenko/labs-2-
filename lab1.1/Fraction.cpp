#include "Fraction.h"
#include <iostream>

using namespace std;

bool Fraction::SetFirst(int value)
{
    if (value > 0)
    {
        first = value;
        return true;
    }
    first = 1;
    return false;
}

bool Fraction::SetSecond(int value)
{
    if (value > 0)            // тут і є перевірка "знаменник не нуль"
    {
        second = value;
        return true;
    }
    second = 1;
    return false;
}

bool Fraction::Init(int a, int b)
{
    return SetFirst(a) && SetSecond(b);
}

void Fraction::Display() const
{
    cout << "Fraction = " << first << "/" << second << endl;
}

void Fraction::Read()
{
    int a, b;
    do
    {
        cout << "Numerator = ";
        cin >> a;
        cout << "Denominator = ";
        cin >> b;
    } while (!Init(a, b));
}

unsigned int Fraction::ipart() const
{
    if (second == 0) // на всякий випадок (але через SetSecond це не проскочить)
    {
        cout << "Error: denominator is zero!" << endl;
        return 0;
    }
    return first / second;
}
