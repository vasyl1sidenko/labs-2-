#include "Calculator.h"
#include <iostream>
#include <sstream>

using namespace std;

Calculator::Calculator()
{
    first.Init(0, 0);
    second.Init(0, 0);
}

Calculator::Calculator(Fraction firstValue, Fraction secondValue)
{
    Init(firstValue, secondValue);
}

Fraction Calculator::GetFirst() const
{
    return first;
}

Fraction Calculator::GetSecond() const
{
    return second;
}

void Calculator::SetFirst(Fraction value)
{
    first.Init(value.GetWhole(), value.GetPart());
}

void Calculator::SetSecond(Fraction value)
{
    second.Init(value.GetWhole(), value.GetPart());
}

bool Calculator::Init(Fraction firstValue, Fraction secondValue)
{
    SetFirst(firstValue);
    SetSecond(secondValue);
    return true;
}

void Calculator::Read()
{
    cout << "Enter first fraction:" << endl;
    first.Read();

    cout << "Enter second fraction:" << endl;
    second.Read();
}

void Calculator::Display() const
{
    cout << "First = ";
    first.Display();
    cout << endl;

    cout << "Second = ";
    second.Display();
    cout << endl;
}

string Calculator::toString() const
{
    stringstream sout;
    sout << "First = " << first.toString()
         << ", Second = " << second.toString();
    return sout.str();
}

double Calculator::Add() const
{
    return first.ToDouble() + second.ToDouble();
}

double Calculator::Sub() const
{
    return first.ToDouble() - second.ToDouble();
}

double Calculator::Mul() const
{
    return first.ToDouble() * second.ToDouble();
}

bool Calculator::IsEqual() const
{
    return first.ToDouble() == second.ToDouble();
}

bool Calculator::IsGreater() const
{
    return first.ToDouble() > second.ToDouble();
}

bool Calculator::IsLess() const
{
    return first.ToDouble() < second.ToDouble();
}