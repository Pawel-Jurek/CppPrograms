#pragma once
#include <iostream>
#include <random>

int rand_int(int low, int high);
void wypelnij_tab(int* tab, const int rozmiar);
void wyswietl_tab(int* tab, const int rozmiar);

struct Osoba
{
	std::string imie;
	unsigned int wiek;
};

struct Osoby
{
	Osoba* tab_os[10];
	int rozmiar = 5;
	int zajete = 0;
};

bool Dodaj(Osoby& osoby, const std::string& imie, int wiek);
void Wypisz(Osoby& osoby);

