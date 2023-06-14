#pragma once
#include <iostream>

class Vector
{
private:
    float x, y, z;

protected:
    static int counter;
    static int active;
    int obj_number;

public:   
    Vector();

    Vector(float x, float y, float z);

    Vector(const Vector& c);

    void add(const Vector& v);

    void substract(const Vector& v);

    float scalar_mult(const Vector& v);

    void show_vector();

    ~Vector();

    static int GetCounter();
    
    int GetId();

    static int GetActive();

};
