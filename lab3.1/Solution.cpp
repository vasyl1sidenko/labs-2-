#include "Solution.h"
#include <sstream>

Solution::Solution(string n, double d, double c) : Liquid(n, d)
{
    setConcentration(c);
}

Solution::Solution(const Solution& s) : Liquid(s)
{
    concentration = s.concentration;
}

double Solution::getConcentration() const
{
    return concentration;
}

void Solution::setConcentration(double c)
{
    if (c < 0 || c > 1)
    {
        cout << "Error: concentration must be [0..1]!" << endl;
        exit(1);
    }
    concentration = c;
}

void Solution::changeConcentration(double c)
{
    setConcentration(c);
}

Solution::operator string() const
{
    stringstream ss;
    ss << "Solution: " << name
       << ", density = " << density
       << ", concentration = " << concentration;
    return ss.str();
}

ostream& operator<<(ostream& out, const Solution& s)
{
    return out << (string)s;
}

istream& operator>>(istream& in, Solution& s)
{
    string n;
    double d, c;

    cout << "Name: ";
    in >> n;

    cout << "Density: ";
    in >> d;

    cout << "Concentration (0..1): ";
    in >> c;

    s.setName(n);
    s.setDensity(d);
    s.setConcentration(c);

    return in;
}