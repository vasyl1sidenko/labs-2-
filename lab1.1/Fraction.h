#pragma once

class Fraction
{
private:
    unsigned int first;   // numerator
    unsigned int second;  // denominator

public:
    unsigned int GetFirst() const { return first; }
    unsigned int GetSecond() const { return second; }

    bool SetFirst(int value);
    bool SetSecond(int value);

    bool Init(int a, int b);

    void Display() const;
    void Read();

    unsigned int ipart() const; // integer part of first/second
};