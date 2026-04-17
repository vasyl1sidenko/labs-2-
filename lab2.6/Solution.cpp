#include "Solution.h"
#include <sstream>

int Solution::counter = 0;
int Solution::Liquid::counter = 0;

void Solution::Liquid::setName(string name) {
    if (name.empty()) {
        this->name = "Unknown";
    } else {
        this->name = name;
    }
}

void Solution::Liquid::setDensity(double density) {
    if (density <= 0) {
        cout << "[Помилка] Густина має бути > 0. Встановлено 1000.0\n";
        this->density = 1000.0;
    } else {
        this->density = density;
    }
}

void Solution::Liquid::Init(string name, double density) {
    setName(name);
    setDensity(density);
}

void Solution::Liquid::Display() const {
    cout << string(*this) << endl;
}

void Solution::Liquid::Read() {
    string n;
    double d;
    cout << "Назва рідини: "; cin >> n;
    cout << "Густина рідини: "; cin >> d;
    Init(n, d);
}

Solution::Liquid::Liquid() { Init("Unknown", 1000.0); Solution::Liquid::counter++; }
Solution::Liquid::Liquid(const string name) { Init(name, 1000.0); Solution::Liquid::counter++; }
Solution::Liquid::Liquid(const double density) { Init("Unknown", density); Solution::Liquid::counter++; }
Solution::Liquid::Liquid(const string name, const double density) { Init(name, density); Solution::Liquid::counter++; }

Solution::Liquid::Liquid(const Liquid& l) {
    Init(l.name, l.density);
    Solution::Liquid::counter++;
}

Solution::Liquid::~Liquid() { Solution::Liquid::counter--; }

Solution::Liquid& Solution::Liquid::operator=(const Liquid& l) {
    if (this != &l) {
        Init(l.name, l.density);
    }
    return *this;
}

Solution::Liquid::operator string() const {
    stringstream ss;
    ss << "[Liquid: " << name << ", Density: " << density << "]";
    return ss.str();
}

Solution::Liquid& Solution::Liquid::operator++() {
    ++density;
    return *this;
}
Solution::Liquid& Solution::Liquid::operator--() {
    --density;
    if (density <= 0) density = 0.1;
    return *this;
}

Solution::Liquid Solution::Liquid::operator++(int) {
    Liquid temp(*this);
    density++;
    return temp;
}
Solution::Liquid Solution::Liquid::operator--(int) {
    Liquid temp(*this);
    density--;
    if (density <= 0) density = 0.1;
    return temp;
}

ostream& operator<<(ostream& out, const Solution::Liquid& l) {
    out << string(l);
    return out;
}

istream& operator>>(istream& in, Solution::Liquid& l) {
    l.Read();
    return in;
}

int Solution::Liquid::getCounter() { return Solution::Liquid::counter; }


void Solution::setConcentration(double concentration) {
    if (concentration < 0 || concentration > 1) {
        cout << "[Помилка] Концентрація від 0 до 1. Встановлено 0\n";
        this->concentration = 0;
    } else {
        this->concentration = concentration;
    }
}

void Solution::setLiquid(Liquid liquid) {
    this->liquid = liquid;
}

void Solution::Init(double concentration, Liquid liquid) {
    setConcentration(concentration);
    setLiquid(liquid);
}

void Solution::Display() const {
    cout << string(*this) << endl;
}

void Solution::Read() {
    double c;
    Liquid l;
    l.Read();
    cout << "Концентрація (0.0 - 1.0): "; cin >> c;
    Init(c, l);
}

Solution::Solution(const double concentration, const string name, const double density) {
    Liquid l(name, density);
    Init(concentration, l);
    Solution::counter++;
}

Solution::Solution(const Solution& s) {
    Init(s.concentration, s.liquid);
    Solution::counter++;
}

Solution::~Solution() { Solution::counter--; }

Solution& Solution::operator=(const Solution& s) {
    if (this != &s) {
        Init(s.concentration, s.liquid);
    }
    return *this;
}

Solution::operator string() const {
    stringstream ss;
    ss << string(liquid) << ", Concentration: " << concentration;
    return ss.str();
}

Solution& Solution::operator++() {
    concentration += 0.1;
    if (concentration > 1.0) concentration = 1.0;
    return *this;
}
Solution& Solution::operator--() {
    concentration -= 0.1;
    if (concentration < 0.0) concentration = 0.0;
    return *this;
}

Solution Solution::operator++(int) {
    Solution temp(*this);
    operator++();
    return temp;
}
Solution Solution::operator--(int) {
    Solution temp(*this);
    operator--(); 
    return temp;
}

ostream& operator<<(ostream& out, const Solution& s) {
    out << string(s);
    return out;
}

istream& operator>>(istream& in, Solution& s) {
    s.Read();
    return in;
}

int Solution::getCounter() { return Solution::counter; }