#pragma once
#include "Array.h"

class VectorN : public Array
{
public:
    VectorN();
    VectorN(int n);
    VectorN(int n, const double* arr);
    VectorN(const VectorN& other);

    VectorN& operator=(const VectorN& other);

    // Специфічні методи вектора
    double Length() const;
    VectorN operator*(double scalar) const;

    // Шість операторів порівняння
    // Порівняння самих векторів (за координатами)
    bool operator==(const VectorN& other) const;
    bool operator!=(const VectorN& other) const;

    // Порівняння довжин векторів
    bool operator>(const VectorN& other) const;
    bool operator<(const VectorN& other) const;
    bool operator>=(const VectorN& other) const;
    bool operator<=(const VectorN& other) const;

    ~VectorN();
};