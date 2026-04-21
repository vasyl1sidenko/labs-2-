#ifndef LAB_H
#define LAB_H

class Employee {
protected:
    int experience;

public:
    Employee(int exp);
    virtual ~Employee();
    virtual double calculateSalary() const = 0;
};

class HourlyWorker : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyWorker(int exp, double rate, int hours);
    double calculateSalary() const override;
};

class SalariedEmployee : public Employee {
private:
    double baseSalary;

public:
    SalariedEmployee(int exp, double salary);
    double calculateSalary() const override;
};

#endif