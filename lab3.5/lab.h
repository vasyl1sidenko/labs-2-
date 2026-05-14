#ifndef LAB_H
#define LAB_H

#include <string>

struct Node {
    double data; // Використовуємо double для радіусів та сторін
    Node* next;
};

// Прототипи
void push(Node*& top, double value);
double pop(Node*& top);
void createStackFromFile(Node*& top, const std::string& filename);
void printStack(Node* top);
bool isRightTriangle(double a, double b, double c);
double calculateInradius(double a, double b, double c);
void processTriplets(Node*& sourceTop, Node*& resultTop);
void deleteStack(Node*& top);

#endif