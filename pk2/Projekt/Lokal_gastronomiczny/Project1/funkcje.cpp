/** @file */

#include "funkcje.h"
#include "stolik.h"
#include "zamowienia.h"
#include <iostream>


int Zamowienie::ctr;

int wyznacz_id_wolny_stolik_min_os(std::vector<Stolik>stoliki, std::vector<int> pozycje)
{
	int min = stoliki[pozycje[0]].max_ilosc_osob;
	int pozycja_szukana = pozycje[0];
	for (int i = 0; i < pozycje.size(); i++)
	{
		if (stoliki[pozycje[i]].max_ilosc_osob < min)
		{
			min = stoliki[pozycje[i]].max_ilosc_osob;
			pozycja_szukana = pozycje[i];
		}
	}
	
	return pozycja_szukana;
}

void pokaz_menu_dzialania_zamowienie()
{
	system("cls");
	std::cout << "Wcisnij odpowiednia litere zeby przejsc do poszczegolnej opcji\n";
	std::cout << "\n d -> dodawanie dania do zamowienia";
	std::cout << "\n u -> usuwanie dania z zamowienia";
	std::cout << "\n x -> anulowanie calego zamowienia";
	std::cout << "\n v -> zatwierdzenie zamowienia\n";
}

void pokaz_menu_dzialania_wstep()
{
	system("cls");
	std::cout << "Witaj w programie gastronomia!!\n\n";
	std::cout << "Wcisnij odpowiedni klawisz i potwierdz enterem, do wykonania wybranej operacji\n";
	std::cout << "\n z -> zloz zamowienie";
	std::cout << "\n s -> pokaz statystyki";
	std::cout << "\n Kazdy inny -> zakoncz program\n";
}


std::ostream& operator<< (std::ostream& s, const Danie& danie)
{
	s << danie.nazwa << "\t" << "czas przygotwania: " << danie.czas_przygotwania << "sec | " << "wielkosc porcji: " << danie.wielkosc_porcji << "g | " << "cena: " << danie.cena << "zl\n";
	return s;
}