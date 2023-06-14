#pragma once
#include <iostream>
#include <list>
#include <string>

void wypelnij_liste(std::list<int>& lista, double l, double p);
void wyswietl_liste(std::list<int>& lista);

struct Osoba
{
	std::string imie;
	int wiek;
};

void dodaj_osobe(std::list<Osoba>& osoby);
void sortuj_leksy(std::list<Osoba>& osoby);
void sortuj_odwr_leksy(std::list<Osoba>& osoby);
void sortuj_odwr_wiek(std::list<Osoba>& osoby);
void sortuj_wiek(std::list<Osoba>& osoby);
void sortuj_imie_wiek(std::list<Osoba>& osoby);
void wypisz_os(std::list<Osoba> const& osoby);