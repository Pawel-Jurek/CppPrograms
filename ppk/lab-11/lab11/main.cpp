#include <iostream>
#include "funkcje.h"
#include <list>
#include <algorithm> 

int main()
{
	double l = 0, p = 99;
	std::list<int> lista_calkowita;
	wypelnij_liste(lista_calkowita, l, p);
	//wyswietl_liste(lista_calkowita);
	std::cout << "**************\n\n";
	l = -1;
	p = -100;
	wypelnij_liste(lista_calkowita, l, p);
	//wyswietl_liste(lista_calkowita);

	auto pozycja = std::find(lista_calkowita.begin(), lista_calkowita.end(), 125);
	if (pozycja != lista_calkowita.end())
		std::cout << "pozycja: " << *pozycja;
	else
		std::cout << "Nie znaleziono";
	std::cout << "\n";
	auto pozliczba1 = std::find(lista_calkowita.begin(), lista_calkowita.end(), -40);
	auto pozliczba2 = std::find(lista_calkowita.begin(), lista_calkowita.end(), 41);

	lista_calkowita.erase(pozliczba1, pozliczba2);
	
	auto poz80 = std::find(lista_calkowita.begin(), lista_calkowita.end(), 80);
	lista_calkowita.insert(poz80, -1);
	

	for (int i = 0; i < 3; i++)
		lista_calkowita.pop_front();
	for (int i = 0; i < 5; i++)
		lista_calkowita.pop_back();


	lista_calkowita.sort(std::greater<int>{});
	wyswietl_liste(lista_calkowita);

	std::list<Osoba> Osoby;
	Osoba osoba;
	//dodaj_osobe(Osoby);
	osoba.imie = "Antek";
	osoba.wiek = 5;
	Osoby.push_back(osoba);
	osoba.imie = "Krystian";
	osoba.wiek = 15;
	Osoby.push_back(osoba);
	osoba.imie = "Pawel";
	osoba.wiek = 20;
	Osoby.push_back(osoba);
	osoba.imie = "Maciej";
	osoba.wiek = 7;
	Osoby.push_back(osoba);
	osoba.imie = "Pawel";
	osoba.wiek = 10;
	Osoby.push_back(osoba);


	sortuj_leksy(Osoby);
	wypisz_os(Osoby);
	std::cout << "\n";
	sortuj_odwr_leksy(Osoby);
	wypisz_os(Osoby);
	std::cout << "\n";
	sortuj_odwr_wiek(Osoby);
	wypisz_os(Osoby);
	std::cout << "\n";
	sortuj_wiek(Osoby);
	wypisz_os(Osoby);
	std::cout << "\n";
	sortuj_imie_wiek(Osoby);
	wypisz_os(Osoby);
}