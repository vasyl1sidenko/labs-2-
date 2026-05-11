#include <iostream>

// === Шаблон класу Vector (з великої літери для уникнення конфліктів) ===
template <class T> 
class Vector
{
    T* v;
    int size;
public:
    // Конструктор ініціалізації
    Vector(int newsize) {
        v = new T[size = newsize];
        for (int i = 0; i < size; i++)
            v[i] = T();
    }

    // Конструктор копіювання
    Vector(const Vector& x) {
        v = new T[size = x.size];
        for (int i = 0; i < size; i++) 
            v[i] = x.v[i];
    }

    // Деструктор
    ~Vector() {
        delete[] v;
    }

    // РЕАЛІЗАЦІЯ: Додавання двох векторів (Варіант 23)
    friend Vector<T> operator + (Vector<T>& x, Vector<T>& y) {
        if (x.size != y.size) exit(1);
        Vector<T> z(x.size);
        for (int i = 0; i < x.size; i++)
            z.v[i] = x.v[i] + y.v[i];
        return z;
    }

    // РЕАЛІЗАЦІЯ: Додавання вектора та числа (Варіант 23)
    Vector<T> operator + (T scalar) {
        Vector<T> res(size);
        for (int i = 0; i < size; i++)
            res.v[i] = v[i] + scalar;
        return res;
    }

    // Оператор присвоєння
    Vector& operator = (const Vector& x) {
       if (this != &x) {
            delete[] v;
            v = new T[size = x.size];
            for (int i = 0; i < size; i++)
                v[i] = x.v[i];
        }
        return *this;
    }

    // Індексування
    T& operator [] (int index) {
        if (index < 0 || index >= size) exit(1);
        return v[index];
    }

    // Введення (використовуємо std:: для надійності)
    friend std::istream& operator >> (std::istream& is, Vector<T>& x) {
        for (int i = 0; i < x.size; i++) {
            std::cout << "element[" << i << "] = ? ";
            is >> x.v[i];
        }
        return is;
    }

    // Виведення
    friend std::ostream& operator << (std::ostream& os, Vector<T>& x) {
        for (int i = 0; i < x.size; i++)
            os << x.v[i] << ' ';
        os << std::endl;
        return os;
    }
};

 