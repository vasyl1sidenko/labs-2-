#pragma once
#include <string>
#include <exception>

using namespace std;

bool IsValidTriangle(double a, double b, double c);

class Empty {};

class Error {
    string message;
    double a, b, c;
public:
    Error(string msg, double a, double b, double c);
    string What();
};

class E : public exception {
    string message;
    double a, b, c;
    string full_message;
public:
    E(string msg, double a, double b, double c);
    ~E() throw();
    const char* what() const throw();
};

double Perimeter1(double a, double b, double c);
double Perimeter2(double a, double b, double c) throw();
double Perimeter3(double a, double b, double c) throw(char);
double Perimeter4(double a, double b, double c) throw(Empty);
double Perimeter5(double a, double b, double c) throw(Error);
double Perimeter6(double a, double b, double c) throw(E);

void FU();
void FT();