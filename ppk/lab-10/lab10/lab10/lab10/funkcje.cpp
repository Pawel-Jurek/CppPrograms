#include "funkcje.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


void wyswietl_wek(std::vector<int> wektor)
{
	for (int i = 0; i < wektor.size(); i++)
	{
		//std::cout << wektor[i] << ", s " << wektor.size() << " c " << wektor.capacity() << "\n";
		std::cout << wektor[i] << " ";
	}
}

std::vector<int>::iterator znajdz_w_wekt(std::vector<int>& wektor, int wartosc)
{
	std::vector<int>::iterator it;
	it = find(wektor.begin(), wektor.end(), wartosc);
	return it;

}

std::vector<std::vector<double>> wczytaj_macierz(std::string nazwa_pliku)
{
	int kolumny=0, wiersze=0;
	std::ifstream plik(nazwa_pliku);
	plik >> kolumny;
	plik >> wiersze;
	std::vector<double>wiersz;
	std::vector<std::vector<double>>macierz;
	double liczba;
	for (int i = 0;i < wiersze;i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			plik >> liczba;
			wiersz.push_back(liczba);
		}
		macierz.push_back(wiersz);
		wiersz.clear();
	}
	plik.close();
	return macierz;
	
}

void wypisz_macierz(std::vector<std::vector<double>> macierz)
{
	for (int i = 0;i < macierz.size();i++)
	{
		for (int j = 0; j < macierz[0].size(); j++)
		{
			std::cout<<macierz[i][j]<<"\t";
		}
		std::cout << "\n";
	}
}

std::vector<std::vector<double>> dodaj_macierze(std::vector<std::vector<double>>macierz1, std::vector<std::vector<double>>macierz2)
{
	std::vector<std::vector<double>> macierz_wyjsciowa;
	std::vector<double> linia;
	if (macierz1.size() != macierz2.size() || macierz1[0].size() != macierz2[0].size())
		return { {} };
		//return macierz_wyjsciowa;
		
	for (int i =0; i< macierz1.size();i++)
	{
		for (int j = 0; j < macierz1[0].size();j++)
		{
			linia.push_back(macierz1[i][j] + macierz2[i][j]);
		}
		macierz_wyjsciowa.push_back(linia);
		linia.clear();
	}
	return macierz_wyjsciowa;
}

void zapis_do_pliku(std::vector<std::vector<double>> const& macierz, std::string const& nazwa_pliku)
{
	std::ofstream plik(nazwa_pliku);
	for (int i = 0;i < macierz.size();i++)
	{
		for (int j = 0; j < macierz[0].size(); j++)
		{
			plik << macierz[i][j] << "\t";
		}
		plik << "\n";
	}
	plik.close();
}

void dodaj_osobe(std::vector<Osoba>& osoby)
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

bool porownaj_imiona(Osoba os1, Osoba os2)
{
	return(os1.imie < os2.imie);
}
void sortuj_leksy(std::vector<Osoba>& osoby)
{
	std::sort(osoby.begin(), osoby.end(), porownaj_imiona);
}

bool porownaj_wieki(Osoba os1, Osoba os2)
{
	return(os1.wiek < os2.wiek);
}
void sortuj_wiek_rosn(std::vector<Osoba>& osoby)
{
	std::sort(osoby.begin(), osoby.end(), porownaj_wieki);
}

void sortuj_wiek_mal(std::vector<Osoba>& osoby)
{
	sortuj_wiek_rosn(osoby);
	std::reverse(osoby.begin(), osoby.end());
}

void sortuj_odwro_leksy(std::vector<Osoba>& osoby)
{
	sortuj_leksy(osoby);
	std::reverse(osoby.begin(), osoby.end());
}
void wypisz_os(std::vector<Osoba> const& osoby)
{
	for (int i = 0;i < osoby.size();i++)
	{
		std::cout << osoby[i].imie << " " << osoby[i].wiek<<"\n";
	}
}

bool porownaj_imiona2(Osoba os1, Osoba os2)
{
	if (os1.imie == os2.imie) 
		return porownaj_wieki(os1, os2);
	return(os1.imie < os2.imie);
}
void sortuj_imie_wiek(std::vector<Osoba>& osoby)
{
	std::sort(osoby.begin(), osoby.end(), porownaj_imiona2);
}