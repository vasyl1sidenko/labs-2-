#include "Array.h"
#include <sstream>

void Array::Init(int n, const double* arr)
{
    if (this->a != nullptr) {
        delete[] this->a;
    }
    this->N = n;
    this->a = new double[N];
    for (int i = 0; i < N; ++i) {
        this->a[i] = (arr != nullptr) ? arr[i] : 0.0;
    }
}

void Array::Display() const
{
    cout << string(*this) << endl;
}

void Array::Read()
{
    cout << "Введіть розмірність масиву (N): ";
    int n;
    cin >> n;
    double* temp = new double[n];
    cout << "Введіть " << n << " дійсних чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
    }
    Init(n, temp);
    delete[] temp;
}

Array::Array() : N(0), a(nullptr) {}

Array::Array(int n) : N(n)
{
    a = new double[N]{0.0};
}

Array::Array(int n, const double* arr) : N(0), a(nullptr)
{
    Init(n, arr);
}

Array::Array(const Array& other) : N(0), a(nullptr)
{
    Init(other.N, other.a);
}

Array& Array::operator=(const Array& other)
{
    if (this != &other) {
        Init(other.N, other.a);
    }
    return *this;
}

ostream& operator<<(ostream& out, const Array& arr)
{
    out << string(arr);
    return out;
}

istream& operator>>(istream& in, Array& arr)
{
    int n;
    cout << "N = ? ";
    in >> n;
    double* temp = new double[n];
    cout << "Елементи = ? ";
    for (int i = 0; i < n; ++i) {
        in >> temp[i];
    }
    arr.Init(n, temp);
    delete[] temp;
    return in;
}

Array::operator string() const
{
    stringstream ss;
    ss << "[ ";
    for (int i = 0; i < N; ++i) {
        ss << a[i] << (i < N - 1 ? ", " : "");
    }
    ss << " ]";
    return ss.str();
}

Array& Array::operator++()
{
    for (int i = 0; i < N; ++i) a[i] += 1.0;
    return *this;
}

Array& Array::operator--()
{
    for (int i = 0; i < N; ++i) a[i] -= 1.0;
    return *this;
}

Array Array::operator++(int)
{
    Array temp(*this);
    ++(*this);
    return temp;
}

Array Array::operator--(int)
{
    Array temp(*this);
    --(*this);
    return temp;
}

Array::~Array()
{
    delete[] a;
}