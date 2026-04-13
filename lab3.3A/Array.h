#pragma once
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class Array : public Object
{
protected: // protected, щоб VectorN мав прямий доступ до полів
    int N;
    double* a;

public:
    int getN() const { return N; }
    void Init(int n, const double* arr);
    void Display() const;
    void Read();

    Array();
    Array(int n);
    Array(int n, const double* arr);
    Array(const Array& other);
    
    Array& operator=(const Array& other);
    
    friend ostream& operator<<(ostream& out, const Array& arr);
    friend istream& operator>>(istream& in, Array& arr);
    operator string() const;

    // Перевантаження інкременту та декременту для числових полів
    Array& operator++();    // префіксний
    Array& operator--();    // префіксний
    Array operator++(int);  // постфіксний
    Array operator--(int);  // постфіксний

    ~Array();
};