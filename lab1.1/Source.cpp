#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction makeFraction(int a, int b)
{
    Fraction f;
    if (!f.Init(a, b))
        cout << "Wrong arguments to Init!" << endl;
    return f;
}

int main()
{
    Fraction f1;
    f1.Read();
    f1.Display();
    cout << "Integer part = " << f1.ipart() << endl;

    cout << endl;

    Fraction f2;
    f2 = makeFraction(7, 3);
    f2.Display();
    cout << "Integer part = " << f2.ipart() << endl;

    return 0;
}
