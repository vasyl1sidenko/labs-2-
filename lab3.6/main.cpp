#include <iostream>
#include "B1.h"
#include "B2.h"
#include "B3.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"

using namespace std;

int main() {
    // 1. Створення та ініціалізація об'єктів
    B1 objB1(10);
    B2 objB2(20);
    B3 objB3(30);
    D1 objD1(11, 21, 100);
    D2 objD2(31, 200);
    D3 objD3(12, 22, 101, 32, 201, 300);

    // 2. Виведення розмірів об'єктів
    cout << "=== Розміри об'єктів ===" << endl;
    cout << "sizeof(B1) = " << sizeof(B1) << " bytes" << endl;
    cout << "sizeof(B2) = " << sizeof(B2) << " bytes" << endl;
    cout << "sizeof(B3) = " << sizeof(B3) << " bytes" << endl;
    cout << "sizeof(D1) = " << sizeof(D1) << " bytes" << endl;
    cout << "sizeof(D2) = " << sizeof(D2) << " bytes" << endl;
    cout << "sizeof(D3) = " << sizeof(D3) << " bytes" << endl << endl;

    // 3. Виклик функцій show()
    cout << "=== Демонстрація ієрархії ===" << endl;
    objB1.show_B1();
    objB2.show_B2();
    objB3.show_B3();
    objD1.show_D1();
    objD2.show_D2();
    objD3.show_D3();

    return 0;
}