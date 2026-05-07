#ifndef LAB_H
#define LAB_H

// Структура вузла
struct Node {
    int data;
    Node* next;
};

// Прототипи функцій
void appendNode(Node*& head, int value);
void printList(Node* head);
int calculateEvenElementsSum(Node* head);
void deleteList(Node*& head);

#endif