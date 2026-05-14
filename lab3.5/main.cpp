#include <iostream>
#include "lab.h"

using namespace std;

int main() {
    Node* mainStack = nullptr;
    Node* radiusStack = nullptr;

    // 1. Сформувати список (з файлу)
    createStackFromFile(mainStack, "data.txt");

    cout << "Початковий стек (з файлу):" << endl;
    printStack(mainStack);

    // 2. Виконати дії
    processTriplets(mainStack, radiusStack);

    // 3. Вивести результат
    cout << "\nСтек радіусів вписаних кіл (для прямокутних трикутників):" << endl;
    printStack(radiusStack);

    deleteStack(mainStack);
    deleteStack(radiusStack);
    return 0;
}