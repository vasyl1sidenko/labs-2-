#include <iostream>
#include "lab.h"

using namespace std;

// Формування списку
void appendNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Виведення списку
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Розрахунок суми парних
int calculateEvenElementsSum(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            sum += current->data;
        }
        current = current->next;
    }
    return sum;
}

// Очищення пам'яті
void deleteList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}