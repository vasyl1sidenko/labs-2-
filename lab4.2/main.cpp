#include <iostream>
#include <typeinfo>
#include "lab.h"

using namespace std;

int main() {
    // Тепер масив вказівників робимо на ІНТЕРФЕЙС
    IEmployee* workers[2];

    workers[0] = new HourlyWorker(3, 150.0, 160); 
    workers[1] = new SalariedEmployee(5, 20000.0); 

    for (int i = 0; i < 2; ++i) {
        cout << typeid(*workers[i]).name() << " | Salary: " << workers[i]->calculateSalary() << endl;
    }

    for (int i = 0; i < 2; ++i) {
        delete workers[i];
    }

    return 0;
}