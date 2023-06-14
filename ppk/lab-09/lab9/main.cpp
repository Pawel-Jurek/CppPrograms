#include "funkcje.h"
#include <iostream>

int main()
{
	int a = 9;
	int* ap = &a;
	int* bp = ap;
	ap = nullptr;
	std::cout << ++(*bp)<<"\n";
	const int rozmiar = 5;
	int tab[rozmiar];
	wypelnij_tab(tab,rozmiar);
	wyswietl_tab(tab, rozmiar);

	int* x = new int(17);
	std::cout << "\n\n" << *x;
	int* y = x;
	delete x;
	std::unique_ptr<int>znacznik(new int);
	*znacznik = 55;
	std::cout << "\n" << *znacznik;
	std::string imie;
	int wiek;
	Osoby osoby;
	for (int i = 0;i < 3;i++)
	{
		std::cout << "\nImie i wiek osoby: " << i+1 << "\n";
		std::cin >> imie;
		std::cin >> wiek;
		Dodaj(osoby, imie, wiek);
	}
	Wypisz(osoby);
}