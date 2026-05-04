#include <iostream>
#include "Fraction.h"

int main() {
    try {
        Fraction f1;
        
        std::cout << "--- Test 1: Read() --- \n";
        f1.Read();     
        f1.Display();  

        std::cout << "\n--- Test 2: Constructor --- \n";
        Fraction f2(5, 0); 
        f2.Display();      

    } catch (std::invalid_argument e) {
        std::cerr << "Input Error (by value): " << e.what() << "\n";
    } catch (NegErr& e) {
        std::cerr << "Math Error (by reference): " << e.what() << "\n";
    } catch (ZeroErr* e) {
        std::cerr << "Math Error (by pointer): " << e->msg << "\n";
        delete e;
    }

    return 0;
}