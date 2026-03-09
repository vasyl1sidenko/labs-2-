#include <iostream>
#include "Bankomat.h"
using namespace std;

int main()
{
    Bankomat b;

    b.Read();
    b.Display();

    cout << b.toString() << endl;

    b.Load(1, 1, 1, 1, 1, 1);
    cout << "After loading:" << endl;
    b.Display();

    int sum;
    cout << "sum = ";
    cin >> sum;

    if (b.Withdraw(sum))
        cout << "money was withdrawn" << endl;
    else
        cout << "cannot withdraw money" << endl;

    b.Display();
    cout << b.toString() << endl;

    return 0;
}