#pragma once

class Figure
{
public:
	virtual double volume() = 0;
	virtual double area() = 0;
	inline double vol_area_ratio() { return this->area() / this->volume(); }

};

class Sphere : public Figure
{
	unsigned int radius;
public:
	Sphere();
	Sphere(const unsigned int r);
	Sphere(const Sphere& copied);

	inline unsigned int get_r() const { return radius; }
	virtual double volume() override;
	virtual double area() override;

	Sphere& operator=(const Sphere& copied);

	~Sphere();
};

class Cuboid : public Figure
{
	unsigned int a, b, c;
public:
	Cuboid();
	Cuboid(const Cuboid& copied);
	Cuboid(const unsigned int a, const unsigned int b, const unsigned int c);
	
	inline unsigned int get_a() const { return a; }
	inline unsigned int get_b() const { return b; }
	inline unsigned int get_c() const { return c; }
	virtual double volume() override;
	virtual double area() override;

	Cuboid& operator=(const Cuboid& copied);
	~Cuboid();
};

class Cylinder : public Figure
{
	unsigned int radius, height;
public:
	Cylinder();
	Cylinder(const Cylinder& copied);
	Cylinder(const unsigned int r, const unsigned int h);

	inline unsigned int get_r() const { return radius; }
	inline unsigned int get_h() const { return height; }
	virtual double volume() override;
	virtual double area() override;

	Cylinder& operator=(const Cylinder& copied);
	~Cylinder();
};