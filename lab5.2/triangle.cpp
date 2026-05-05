#include "triangle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

bool IsValidTriangle(double a, double b, double c) {
    return (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a));
}

Error::Error(string msg, double a, double b, double c) : message(msg), a(a), b(b), c(c) {}

string Error::What() {
    return message + "\nВведені сторони: a=" + to_string(a) + ", b=" + to_string(b) + ", c=" + to_string(c);
}

E::E(string msg, double a, double b, double c) : message(msg), a(a), b(b), c(c) {
    full_message = message + " [" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + "]";
}

E::~E() throw() {}

const char* E::what() const throw() { 
    return full_message.c_str(); 
}

double Perimeter1(double a, double b, double c) {
    if (!IsValidTriangle(a, b, c)) throw 1;
    return a + b + c;
}

double Perimeter2(double a, double b, double c) throw() {
    if (!IsValidTriangle(a, b, c)) throw 1.0;
    return a + b + c;
}

double Perimeter3(double a, double b, double c) throw(char) {
    if (!IsValidTriangle(a, b, c)) throw '1';
    return a + b + c;
}

double Perimeter4(double a, double b, double c) throw(Empty) {
    if (!IsValidTriangle(a, b, c)) throw Empty();
    return a + b + c;
}

double Perimeter5(double a, double b, double c) throw(Error) {
    if (!IsValidTriangle(a, b, c)) throw Error("Помилка: Трикутник з такими сторонами не може існувати!", a, b, c);
    return a + b + c;
}

double Perimeter6(double a, double b, double c) throw(E) {
    if (!IsValidTriangle(a, b, c)) throw E("Критична помилка геометрії", a, b, c);
    return a + b + c;
}

void FU() {
    cout << "unexpected error! - викликано unexpected()" << endl;
    throw; 
}

void FT() {
    cout << "unknown error! - викликано terminate(). Роботу завершено." << endl;
    abort();
}