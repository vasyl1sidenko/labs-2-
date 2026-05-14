#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "lab.h"

using namespace std;

void push(Node*& top, double value) {
    Node* newNode = new Node{value, top};
    top = newNode;
}

double pop(Node*& top) {
    if (top == nullptr) return 0;
    Node* temp = top;
    double val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

void createStackFromFile(Node*& top, const string& filename) {
    ifstream file(filename);
    double val;
    while (file >> val) {
        push(top, val);
    }
    file.close();
}

void printStack(Node* top) {
    if (!top) { cout << "Стек порожній" << endl; return; }
    Node* current = top;
    while (current) {
        cout << "| " << current->data << " |" << endl;
        current = current->next;
    }
    cout << " --- " << endl;
}

// Перевірка на прямокутний трикутник (a^2 + b^2 = c^2)
bool isRightTriangle(double a, double b, double c) {
    double sides[3] = {a, b, c};
    sort(sides, sides + 3);
    // Використовуємо epsilon для порівняння double
    return abs(pow(sides[0], 2) + pow(sides[1], 2) - pow(sides[2], 2)) < 1e-9;
}

// Радіус вписаного кола: r = (a + b - c) / 2 (для прямокутного)
double calculateInradius(double a, double b, double c) {
    double sides[3] = {a, b, c};
    sort(sides, sides + 3);
    return (sides[0] + sides[1] - sides[2]) / 2.0;
}

// Головна логіка: витягуємо по 3, перевіряємо, записуємо радіуси в новий стек
void processTriplets(Node*& sourceTop, Node*& resultTop) {
    while (sourceTop != nullptr) {
        // Нам потрібно мінімум 3 числа
        if (sourceTop->next == nullptr || sourceTop->next->next == nullptr) break;

        double a = pop(sourceTop);
        double b = pop(sourceTop);
        double c = pop(sourceTop);

        if (isRightTriangle(a, b, c)) {
            double r = calculateInradius(a, b, c);
            push(resultTop, r);
        }
    }
}

void deleteStack(Node*& top) {
    while (top) pop(top);
}