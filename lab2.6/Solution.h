#pragma once
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    double concentration;
    static int counter;

public:
    class Liquid {
    private:
        string name;
        double density;
        static int counter;

    public:
        string getName() const { return name; }
        double getDensity() const { return density; }

        void setName(string name);
        void setDensity(double density);

        void Init(string name, double density);
        void Display() const;
        void Read();

        Liquid();
        Liquid(const string name);
        Liquid(const double density);
        Liquid(const string name, const double density);
        Liquid(const Liquid& l);
        ~Liquid();

        Liquid& operator=(const Liquid& l);
        operator string() const;
        
        Liquid& operator++();
        Liquid& operator--();
        Liquid operator++(int);
        Liquid operator--(int);

        friend ostream& operator<<(ostream& out, const Liquid& l);
        friend istream& operator>>(istream& in, Liquid& l);

        static int getCounter();
    };

private:
    Liquid liquid;

public:
    double getConcentration() const { return concentration; }
    Liquid getLiquid() const { return liquid; }

    void setConcentration(double concentration);
    void setLiquid(Liquid liquid);

    void Init(double concentration, Liquid liquid);
    void Display() const;
    void Read();

    Solution(const double concentration = 0.0, const string name = "Water", const double density = 1000.0);
    Solution(const Solution& s);
    ~Solution();

    Solution& operator=(const Solution& s);
    operator string() const;

    Solution& operator++();
    Solution& operator--();
    Solution operator++(int);
    Solution operator--(int);

    friend ostream& operator<<(ostream& out, const Solution& s);
    friend istream& operator>>(istream& in, Solution& s);

    static int getCounter();
};

#pragma pack(push, 1)
struct PackedSolution {
    double concentration;
    struct PackedLiquid {
        string name;
        double density;
    } liquid;
};
#pragma pack(pop)