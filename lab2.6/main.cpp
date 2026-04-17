#include "Solution.h"
#include <iostream>

using namespace std;

int main() {
    cout << "--- 1. Створення об'єктів (Display) ---\n";
    Solution s1; 
    Solution s2(0.5, "H2SO4", 1830.0);
    Solution s3 = s2;

    s1.Display();
    s2.Display();
    
    cout << "\n--- 2. Перевантаження операторів ---\n";
    s3++;
    cout << "s3 після інкременту: " << s3 << endl;

    cout << "\n--- 3. Введення з клавіатури (Read -> Init) ---\n";
    Solution s4;
    cin >> s4;
    cout << "Ви ввели: " << s4 << endl;

    cout << "\n--- 4. Масив об'єктів ---\n";
    Solution arr[2] = { Solution(0.1, "NaCl", 2160.0), Solution(0.9, "Ethanol", 789.0) };
    for (int i = 0; i < 2; i++) {
        cout << arr[i] << endl;
    }

    cout << "\n--- 5. Лічильники та розмір пам'яті ---\n";
    cout << "Створено об'єктів Solution: " << Solution::getCounter() << "\n";
    cout << "Створено об'єктів Liquid: " << Solution::Liquid::getCounter() << "\n";
    cout << "Розмір класу без вирівнювання: " << sizeof(Solution) << " байт\n";
    cout << "Розмір класу #pragma pack(1): " << sizeof(PackedSolution) << " байт\n";

    return 0;
}