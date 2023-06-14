#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
struct wektor
{
	double x, y;
};
wektor dodaj_wektory(const wektor& w1, const wektor& w2);
wektor odejmij_wektory(const wektor& w1, const wektor& w2);
double dlugosc_wektorow(const wektor &w1, const wektor &w2);
wektor skaluj_wektor(const wektor& w,  int k);
double iloczyn_skalarny(const wektor& w1, const wektor& w2);

enum typ_kola { letnia, zimowa };
struct wheel
{
	typ_kola _typ_kola;
};

struct car
{
	wheel _kolo[4];
};

bool CheckCar(const car v1);

void SetType(car& samochod, typ_kola docelowy_typ);

struct date
{
	int year, month, day;
};

bool czy_przestepny(const date &data);
void porownaj_daty(const date& data1, const date& data2);
bool czy_prawidlowa_data(const date & data);

struct okrag
{
	wektor srodek;
	double promien;
};

enum polozenie_okregow {styczne_zewn, styczne_wewn, przecinajace, wspolsrodkowe, rozlaczne_zewn, rozlaczne_wewn};

int roznica_promieni(okrag o1, okrag o2);

polozenie_okregow funkcja_okregi (okrag o1, okrag o2);

// czêœæ 2 - string

struct Osoba
{
	std::string Imie;
	unsigned int Wiek;
};

struct Osoby
{
	std::vector<Osoba>lista_osob;
};

bool Dodaj_osobe(Osoby& osoby, const std::string& imie, int wiek);
void wypisz_osoby(Osoby& osoby);

std::vector<int>znajdz(Osoby osoby, std::string imie);

void wypisz_znalezione(Osoby osoby, std::vector<int> it);
std::vector<int>znajdz_po_wieku(Osoby osoby, int mini, int maks);

void zapis_do_pliku_wektory(const int n, std::string nazwa_tekst);
std::pair<wektor, wektor> oddalone_wektory(std::string nazwa_pliku);