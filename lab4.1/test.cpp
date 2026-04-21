#include <gtest/gtest.h>
#include "lab.h"

// 1. Тест для робітника з погодинною оплатою
TEST(EmployeeTest, HourlyWorkerSalary) {
    // Стаж 3 роки, 150 грн/год, 160 годин
    HourlyWorker worker(3, 150.0, 160);
    
    // Формула: (150 * 160) + (3 * 100) = 24000 + 300 = 24300
    // EXPECT_DOUBLE_EQ порівнює дробові числа (double)
    EXPECT_DOUBLE_EQ(worker.calculateSalary(), 24300.0);
}

// 2. Тест для службовця з окладом
TEST(EmployeeTest, SalariedEmployeeSalary) {
    // Стаж 5 років, оклад 20000 грн
    SalariedEmployee emp(5, 20000.0);
    
    // Формула: 20000 + (20000 * 0.05 * 5) = 20000 + 5000 = 25000
    EXPECT_DOUBLE_EQ(emp.calculateSalary(), 25000.0);
}

// 3. Тест поліморфізму (через вказівники на базовий клас)
TEST(EmployeeTest, PolymorphismTest) {
    Employee* w1 = new HourlyWorker(2, 100.0, 100);  // (100*100) + (2*100) = 10200
    Employee* w2 = new SalariedEmployee(1, 10000.0); // 10000 + (10000*0.05*1) = 10500

    EXPECT_DOUBLE_EQ(w1->calculateSalary(), 10200.0);
    EXPECT_DOUBLE_EQ(w2->calculateSalary(), 10500.0);

    // Обов'язково чистимо пам'ять у тестах
    delete w1;
    delete w2;
}

// Головна функція для запуску тестів
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}