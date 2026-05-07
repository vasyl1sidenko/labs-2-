#include <gtest/gtest.h>
#include <vector>
#include "lab.h"

// Допоміжна функція для швидкої перевірки вмісту списку у тестах
std::vector<int> listToVector(Node* head) {
    std::vector<int> result;
    Node* current = head;
    while (current != nullptr) {
        result.push_back(current->data);
        current = current->next;
    }
    return result;
}

// Тест 1: Якщо список порожній, програма не має крашнутись
TEST(DoublyListTest, EmptyList) {
    Node* head = nullptr;
    removePrecedingElements(head, 5);
    EXPECT_EQ(head, nullptr);
}

// Тест 2: Якщо елемента немає в списку, список не змінюється
TEST(DoublyListTest, TargetNotFound) {
    Node* head = nullptr;
    appendNode(head, 1);
    appendNode(head, 2);
    
    removePrecedingElements(head, 5); // Шукаємо 5, якого немає
    
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(listToVector(head), expected);
    deleteList(head);
}

// Тест 3: Цільовий елемент посередині (класичний випадок)
TEST(DoublyListTest, RemoveMiddleElement) {
    Node* head = nullptr;
    appendNode(head, 1);
    appendNode(head, 2); // Видалиться
    appendNode(head, 3); // targetValue
    
    removePrecedingElements(head, 3);
    
    std::vector<int> expected = {1, 3};
    EXPECT_EQ(listToVector(head), expected);
    deleteList(head);
}

// Тест 4: Видалення голови списку (першого елемента)
TEST(DoublyListTest, RemoveHeadElement) {
    Node* head = nullptr;
    appendNode(head, 1); // Видалиться, бо він перед двійкою
    appendNode(head, 2); // targetValue
    appendNode(head, 3);
    
    removePrecedingElements(head, 2);
    
    std::vector<int> expected = {2, 3};
    EXPECT_EQ(listToVector(head), expected);
    
    // Обов'язково перевіряємо, чи вказівник prev нової голови став nullptr
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->prev, nullptr);
    
    deleteList(head);
}

// Тест 5: Цільовий елемент стоїть першим (перед ним нічого немає)
TEST(DoublyListTest, TargetIsFirstElement) {
    Node* head = nullptr;
    appendNode(head, 1); // targetValue
    appendNode(head, 2);
    
    removePrecedingElements(head, 1);
    
    std::vector<int> expected = {1, 2}; // Нічого не має змінитися
    EXPECT_EQ(listToVector(head), expected);
    deleteList(head);
}