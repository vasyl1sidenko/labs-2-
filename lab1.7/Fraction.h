#pragma once
#include <string>

class Fraction
{
private:
    long whole;
    unsigned short part;

public:
    Fraction();
    Fraction(long wholeValue, unsigned short partValue);

    long GetWhole() const;
    unsigned short GetPart() const;

    void SetWhole(long value);
    bool SetPart(unsigned short value);

    bool Init(long wholeValue, unsigned short partValue);
    void Read();
    void Display() const;
    std::string toString() const;

    double ToDouble() const;
};