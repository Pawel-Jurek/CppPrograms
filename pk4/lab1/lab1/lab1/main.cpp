#include <iostream>

import Pow;
import Square;
//import modul;

void f() {
	std::cout << "funkcja f() z main.cpp\n\n";
}

int main()
{
	// zadanie 1
	std::cout <<"5^ 3 = " << Potega(5, 3);

	// zadanie 4 

	std::cout <<"\n5^ -2 = " << Potega(5, -2);
	// zadanie 2 i 3
	Kwadrat k(5);
	std::cout << "\nPole kwadratu o boku 5: " << k.Pole();

	/*
	*  zadanie 5
	* Problem uniemo¿liwiaj¹cy kompilacjê tkwi w tym, ¿e nazwa funkcji f() wraz z parametrami jest identyczna zarówno w mainie jak i w module 
	std::cout << "\n\nwywolanie funkcji f() w main.cpp:\n\t";
	f();
	std::cout << "wywolanie funkcji g() w main.cpp:\n\t";
	g();
	*/
	
}