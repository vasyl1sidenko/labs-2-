#include <iostream>
#include "Fraction.h"

using namespace std;

#pragma pack(push, 1)
class FractionPacked
{
private:
    unsigned int first;
    unsigned int second;
};
#pragma pack(pop)

int main()
{
    Fraction a;              // конструктор без аргументів
    Fraction b(7, 3);        // конструктор ініціалізації
    Fraction c = b;          // конструктор копіювання
    Fraction d;

    Fraction arr[3];         // масив об'єктів

    a = makeFraction(10, 4); // зовнішня функція + оператор присвоєння

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "Integer part of b = " << b.ipart() << endl;

    cout << endl << "Input d:" << endl;
    cin >> d;
    cout << "d = " << d << endl;

    cout << endl << "Prefix increment ++b: " << ++b << endl;
    cout << "After ++b: " << b << endl;

    cout << endl << "Postfix increment b++: " << b++ << endl;
    cout << "After b++: " << b << endl;

    cout << endl << "Prefix decrement --b: " << --b << endl;
    cout << "After --b: " << b << endl;

    cout << endl << "Postfix decrement b--: " << b-- << endl;
    cout << "After b--: " << b << endl;

    arr[0] = Fraction(1, 2);
    arr[1] = Fraction(3, 4);
    arr[2] = Fraction(5, 6);

    cout << endl << "Array of objects:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    cout << endl << "Size of Fraction = " << sizeof(Fraction) << endl;
    cout << "Size of FractionPacked (#pragma pack(1)) = " << sizeof(FractionPacked) << endl;

    return 0;
}