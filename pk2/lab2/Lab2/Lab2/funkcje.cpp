#include <iostream>
#include "funkcje.h"
#include <string>


int Okno::LiczbaOkien;
Okno::Okno()
{
	Komponent();
	tytul = "Tytul";
	LiczbaOkien++;
	std::cout << LiczbaOkien << "<- liczba okien\n";
}

std::string Pola_hasla::pobierz_tresc_pola_tekstowego()
{
	int dlugosc = pobierz_dlugosc_tekstu();
	std::cout << "\nslugosc pola: " << dlugosc;
	std::string gwazdkowany_tekst="";
	for (int i = 0; i < dlugosc; ++i)
	{
		gwazdkowany_tekst += "*";
	}
	return gwazdkowany_tekst;
}

void Okno::dopasuj_okno()
{

	if (dostep_przycisk().pobierz_x() + dostep_przycisk().pobierz_szerokosc() > dostep_pole().pobierz_x() + dostep_pole().pobierz_szerokosc())
	{
		szerokosc = dostep_przycisk().pobierz_szerokosc() + dostep_przycisk().pobierz_x();
		x = dostep_pole().pobierz_x();
	}
		
	else
	{
		szerokosc = dostep_pole().pobierz_szerokosc() + dostep_pole().pobierz_x();
		x = dostep_przycisk().pobierz_x();
	}
		
	if (dostep_przycisk().pobierz_y() + dostep_przycisk().pobierz_wysokosc() > dostep_pole().pobierz_y() + dostep_pole().pobierz_wysokosc())
	{
		wysokosc = dostep_przycisk().pobierz_wysokosc() + dostep_przycisk().pobierz_y();
		y = dostep_pole().pobierz_y();
	}
		
	else
	{
		wysokosc = dostep_pole().pobierz_wysokosc() + dostep_pole().pobierz_y();
		y = dostep_przycisk().pobierz_y();
	}
		

	std::cout << "\n\nNowa szerokosc:" << szerokosc << "   Nowa wysokosc:" << wysokosc;
	std::cout << "    Nowy x: " << x << "   Nowy y: " << y <<"\n\n";
	
}

Okno::~Okno()
{
	std::cout << "Wywolany destruktur okna \n";
	LiczbaOkien--;
	std::cout << LiczbaOkien << "<- liczba okien\n";

}

/*
Przycisk::Przycisk()
{
	Komponent();
	opis = "opis";
}
*/
Przycisk::~Przycisk()
{
	std::cout << "Wywolany destruktur przycisku \n";
}

/*
Pole::Pole()
{
	Komponent();
	dlugosc = 0;
}
*/


Pole_tekstowe::~Pole_tekstowe()
{
	std::cout << "Wywolany destruktur pola \n";
}

Komponent::~Komponent()
{
	std::cout << "Wywolany destruktur komponentu \n";
}

Kontrolka::~Kontrolka()
{
	std::cout << "wywolany destruktor kontrolki\n";
}

Pola_hasla::~Pola_hasla()
{
	std::cout << "wywolany destruktor hasla\n";
}