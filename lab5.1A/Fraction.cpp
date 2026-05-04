#include "Fraction.h"

Fraction::Fraction() : first(1), second(1) {}

Fraction::Fraction(int f, int s) throw(NegErr, ZeroErr*) {
    Init(f, s);
}

Fraction::Fraction(const Fraction& other) : first(other.first), second(other.second) {}

void Fraction::Init(int f, int s) throw(NegErr, ZeroErr*) {
    if (f < 0 || s < 0) throw NegErr("Values must be positive!");
    if (s == 0) throw new ZeroErr("Denominator cannot be zero!");
    first = f;
    second = s;
}

void Fraction::Read() throw(std::invalid_argument, NegErr, ZeroErr*) {
    int f, s;
    std::cout << "Enter numerator and denominator: ";
    if (!(std::cin >> f >> s)) throw std::invalid_argument("Input error!");
    Init(f, s);
}

void Fraction::Display() const {
    std::cout << first << "/" << second << "\n";
}

int Fraction::ipart() const throw(ZeroErr*) {
    if (second == 0) throw new ZeroErr("Div by zero in ipart!");
    return first / second;
}

Fraction& Fraction::operator=(const Fraction& other) {
    first = other.first;
    second = other.second;
    return *this;
}

// Спрощене зведення до рядка
Fraction::operator std::string() const {
    return std::to_string(first) + "/" + std::to_string(second);
}

Fraction& Fraction::operator++() {
    ++first;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    first++;
    return temp;
}

Fraction& Fraction::operator--() throw(NegErr) {
    if (second <= 1) throw NegErr("Denominator becomes <= 0!");
    --second;
    return *this;
}

Fraction Fraction::operator--(int) throw(NegErr) {
    Fraction temp = *this;
    if (second <= 1) throw NegErr("Denominator becomes <= 0!");
    second--;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    return os << f.first << "/" << f.second;
}

std::istream& operator>>(std::istream& is, Fraction& f) throw(std::invalid_argument) {
    int f_val, s_val;
    is >> f_val >> s_val;
    if (is.fail()) throw std::invalid_argument("Stream error!");
    f.Init(f_val, s_val);
    return is;
}

Fraction makeFraction(int f, int s) throw(std::bad_exception, NegErr, ZeroErr*) {
    if (f == 999) throw std::bad_exception(); 
    Fraction frac;
    frac.Init(f, s);
    return frac;
}