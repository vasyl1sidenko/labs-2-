#include <iostream>
#include "lab.h"

using namespace std;

int main() {
    Node* head = nullptr; 
    int n, value, targetValue;

    cout << "Введіть кількість елементів списку: ";
    cin >> n;
    //сформувати
    for (int i = 0; i < n; i++) {
        cout << "Введіть значення елемента " << i + 1 << ": ";
        cin >> value;
        appendNode(head, value);
    }

    
    //друк
    cout << "\nСформований список: ";
    printList(head);

    cout << "\nВведіть значення елемента, ПЕРЕД яким треба видалити вузол: ";
    cin >> targetValue;

    //дії
    removePrecedingElements(head, targetValue);

    //вивід
    cout << "Список після вилучення: ";
    printList(head);

    deleteList(head);
    return 0;
}