#include "Bankomat.h"
#include <iostream>
using namespace std;

void Bankomat::setId(int value)
{
    id = value;
}

bool Bankomat::setMinSum(int value)
{
    if (value > 0)
    {
        minSum = value;
        return true;
    }
    else
    {
        minSum = 0;
        return false;
    }
}

bool Bankomat::setMaxSum(int value)
{
    if (value > minSum)
    {
        maxSum = value;
        return true;
    }
    else
    {
        maxSum = 0;
        return false;
    }
}

bool Bankomat::setN500(int value)
{
    if (value >= 0)
    {
        n500 = value;
        return true;
    }
    else
    {
        n500 = 0;
        return false;
    }
}

bool Bankomat::setN200(int value)
{
    if (value >= 0)
    {
        n200 = value;
        return true;
    }
    else
    {
        n200 = 0;
        return false;
    }
}

bool Bankomat::setN100(int value)
{
    if (value >= 0)
    {
        n100 = value;
        return true;
    }
    else
    {
        n100 = 0;
        return false;
    }
}

bool Bankomat::setN50(int value)
{
    if (value >= 0)
    {
        n50 = value;
        return true;
    }
    else
    {
        n50 = 0;
        return false;
    }
}

bool Bankomat::setN20(int value)
{
    if (value >= 0)
    {
        n20 = value;
        return true;
    }
    else
    {
        n20 = 0;
        return false;
    }
}

bool Bankomat::setN10(int value)
{
    if (value >= 0)
    {
        n10 = value;
        return true;
    }
    else
    {
        n10 = 0;
        return false;
    }
}

bool Bankomat::Init(int id, int minSum, int maxSum,
                    int n500, int n200, int n100, int n50, int n20, int n10)
{
    setId(id);
    return setMinSum(minSum) &&
           setMaxSum(maxSum) &&
           setN500(n500) &&
           setN200(n200) &&
           setN100(n100) &&
           setN50(n50) &&
           setN20(n20) &&
           setN10(n10);
}

void Bankomat::Read()
{
    int id, minSum, maxSum;
    int n500, n200, n100, n50, n20, n10;

    do
    {
        cout << "id = "; cin >> id;
        cout << "minSum = "; cin >> minSum;
        cout << "maxSum = "; cin >> maxSum;

        cout << "n500 = "; cin >> n500;
        cout << "n200 = "; cin >> n200;
        cout << "n100 = "; cin >> n100;
        cout << "n50 = "; cin >> n50;
        cout << "n20 = "; cin >> n20;
        cout << "n10 = "; cin >> n10;
    }
    while (!Init(id, minSum, maxSum, n500, n200, n100, n50, n20, n10));
}

void Bankomat::Display() const
{
    cout << "id = " << id << endl;
    cout << "minSum = " << minSum << endl;
    cout << "maxSum = " << maxSum << endl;

    cout << "n500 = " << n500 << endl;
    cout << "n200 = " << n200 << endl;
    cout << "n100 = " << n100 << endl;
    cout << "n50 = " << n50 << endl;
    cout << "n20 = " << n20 << endl;
    cout << "n10 = " << n10 << endl;
}

int Bankomat::getMoneySum() const
{
    return n500 * 500 +
           n200 * 200 +
           n100 * 100 +
           n50 * 50 +
           n20 * 20 +
           n10 * 10;
}

void Bankomat::Load(int add500, int add200, int add100, int add50, int add20, int add10)
{
    n500 += add500;
    n200 += add200;
    n100 += add100;
    n50 += add50;
    n20 += add20;
    n10 += add10;
}

bool Bankomat::Withdraw(int sum)
{
    if (sum < minSum || sum > maxSum)
        return false;

    if (sum > getMoneySum())
        return false;

    int t500 = n500;
    int t200 = n200;
    int t100 = n100;
    int t50 = n50;
    int t20 = n20;
    int t10 = n10;

    while (sum >= 500 && t500 > 0)
    {
        sum -= 500;
        t500--;
    }
    while (sum >= 200 && t200 > 0)
    {
        sum -= 200;
        t200--;
    }
    while (sum >= 100 && t100 > 0)
    {
        sum -= 100;
        t100--;
    }
    while (sum >= 50 && t50 > 0)
    {
        sum -= 50;
        t50--;
    }
    while (sum >= 20 && t20 > 0)
    {
        sum -= 20;
        t20--;
    }
    while (sum >= 10 && t10 > 0)
    {
        sum -= 10;
        t10--;
    }

    if (sum != 0)
        return false;

    n500 = t500;
    n200 = t200;
    n100 = t100;
    n50 = t50;
    n20 = t20;
    n10 = t10;

    return true;
}

string Bankomat::toString() const
{
    return "sum = " + to_string(getMoneySum());
}

Bankomat makeBankomat(int id, int minSum, int maxSum,
                      int n500, int n200, int n100, int n50, int n20, int n10)
{
    Bankomat b;
    if (!b.Init(id, minSum, maxSum, n500, n200, n100, n50, n20, n10))
    {
        cout << "wrong argument to Init!" << endl;
        exit(1);
    }
    return b;
}