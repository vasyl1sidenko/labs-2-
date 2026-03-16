#pragma once
#include "Fraction.h"
#include <string>

class Calculator
{
private:
    Fraction first;
    Fraction second;

public:
    Calculator();
    Calculator(Fraction firstValue, Fraction secondValue);

    Fraction GetFirst() const;
    Fraction GetSecond() const;

    void SetFirst(Fraction value);
    void SetSecond(Fraction value);

    bool Init(Fraction firstValue, Fraction secondValue);
    void Read();
    void Display() const;
    std::string toString() const;

    double Add() const;
    double Sub() const;
    double Mul() const;

    bool IsEqual() const;
    bool IsGreater() const;
    bool IsLess() const;
};