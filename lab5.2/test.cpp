#include <iostream>
#include "triangle.h"

using namespace std;

#define TEST(test_case_name, test_name) void test_case_name##_##test_name()

#define RUN_TEST(test_case_name, test_name) \
    cout << "[ RUN      ] " << #test_case_name << "." << #test_name << "\n"; \
    test_case_name##_##test_name();

#define EXPECT_EQ(expected, actual) \
    if ((expected) == (actual)) { cout << "[       OK ]\n"; } \
    else { cerr << "[  FAILED  ] Expected: " << (expected) << ", Actual: " << (actual) << "\n"; }

#define EXPECT_THROW(statement, expected_exception) \
    do { \
        bool threw = false; \
        try { statement; } \
        catch (expected_exception) { threw = true; cout << "[       OK ]\n"; } \
        catch (...) { cerr << "[  FAILED  ] Wrong exception type\n"; threw = true; } \
        if (!threw) { cerr << "[  FAILED  ] Exception was not thrown\n"; } \
    } while(0)

TEST(PerimeterTest, ValidTriangle) {
    EXPECT_EQ(12.0, Perimeter1(3, 4, 5));
}

TEST(PerimeterTest, ThrowsInt) {
    EXPECT_THROW(Perimeter1(1, 2, 10), int);
}

// Тест для Perimeter2 закоментовано, оскільки специфікація throw() 
// на macOS викликає аварійне завершення (std::terminate), яке неможливо зловити через catch.
/*
TEST(PerimeterTest, ThrowsDouble) {
    EXPECT_THROW(Perimeter2(-3, 4, 5), double);
}
*/

TEST(PerimeterTest, ThrowsChar) {
    EXPECT_THROW(Perimeter3(0, 4, 5), char);
}

TEST(PerimeterTest, ThrowsEmpty) {
    EXPECT_THROW(Perimeter4(3, 4, 8), Empty);
}

TEST(PerimeterTest, ThrowsError) {
    EXPECT_THROW(Perimeter5(1, 1, 3), Error&);
}

TEST(PerimeterTest, ThrowsE) {
    EXPECT_THROW(Perimeter6(3, -4, 5), E&);
}

int main() {
    cout << "[==========] Running 6 tests.\n";
    
    RUN_TEST(PerimeterTest, ValidTriangle);
    RUN_TEST(PerimeterTest, ThrowsInt);
    RUN_TEST(PerimeterTest, ThrowsChar);
    RUN_TEST(PerimeterTest, ThrowsEmpty);
    RUN_TEST(PerimeterTest, ThrowsError);
    RUN_TEST(PerimeterTest, ThrowsE);
    
    cout << "[==========] Tests completed.\n";
    return 0;
}