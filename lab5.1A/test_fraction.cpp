#include <gtest/gtest.h>
#include "Fraction.h"

TEST(FractionTest, ValidInitialization) {
    Fraction f;
    EXPECT_NO_THROW(f.Init(10, 2));
    EXPECT_EQ(f.ipart(), 5);
}

TEST(FractionTest, ThrowsNegativeError) {
    Fraction f;
    EXPECT_THROW(f.Init(-5, 2), NegErr);
    EXPECT_THROW(f.Init(5, -2), NegErr);
    EXPECT_THROW(f.Init(-5, -2), NegErr);
}

TEST(FractionTest, ThrowsZeroError) {
    Fraction f;
    EXPECT_THROW(f.Init(5, 0), ZeroErr*);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}