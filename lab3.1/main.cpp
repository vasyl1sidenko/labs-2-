#include "Solution.h"

Liquid makeLiquid(Liquid l)
{
    return l; // підстановка
}

int main()
{
    Liquid l1("Water", 1000);
    Solution s1("SaltWater", 1020, 0.1);

    cin >> l1;
    cin >> s1;

    cout << l1 << endl;
    cout << s1 << endl;

    Liquid result = makeLiquid(s1);
    cout << result << endl;

    return 0;
}