#include <gtest/gtest.h>
#include "lab.h"

// Тест 1: Якщо список порожній, сума має бути 0
TEST(ListTest, EmptyListSum) {
    Node* head = nullptr;
    EXPECT_EQ(calculateEvenElementsSum(head), 0);
}

// Тест 2: Список тільки з непарних чисел (сума має бути 0)
TEST(ListTest, OnlyOddNumbers) {
    Node* head = nullptr;
    appendNode(head, 1);
    appendNode(head, 3);
    appendNode(head, 5);
    
    EXPECT_EQ(calculateEvenElementsSum(head), 0);
    
    deleteList(head); // прибираємо за собою пам'ять
}

// Тест 3: Список з парними і непарними числами
TEST(ListTest, MixedNumbers) {
    Node* head = nullptr;
    appendNode(head, 1); // непарне
    appendNode(head, 2); // парне
    appendNode(head, 3); // непарне
    appendNode(head, 4); // парне
    
    // Парні тут 2 і 4. Їх сума = 6.
    EXPECT_EQ(calculateEvenElementsSum(head), 6);
    
    deleteList(head);
}

// Тест 4: Список тільки з парних чисел
TEST(ListTest, OnlyEvenNumbers) {
    Node* head = nullptr;
    appendNode(head, 10);
    appendNode(head, 20);
    
    EXPECT_EQ(calculateEvenElementsSum(head), 30);
    
    deleteList(head);
}