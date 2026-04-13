#pragma once

class Object
{
    static unsigned int count;
public:
    static unsigned int Count()
    {
        return count;
    }
    Object()
    {
        count++;
    }
    virtual ~Object() // Додано virtual для безпечного видалення похідних класів
    {
        count--;
    }
};