#include <gtest/gtest.h>
#include "Vector.cpp"

// Тестування додавання векторів
TEST(VectorTest, AdditionVectors) {
    Vector<int> a(2), b(2);
    a[0] = 5; a[1] = 10;
    b[0] = 2; b[1] = 3;
    Vector<int> c = a + b;
    EXPECT_EQ(c[0], 7);
    EXPECT_EQ(c[1], 13);
}

// Тестування додавання скаляра
TEST(VectorTest, AdditionScalar) {
    Vector<int> a(2);
    a[0] = 10; a[1] = 20;
    Vector<int> b = a + 5;
    EXPECT_EQ(b[0], 15);
    EXPECT_EQ(b[1], 25);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}