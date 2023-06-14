#define _USE_MATH_DEFINES
#include <cmath>
#include "figure.h"
#include <iostream>

double Sphere::volume()
{
	return 4/3 * M_PI * pow(radius,3);
}
double Sphere::area()
{
	return 4 * M_PI * pow(radius, 2);
}

Sphere& Sphere::operator=(const Sphere& copied)
{
	this->radius = copied.radius;
	return *this;
}

Sphere::Sphere()
{
	radius = 1;
}
Sphere::Sphere(const unsigned int r)
{
	radius = r;
}
Sphere::Sphere(const Sphere& copied)
{
	this->radius = copied.radius;
}
Sphere::~Sphere()
{
	std::cout << "Destruktor objektu KULA\n";
}


double Cuboid::volume()
{
	return a * b * c;
}
double Cuboid::area()
{
	return (a * b * 2 + a * c * 2 + c * b * 2);
}
Cuboid::Cuboid()
{
	a = b = c = 1;
}
Cuboid::Cuboid(const unsigned int a, const unsigned int b, const unsigned int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
Cuboid::Cuboid(const Cuboid& copied)
{
	this->a = copied.a;
	this->b = copied.b;
	this->c = copied.c;
}

Cuboid& Cuboid::operator=(const Cuboid& copied)
{
	this->a = copied.a;
	this->b = copied.b;
	this->c = copied.c;
	return *this;
}

Cuboid::~Cuboid()
{
	std::cout << "Destruktor objektu PROSTOPADLOSCIAN\n";
}


double Cylinder::volume()
{
	return M_PI * pow(radius, 2) * height;
}
double Cylinder::area()
{
	return 2 * M_PI * radius * (radius + height);
}

Cylinder::Cylinder()
{
	radius = height = 1;
}
Cylinder::Cylinder(const unsigned int r, const unsigned int h)
{
	this->radius = r;
	this->height = h;
}
Cylinder::Cylinder(const Cylinder& copied)
{
	this->radius = copied.radius;
	this->height = copied.height;
}

Cylinder& Cylinder::operator=(const Cylinder& copied)
{
	this->radius = copied.radius;
	this->height = copied.height;
	return *this;
}

Cylinder::~Cylinder()
{
	std::cout << "Destruktor objektu WALEC\n";
}