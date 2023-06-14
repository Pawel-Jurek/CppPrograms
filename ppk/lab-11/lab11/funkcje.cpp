#include <iostream>
#include "funkcje.h"
#include<list>
void wypelnij_liste(std::list<int>& lista, double l, double p)
{
	if (l < p)
	{
		for (double i = l; i <= p;i++)
			lista.push_back(i);
	}
	else
	{
		for (double i = l; i >= p;i--)
			lista.push_front(i);
	}
}

void wyswietl_liste(std::list<int>& lista)
{
	for (auto z : lista)
		std::cout << z << " ";
	std::cout << "\n";
}

void dodaj_osobe(std::list<Osoba>& osoby)
{
	Osoba osoba;
	std::string imie;
	int wiek;
	std::cout << "Podaj imie i wiek:";
	std::cin >> imie >> wiek;
	osoba.imie = imie;
	osoba.wiek = wiek;
	osoby.push_back(osoba);
}

void wypisz_os(std::list<Osoba> const& osoby)
{
	for (auto const &z : osoby)
		std::cout << z.imie << " " << z.wiek << "\n";
}

void sortuj_leksy(std::list<Osoba>& osoby)
{
	osoby.sort([](Osoba const& os1, Osoba const& os2) { return os1.imie < os2.imie; });
}

void sortuj_odwr_leksy(std::list<Osoba>& osoby)
{
	osoby.sort([](Osoba const& os1, Osoba const& os2) { return os1.imie > os2.imie; });
}

void sortuj_odwr_wiek(std::list<Osoba>& osoby)
{
	osoby.sort([](Osoba const& os1, Osoba const &os2) { return os1.wiek > os2.wiek; });
}
void sortuj_wiek(std::list<Osoba>& osoby)
{
	osoby.sort([](Osoba const& os1, Osoba const& os2) { return os1.wiek < os2.wiek; });
}
void sortuj_imie_wiek(std::list<Osoba>& osoby)
{
	osoby.sort([](Osoba const& os1, Osoba const& os2) {
		if (os1.imie == os2.imie)
			return os1.wiek > os2.wiek;
		else
			return os1.imie < os2.imie;
										});
}