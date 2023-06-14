#include <iostream>
#include <fstream>
#include <string>
#include "funkcje.h"

int main()
{
	//zad1
	std::cout << "zad1\n";
	int p = 4;
	int k = 30;
	int ilosc = 6;
	std::string nazwa1 = "zad1.txt";
	zapis_do_pliku1(nazwa1, ilosc, p, k);
	
	//zad2
	std::cout << "\nzad2\n\n";
	wyniki w;
	w=results(nazwa1);
	std::cout << w.ilosc << " " << w.srednia_liczb << " " << w.odchylenie_standardowe_liczb << std::endl;

	//zad3
	std::cout << "\nzad3\n\n";
	std::string nazwa2 = "zad3.txt";
	int rozmiar = 5;
	tabliczka_mnozenia(nazwa2, rozmiar);

	//zad4
	std::cout << "\nzad4\n\n";
	histogram("zad4.txt");
}