#include <iostream>
#include "funkcje.h"
#include <string>


int Okno::LiczbaOkien;
Okno::Okno()
{
	//Komponent();
	tytul = "Tytul";
	LiczbaOkien++;
	std::cout << LiczbaOkien << "<- liczba okien\n";
}

std::string Pola_hasla::pobierz_tresc_pola_tekstowego()
{
	int dlugosc = pobierz_dlugosc_tekstu();
	std::cout << "\nslugosc pola: " << dlugosc;
	std::string gwazdkowany_tekst = "";
	for (int i = 0; i < dlugosc; ++i)
	{
		gwazdkowany_tekst += "*";
	}
	return gwazdkowany_tekst;
}

void Okno::dopasuj_okno()
{
	if (przycisk->pobierz_x() + przycisk->pobierz_szerokosc() > pole->pobierz_x() + pole->pobierz_szerokosc())
	{
		szerokosc = przycisk->pobierz_szerokosc() + przycisk->pobierz_x();
		x = pole->pobierz_x();
	}

	else
	{
		szerokosc = pole->pobierz_szerokosc() + pole->pobierz_x();
		x = przycisk->pobierz_x();
	}

	if (przycisk->pobierz_y() + przycisk->pobierz_wysokosc() > pole->pobierz_y() + pole->pobierz_wysokosc())
	{
		wysokosc = przycisk->pobierz_wysokosc() + przycisk->pobierz_y();
		y = pole->pobierz_y();
	}

	else
	{
		wysokosc = pole->pobierz_wysokosc() + pole->pobierz_y();
		y = przycisk->pobierz_y();
	}


	std::cout << "\n\nNowa szerokosc:" << szerokosc << "   Nowa wysokosc:" << wysokosc;
	std::cout << "    Nowy x: " << x << "   Nowy y: " << y << "\n\n";

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