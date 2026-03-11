#include "Solution.h"
#include <iostream>

using namespace std;

int main()
{
    Solution s;

    s.Read();
    s.Display();

    cout << endl;
    cout << "toString():" << endl;
    cout << s.toString() << endl;

    return 0;
}