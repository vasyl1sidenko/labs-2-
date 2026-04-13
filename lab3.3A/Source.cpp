#include <iostream>
#include "VectorN.h"

using namespace std;

class DummyVector {
    int N;
    double* a;
};

#pragma pack(push, 1)
class PackedDummyVector {
    int N;
    double* a;
};
#pragma pack(pop)

int main()
{
    // 1. Різні способи створення об'єктів
    double arr1[] = { 3.0, 4.0 };
    VectorN v1(2, arr1);        // З параметрами
    VectorN v2(v1);             // Копіювання
    VectorN v3;                 // За замовчуванням

    // 2. Використання методів та перевантажених операторів
    v3 = v1 * 2.5;              // Множення на скаляр та присвоєння
    
    cout << "v1: " << v1 << " | Len: " << v1.Length() << endl;
    cout << "v3: " << v3 << " | Len: " << v3.Length() << endl;

    // Операції порівняння (виведе 1 - true, 0 - false)
    cout << "v1 == v2: " << (v1 == v2) << endl;
    cout << "v3 > v1: "  << (v3 > v1) << endl;

    // Інкремент / декремент
    v1++;
    --v3;

    // 3. Робота з масивом об'єктів
    VectorN* vectors = new VectorN[2];
    double arr2[] = { 1.0, 1.0, 1.0 };
    vectors[0].Init(3, arr2);
    
    delete[] vectors;

    // 4. Демонстрація розміру та лічильника
    cout << "Size normal: " << sizeof(DummyVector) << endl;
    cout << "Size pack(1): " << sizeof(PackedDummyVector) << endl;
    cout << "Objects count: " << Object::Count() << endl;

    return 0;
}