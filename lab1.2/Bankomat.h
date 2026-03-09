#pragma once
#include <string>
using namespace std;

class Bankomat
{
private:
    int id;
    int minSum;
    int maxSum;

    int n500;
    int n200;
    int n100;
    int n50;
    int n20;
    int n10;

public:
    int getId() const { return id; }
    int getMinSum() const { return minSum; }
    int getMaxSum() const { return maxSum; }

    int getN500() const { return n500; }
    int getN200() const { return n200; }
    int getN100() const { return n100; }
    int getN50() const { return n50; }
    int getN20() const { return n20; }
    int getN10() const { return n10; }

    void setId(int);
    bool setMinSum(int);
    bool setMaxSum(int);

    bool setN500(int);
    bool setN200(int);
    bool setN100(int);
    bool setN50(int);
    bool setN20(int);
    bool setN10(int);

    bool Init(int id, int minSum, int maxSum,
              int n500, int n200, int n100, int n50, int n20, int n10);

    void Read();
    void Display() const;

    void Load(int add500, int add200, int add100, int add50, int add20, int add10);
    bool Withdraw(int sum);
    string toString() const;
    int getMoneySum() const;
};

Bankomat makeBankomat(int id, int minSum, int maxSum,
                      int n500, int n200, int n100, int n50, int n20, int n10);
                      