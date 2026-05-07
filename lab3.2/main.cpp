#include <iostream>
#include "lab.h"

using namespace std;

int main() {
    Node* head = nullptr; 
    int n, value;

    cout << "Введіть кількість елементів списку: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Введіть значення для елемента " << i + 1 << ": ";
        cin >> value;
        appendNode(head, value);
    }

    cout << "\nСформований список: ";
    printList(head);

    // Отримуємо результат з функції
    int result = calculateEvenElementsSum(head);

    // Виводимо результат у місці виклику
    cout << "Сума елементів із парними значеннями: " << result << endl;

    deleteList(head);
    return 0;
}