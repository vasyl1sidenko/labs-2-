#include <iostream>
#include "lab.h"

using namespace std;

// Формування двонаправленого списку
void appendNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current; // У двонаправленому списку додаємо зв'язок назад
    }
}

// Виведення списку (з відображенням двонаправленості)
void printList(Node* head) {
    if (head == nullptr) {
        cout << "Список порожній." << endl;
        return;
    }
    Node* current = head;
    cout << "NULL <- ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " <-> ";
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

// Виконання дії: Вилучення елементів, що передують заданому
// Функція лише модифікує список через параметри!
void removePrecedingElements(Node*& head, int targetValue) {
    // Якщо список порожній або має лише 1 елемент (немає чого видаляти)
    if (head == nullptr || head->next == nullptr) return;

    Node* current = head;
    
    // Йдемо по списку і дивимось на НАСТУПНИЙ елемент
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == targetValue) {
            // Знаходимо елемент, який треба видалити
            Node* nodeToDelete = current;
            Node* prevNode = nodeToDelete->prev;
            Node* nextNode = nodeToDelete->next; // Це і є елемент із targetValue

            // Переприв'язуємо вказівники в обхід nodeToDelete
            if (prevNode != nullptr) {
                prevNode->next = nextNode;
            } else {
                head = nextNode; // Якщо видаляємо найперший елемент списку
            }
            nextNode->prev = prevNode;

            // Звільняємо пам'ять
            delete nodeToDelete;

            // Перестрибуємо на елемент із targetValue і продовжуємо цикл
            current = nextNode;
        } else {
            current = current->next; // Йдемо далі, якщо збігів немає
        }
    }
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