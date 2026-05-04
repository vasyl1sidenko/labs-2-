
#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

//базовий
class ZeroErr {
public:
    std::string msg;
    ZeroErr(std::string m) : msg(m) {}
};

//нащадок
class NegErr : public std::logic_error {
public:
    NegErr(std::string m) : std::logic_error(m) {}
};

class Fraction {
private:
    int first; 
    int second; 

public:
    Fraction();
    Fraction(int f, int s) throw(NegErr, ZeroErr*);
    Fraction(const Fraction& other);

    void Init(int f, int s) throw(NegErr, ZeroErr*);
    void Read() throw(std::invalid_argument, NegErr, ZeroErr*);
    void Display() const;
    
    int ipart() const throw(ZeroErr*);

    Fraction& operator=(const Fraction& other);
    operator std::string() const;

    Fraction& operator++();   
    Fraction operator++(int);  
    Fraction& operator--() throw(NegErr);  
    Fraction operator--(int) throw(NegErr); 

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f) throw(std::invalid_argument);
};

Fraction makeFraction(int f, int s) throw(std::bad_exception, NegErr, ZeroErr*);