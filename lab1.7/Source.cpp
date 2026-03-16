#include <iostream>
#include "Fraction.h"
#include "Calculator.h"

using namespace std;

int main()
{
    Fraction a;
    a.Init(12, 34);

    Fraction b(5, 6);

    cout << "a = ";
    a.Display();
    cout << endl;

    cout << "b = ";
    b.Display();
    cout << endl;

    Calculator c1;
    c1.Init(a, b);

    cout << endl;
    cout << "Calculator c1:" << endl;
    c1.Display();

    cout << "Add = " << c1.Add() << endl;
    cout << "Sub = " << c1.Sub() << endl;
    cout << "Mul = " << c1.Mul() << endl;

    cout << "Equal = " << (c1.IsEqual() ? "true" : "false") << endl;
    cout << "Greater = " << (c1.IsGreater() ? "true" : "false") << endl;
    cout << "Less = " << (c1.IsLess() ? "true" : "false") << endl;

    cout << endl;
    cout << "toString a = " << a.toString() << endl;
    cout << "toString c1 = " << c1.toString() << endl;

    cout << endl;
    cout << "Array of Fraction objects:" << endl;

    Fraction arr[2];
    arr[0].Init(1, 25);
    arr[1].Init(2, 50);

    for (int i = 0; i < 2; i++)
    {
        cout << "arr[" << i << "] = ";
        arr[i].Display();
        cout << endl;
    }

    cout << endl;
    cout << "Array of Calculator objects:" << endl;

    Calculator calcArr[2];
    calcArr[0].Init(Fraction(2, 50), Fraction(1, 25));
    calcArr[1].Init(Fraction(7, 10), Fraction(4, 5));

    for (int i = 0; i < 2; i++)
    {
        cout << "calcArr[" << i << "]:" << endl;
        calcArr[i].Display();
        cout << "Add = " << calcArr[i].Add() << endl;
    }

    cout << endl;
    cout << "Input from keyboard:" << endl;

    Calculator userCalc;
    userCalc.Read();

    cout << "You entered:" << endl;
    userCalc.Display();

    cout << "Add = " << userCalc.Add() << endl;
    cout << "Sub = " << userCalc.Sub() << endl;
    cout << "Mul = " << userCalc.Mul() << endl;

    return 0;
}