#include "Vector.h"
#include <iostream>


Vector::Vector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    counter++;
    active++;
    obj_number = counter;
    std::cout << " + pusty active: " << active << ", counter: " << counter << "\n";
}

Vector::Vector(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    counter++;
    active++;
    obj_number = counter;
    std::cout << " + z parametrami active: " << active << ", counter: " << counter << "\n";
}

Vector::Vector(const Vector& c)
{
    x = c.x;
    y = c.y;
    z = c.z;
    counter++;
    active++;
    obj_number = counter;
}

void Vector::add(const Vector& v)
{
    x += v.x, y += v.y, z += v.z;
}

void Vector::substract(const Vector& v)
{
    x -= v.x, y -= v.y, z -= v.z;
}

float Vector::scalar_mult(const Vector& v)
{
    return x * v.x + y * v.y + z * v.z;
}

void Vector::show_vector()
{
    std::cout << x << ", " << y << ", " << z << "\n";
}

Vector::~Vector()
{
    active--;
    std::cout << " - active: " << active << ", counter: " << counter << "\n";
}

int Vector::GetCounter()
{
    return counter;
}
int Vector::GetActive()
{
    return active;
}

int Vector::GetId()
{
    return obj_number;
}

int Vector::active = 0;
int Vector::counter = 0;