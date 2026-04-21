#include "lab.h"

Employee::Employee(int exp) {
    experience = exp;
}

Employee::~Employee() {}

HourlyWorker::HourlyWorker(int exp, double rate, int hours) : Employee(exp) {
    hourlyRate = rate;
    hoursWorked = hours;
}

double HourlyWorker::calculateSalary() const {
    return (hourlyRate * hoursWorked) + (experience * 100);
}

SalariedEmployee::SalariedEmployee(int exp, double salary) : Employee(exp) {
    baseSalary = salary;
}

double SalariedEmployee::calculateSalary() const {
    return baseSalary + (baseSalary * 0.05 * experience);
}