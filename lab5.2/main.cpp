#include <iostream>
#include "triangle.h"

using namespace std;

int main() {
    set_unexpected(FU);
    set_terminate(FT); 

    double a, b, c;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;

    try {
        cout << "Периметр: " << Perimeter6(a, b, c) << endl;
    }
    catch (int) { cout << "catch (int) <= Perimeter1()" << endl; }
    catch (double) { cout << "catch (double) <= Perimeter2()" << endl; }
    catch (char) { cout << "catch (char) <= Perimeter3()" << endl; }
    catch (Empty) { cout << "catch (Empty) <= Perimeter4()" << endl; }
    catch (Error& e) { cout << e.What() << endl; }
    catch (bad_exception) { cout << "catch (bad_exception)" << endl; }
    catch (E& e) { cout << e.what() << endl; }
    catch (...) { cout << "Сталася невідома виняткова ситуація!" << endl; }

    return 0;
}