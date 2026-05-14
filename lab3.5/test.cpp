#include <gtest/gtest.h>
#include "lab.h"

// Тест 1: Перевірка функції визначення прямокутного трикутника
TEST(TriangleTest, LogicCheck) {
    EXPECT_TRUE(isRightTriangle(3, 4, 5));   // Класичний єгипетський
    EXPECT_TRUE(isRightTriangle(6, 8, 10));  // Масштабований
    EXPECT_FALSE(isRightTriangle(1, 2, 3));  // Не трикутник взагалі
    EXPECT_FALSE(isRightTriangle(5, 5, 5));  // Рівносторонній
}

// Тест 2: Перевірка обчислення радіуса вписаного кола
TEST(TriangleTest, InradiusCalculation) {
    // Для 3, 4, 5 радіус (3+4-5)/2 = 1
    EXPECT_NEAR(calculateInradius(3, 4, 5), 1.0, 1e-9);
    // Для 6, 8, 10 радіус (6+8-10)/2 = 2
    EXPECT_NEAR(calculateInradius(6, 8, 10), 2.0, 1e-9);
}

// Тест 3: Перевірка роботи стеку (Push/Pop)
TEST(StackTest, PushPopCheck) {
    Node* top = nullptr;
    push(top, 10.5);
    push(top, 20.5);
    
    EXPECT_DOUBLE_EQ(pop(top), 20.5);
    EXPECT_DOUBLE_EQ(pop(top), 10.5);
    EXPECT_EQ(top, nullptr);
    
    deleteStack(top);
}

// Тест 4: Перевірка обробки трійок
TEST(ProcessTest, TripletsProcessing) {
    Node* source = nullptr;
    Node* results = nullptr;
    
    // Додаємо числа так, щоб зверху була трійка 3, 4, 5
    push(source, 5);
    push(source, 4);
    push(source, 3);
    
    processTriplets(source, results);
    
    ASSERT_NE(results, nullptr);
    EXPECT_NEAR(results->data, 1.0, 1e-9); // Радіус має бути 1
    
    deleteStack(source);
    deleteStack(results);
}