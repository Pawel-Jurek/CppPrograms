#include "figure.h"
#include <iostream>

int main()
{
	Figure* sphere = new Sphere(10);
	std::cout << "Kula\n";
	std::cout << "Pole: " << sphere->area() << "\n";
	std::cout << "Objetosc: " <<sphere->volume()<<"\n";
	std::cout << "Pole/Obj: " <<sphere->vol_area_ratio()<<"\n\n";

	
	Figure* cuboid = new Cuboid(4,5,6);
	std::cout << "Prostopadloscian\n";
	std::cout << "Pole: " << cuboid->area() << "\n";
	std::cout << "Objetosc: " << cuboid->volume() << "\n";
	std::cout << "Pole/Obj: " << cuboid->vol_area_ratio() << "\n\n";


	Figure* cylinder = new Cylinder();
	std::cout << "Walec\n";
	std::cout << "Pole: " << cylinder->area() << "\n";
	std::cout << "Objetosc: " << cylinder->volume() << "\n";
	std::cout << "Pole/Obj: " << cylinder->vol_area_ratio() << "\n\n";


	//testowanie kostruktora kopiuj¹cego i operatora przypisania
	Cuboid c(1, 2, 3);
	Cuboid c2(3, 2, 4);
	Cuboid c3(c);
	c = c2;

	std::cout << "c.v = " << c.volume() << "\n";
	std::cout << "c3.v = " << c3.volume() << "\n";
	//

	delete sphere;
	delete cuboid;
	delete cylinder;

}
