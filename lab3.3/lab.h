#ifndef LAB_H
#define LAB_H

// Структура вузла двонаправленого списку
struct Node {
    int data;
    Node* prev; // Вказівник на попередній елемент
    Node* next; // Вказівник на наступний елемент
};

//одна функція = одна роль
void appendNode(Node*& head, int value);
void printList(Node* head);
void removePrecedingElements(Node*& head, int targetValue);
void deleteList(Node*& head);

#endif