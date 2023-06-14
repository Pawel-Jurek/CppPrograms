#include <iostream>
#include "funkcje.h"
int Okno::LiczbaOkien;
Okno::Okno()
{
	tytul = "Tytul";
	x = 2;
	y = 1;
	LiczbaOkien++;
	std::cout << LiczbaOkien << "<- liczba okien\n";
}

void Okno::dopasuj_okno(Okno& okno)
{
	okno.x=okno.przycisk->wielkosc_przycisku().first + okno.pole->wielkosc_pola().first;
	okno.y=okno.przycisk->wielkosc_przycisku().second + okno.pole->wielkosc_pola().second;
	std::cout << "\n\nx:"<<okno.x << "   y:" << okno.y << "\n\n";
}

Okno::~Okno()
{
	std::cout << "Wywolany destruktur okna \n";
	LiczbaOkien--;
	std::cout << LiczbaOkien << "<- liczba okien\n";
	
}


Przycisk::Przycisk()
{
	opis = "opis";
	x = 2;
	y = 1;
}

std::pair<double,double> Przycisk::wielkosc_przycisku()
{
	Przycisk przycisk;
	return std::make_pair(przycisk.x, przycisk.y);
}

Przycisk::~Przycisk()
{
	std::cout << "Wywolany destruktur przycisku \n";
}

Pole::Pole()
{
	dlugosc = 0;
	x = 2;
	y = 1;
}

std::pair<double, double> Pole::wielkosc_pola()
{
	Pole pole;
	return std::make_pair(pole.x, pole.y);
}

Pole::~Pole()
{
	std::cout << "Wywolany destruktur pola \n";
}