#include "VectorN.h"
#include <cmath>

// Виклик базових конструкторів
VectorN::VectorN() : Array() {}
VectorN::VectorN(int n) : Array(n) {}
VectorN::VectorN(int n, const double* arr) : Array(n, arr) {}
VectorN::VectorN(const VectorN& other) : Array(other) {}

VectorN& VectorN::operator=(const VectorN& other)
{
    Array::operator=(other); // Виклик базового оператора присвоєння
    return *this;
}

double VectorN::Length() const
{
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        sum += a[i] * a[i];
    }
    return std::sqrt(sum);
}

VectorN VectorN::operator*(double scalar) const
{
    VectorN res(N, a);
    for (int i = 0; i < res.N; ++i) {
        res.a[i] *= scalar;
    }
    return res;
}

// Про-рівень: порівняння double через epsilon, щоб уникнути похибок заокруглення
bool VectorN::operator==(const VectorN& other) const
{
    if (N != other.N) return false;
    for (int i = 0; i < N; ++i) {
        if (std::abs(a[i] - other.a[i]) > 1e-9) return false;
    }
    return true;
}

bool VectorN::operator!=(const VectorN& other) const
{
    return !(*this == other);
}

bool VectorN::operator>(const VectorN& other) const
{
    return this->Length() > other.Length();
}

bool VectorN::operator<(const VectorN& other) const
{
    return this->Length() < other.Length();
}

bool VectorN::operator>=(const VectorN& other) const
{
    return this->Length() >= other.Length();
}

bool VectorN::operator<=(const VectorN& other) const
{
    return this->Length() <= other.Length();
}

VectorN::~VectorN() {}