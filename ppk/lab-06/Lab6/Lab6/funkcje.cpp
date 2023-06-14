#include <iostream>
#include <cmath>
#include "funkcje.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <utility>  

wektor dodaj_wektory(const wektor &w1, const wektor &w2)
{
	wektor w3;
	w3.x = w1.x + w2.x;
	w3.y = w1.y + w2.y;
	return w3;
}

wektor odejmij_wektory(const wektor &w1, const wektor &w2)
{
	wektor w3;
	w3.x = w1.x - w2.x;
	w3.y = w1.y - w2.y;
	return w3;
}

double dlugosc_wektorow(const wektor &w1, const wektor &w2)
{
	return sqrt(pow((w1.x - w2.x), 2) + pow((w1.y - w2.y), 2));
}

wektor skaluj_wektor(const wektor& w, int k) 
{
	wektor pom;
	pom.x = w.x * k;
	pom.y = w.y * k;
	return pom;
}

double iloczyn_skalarny(const wektor& w1, const wektor& w2)
{
	return w1.x * w1.y + w2.x * w2.y;
}

bool CheckCar( car v1)
{
	for (int i = 0; i < 3; i++)
	{
		if (v1._kolo[i]._typ_kola != v1._kolo[i+1]._typ_kola) return false;
	}
	return true;
}

void SetType(car &samochod, typ_kola docelowy_typ)
{
	for (int i = 0; i < 4; i++)
	{
		samochod._kolo[i]._typ_kola=docelowy_typ;
	}
}

bool czy_przestepny(const date & data)
{
	if ((data.year % 100 == 0 && data.year % 400 == 0) || (data.year % 100 != 0 && data.year % 4 == 0)) return true;
	else return false;
}

void porownaj_daty(const date& data1, const date& data2)
{
	if (data1.year > data2.year) std::cout << "Data 1, jest pozniejsza\n";
	else if (data1.year < data2.year) std::cout << "Data 2, jest pozniejsza\n";
	else
	{
		if (data1.month > data2.month) std::cout << "Data 1, jest pozniejsza\n";
		else if (data1.month < data2.month) std::cout << "Data 2, jest pozniejsza\n";
		else
		{
			if (data1.day > data2.day) std::cout << "Data 1, jest pozniejsza\n";
			else if (data1.day < data2.day) std::cout << "Data 2, jest pozniejsza\n";
			else std::cout << "Te same daty\n";
		}
	}
}

bool czy_prawidlowa_data(const date& data)
{
	if (data.year < 0 || data.month < 0 || data.month>12) return false;
	if (((data.month > 0 && data.day < 8 && data.month % 2 == 1) || (data.month > 7 && data.day < 13 && data.month % 2 == 0)) && data.day > 0 && data.day < 32) return true;
	else if (data.month > 0 && data.month != 2 && data.month < 12 && data.day > 0 && data.day < 31)return true;
	if (czy_przestepny(data) == false)
		if (data.month == 2 && data.day > 0 && data.day < 29) return true;
	else if (data.month == 2 && data.day > 0 && data.day < 30) return true;
	return false;
}
int roznica_promieni(okrag o1, okrag o2)
{
	if (o1.promien - o2.promien < 0) return(o2.promien - o1.promien);
	else return o1.promien - o2.promien;
}

polozenie_okregow funkcja_okregi(okrag o1, okrag o2)
{
	if (dlugosc_wektorow(o1.srodek, o2.srodek) == (o1.promien + o2.promien)) return styczne_zewn;
	if (dlugosc_wektorow(o1.srodek, o2.srodek) == (roznica_promieni(o1,o2))) return styczne_wewn;
	if (dlugosc_wektorow(o1.srodek, o2.srodek) < (roznica_promieni(o1, o2))) return rozlaczne_wewn;
	if (dlugosc_wektorow(o1.srodek, o2.srodek) > (roznica_promieni(o1, o2))) return rozlaczne_zewn;
	if ((roznica_promieni(o1, o2)) < dlugosc_wektorow(o1.srodek, o2.srodek) < (o1.promien + o2.promien)) return przecinajace;
	if (o1.srodek.x == o2.srodek.x && o1.srodek.y == o2.srodek.y) return wspolsrodkowe;
}

// czêœæ 2 - string

bool Dodaj_osobe(Osoby& osoby, const std::string& imie, int wiek)
{
	
	Osoba os{ imie, wiek };
	osoby.lista_osob.push_back(os);
	return true;
}

void wypisz_osoby(Osoby& osoby)
{
	for (int i = 0;i < osoby.lista_osob.size();i++)
	{
		std::cout << osoby.lista_osob[i].Imie << "  " << osoby.lista_osob[i].Wiek << std::endl;
	}
}

std::vector<int>znajdz(Osoby osoby, std::string imie)
{
	std::vector<int>indeksy;
	for (int i = 0;i < osoby.lista_osob.size();i++)
	{
		if (osoby.lista_osob[i].Imie == imie) indeksy.push_back(i);
	}
	return indeksy;
}

void wypisz_znalezione(Osoby osoby, std::vector<int> indeksy)
{
	std::cout << "\nLista nalezionych:\n";
	for (int i = 0;i < indeksy.size();i++)
	{
		std::cout <<"Pozycja: "<<indeksy[i]<<". "<< osoby.lista_osob[indeksy[i]].Imie << "  " << osoby.lista_osob[indeksy[i]].Wiek << std::endl;
	}
}

std::vector<int>znajdz_po_wieku(Osoby osoby, int mini, int maks)
{
	std::vector<int>indeksy;
	for (int i = 0;i < osoby.lista_osob.size();i++)
	{
		if (osoby.lista_osob[i].Wiek>=mini && osoby.lista_osob[i].Wiek <= maks) indeksy.push_back(i);
	}
	return indeksy;
}

void zapis_do_pliku_wektory(const int n, std::string nazwa_tekst)
{
	std::vector<wektor>tabwek;
	wektor wek;
	std::ofstream plik(nazwa_tekst);
	for (int i = 0; i < n;i++)
	{
		wek.x = n - i;
		wek.y = i;
		tabwek.push_back(wek);
		plik << tabwek[i].x << " " << tabwek[i].y << std::endl;
	}
	plik.close();
}

std::pair<wektor, wektor> oddalone_wektory(std::string nazwa_pliku)
{
	std::vector<wektor> wektory;
	std::pair<wektor, wektor>para_wyjsc;
	wektor wekt;
	double wsp;
	std::ifstream plik(nazwa_pliku);
	while (plik >> wsp)
	{
		wekt.x = wsp;
		plik >> wsp;
		wekt.y = wsp;
		wektory.push_back(wekt);
	}
	int maks = dlugosc_wektorow(wektory[0], wektory[1]);
	for (int i = 0;i < wektory.size(); i++)
	{
		for (int j = i;j < wektory.size(); j++)
		{
			if (maks < dlugosc_wektorow(wektory[i], wektory[j]))
			{
				maks = dlugosc_wektorow(wektory[i], wektory[j]);
				para_wyjsc=std::make_pair(wektory[i], wektory[j]);
			}
		}
	}
	std::cout << "maks odl: " << maks << std::endl;
	return para_wyjsc;
}