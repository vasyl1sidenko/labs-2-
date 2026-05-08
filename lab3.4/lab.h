#ifndef LAB_H
#define LAB_H

// Вузол однонаправленого кільцевого списку
struct Node {
    int data;
    Node* next;
};

// Прототипи
void appendNode(Node*& head, int value);
void printList(Node* head);
bool hasDuplicateValues(Node* head); // Повертає true, якщо є дублікати
void deleteList(Node*& head);

#endif