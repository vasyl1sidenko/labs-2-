#pragma once
#include <iostream>
#include <string>

using namespace std;

class Fraction
{
private:
    unsigned int first;
    unsigned int second;

public:
    Fraction();
    Fraction(unsigned int f, unsigned int s);
    Fraction(const Fraction& other);

    unsigned int GetFirst() const;
    unsigned int GetSecond() const;

    void SetFirst(unsigned int value);
    void SetSecond(unsigned int value);

    void Init(unsigned int f, unsigned int s);
    int ipart() const;

    Fraction& operator=(const Fraction& other);
    operator string() const;

    Fraction& operator++();      // префіксний ++
    Fraction& operator--();      // префіксний --
    Fraction operator++(int);    // постфіксний ++
    Fraction operator--(int);    // постфіксний --

    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);
};

Fraction makeFraction(unsigned int first, unsigned int second);