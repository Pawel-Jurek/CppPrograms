#include "funkcje.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int main()
{
	std::vector<int>wektor;
	std::cout << wektor.size() << " " << wektor.capacity() << "\n";

	for (int i = 0; i < 100; i++)
	{
		wektor.push_back(i);
		//std::cout <<i<< ". s " << wektor.size() << " c " << wektor.capacity() << "\n";
	}
	
	std::vector<int>::iterator it;

	
	it = znajdz_w_wekt(wektor, 125);
	
	if (it != wektor.end())
		std::cout << "Element found in myvector: " << *it << '\n';
	else
		std::cout << "Element not found in myvector\n";

	it = znajdz_w_wekt(wektor, 40);
	if (it != wektor.end())
		wektor.erase(it, wektor.end());
	//wyswietl_wek(wektor);

	//zad5
	it = znajdz_w_wekt(wektor, 20);
	if (it != wektor.end())
		wektor.insert(it,-1);
	//wyswietl_wek(wektor);
	
	wektor.pop_back();
	wektor.pop_back();
	wektor.pop_back();

	//wyswietl_wek(wektor);

	
	std::cout << "\n";
	std::reverse(wektor.begin(), wektor.end());
	//wyswietl_wek(wektor);

	//zad8
	std::vector < std::vector<double>> macierz1, macierz2;
	macierz1 = wczytaj_macierz("macierz.txt");
	macierz2 = wczytaj_macierz("macierz.txt");
	//std::cout << "\nmacierz1:\n";
	//wypisz_macierz(macierz1);
	//std::cout << "\n\nmacierz2:\n";
	//wypisz_macierz(macierz2);
	//std::cout << "\n\nsuma macierzy:\n";
	//wypisz_macierz(dodaj_macierze(macierz1, macierz2));
	zapis_do_pliku(dodaj_macierze(macierz1, macierz2), "dodane_macierze.txt");

	//czêœæ 3

	std::vector<Osoba> Osoby;
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
	sortuj_odwro_leksy(Osoby);
	wypisz_os(Osoby);
	std::cout << "\n";
	sortuj_wiek_mal(Osoby);
	wypisz_os(Osoby);
	std::cout << "\n";
	sortuj_wiek_rosn(Osoby);
	wypisz_os(Osoby);
	std::cout << "\n";
	sortuj_imie_wiek(Osoby);
	wypisz_os(Osoby);
}