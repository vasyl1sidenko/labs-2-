#include "Liquid.h"
#include <sstream>

Liquid::Liquid(string n, double d)
{
    setName(n);
    setDensity(d);
}

Liquid::Liquid(const Liquid& l)
{
    name = l.name;
    density = l.density;
}

string Liquid::getName() const { return name; }
double Liquid::getDensity() const { return density; }

void Liquid::setName(string n)
{
    if (n.empty())
    {
        cout << "Error: empty name!" << endl;
        exit(1);
    }
    name = n;
}

void Liquid::setDensity(double d)
{
    if (d <= 0)
    {
        cout << "Error: density must be > 0!" << endl;
        exit(1);
    }
    density = d;
}

void Liquid::changeDensity(double d)
{
    setDensity(d);
}

Liquid::operator string() const
{
    stringstream ss;
    ss << "Liquid: " << name << ", density = " << density;
    return ss.str();
}

ostream& operator<<(ostream& out, const Liquid& l)
{
    return out << (string)l;
}

istream& operator>>(istream& in, Liquid& l)
{
    string n;
    double d;

    cout << "Name: ";
    in >> n;

    cout << "Density: ";
    in >> d;

    l.setName(n);
    l.setDensity(d);

    return in;
}