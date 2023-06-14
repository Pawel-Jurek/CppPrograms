#include "funkcje.h"
#include <iostream>
#include <random>


int rand_int(int low = 0, int high = 99)
{
	static std::default_random_engine re{ std::random_device{}() };
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}

void wypelnij_tab(int* tab, const int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		*(tab + i) = rand_int(1, 15);
	}
}
void wyswietl_tab(int* tab, const int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		std::cout << "t[" << i << "]=" << *(tab + i) << "\n";
	}
}

bool Dodaj(Osoby& osoby, const std::string& imie, int wiek)
{

	if (osoby.zajete >= osoby.rozmiar) return false;
	Osoba* pers = new Osoba;

	osoby.tab_os[osoby.zajete] = pers;
	osoby.tab_os[osoby.zajete]->imie = imie;
	osoby.tab_os[osoby.zajete]->wiek = wiek;
	//osoby.tab_osob[osoby.zajete].imie = imie;
	//osoby.tab_osob[osoby.zajete].wiek = wiek;
	osoby.zajete++;
	return true;
}

void Wypisz(Osoby& osoby)
{
	for (int i = 0; i < osoby.zajete; i++)
	{
		std::cout << osoby.tab_os[i]->imie << " ";
		std::cout << osoby.tab_os[i]->wiek << "\n";
		//std::cout << osoby.tab_os[i]->wiek<< "\n";
	}
}