/** @file */

#pragma once
#include <vector>
#include <string>
#include "stolik.h"
#include "windows.h" 


/** Funkcja wyznaczajaca id pierwszego wolnego stolika jesli liczba chetnyc
* @param stoliki vector slolikow
* @param pozycje vector pozycji
* @return pozycja wolnego stolika na liscie stolikow
*/
int wyznacz_id_wolny_stolik_min_os(std::vector<Stolik>stoliki, std::vector<int> pozycje);

/** Funkcja prezentujaca menu dzialania zwiazane ze skladaniem zamowienia */
void pokaz_menu_dzialania_zamowienie();

/** Funkcja prezentujaca menu dzialania na poczatku programu */
void pokaz_menu_dzialania_wstep();

/** Funkcja szablonowa konwertujaca na podany typ ze stringa
* @param wyraz wyraz do przekonwertowania
* @return przekonwertowany napis na podany typ
*/
template <typename T>
T konwerter_ze_stringa(std::string wyraz)
{
	T wynik = 0;
	auto it = wyraz.find('.');
	if (it == std::string::npos)
	{
		it = 0;
	}
		
	bool calkowite = true;
	int i_po_przecinku=1;
	for (int i = 0; i <wyraz.size(); i++)
	{
		if (wyraz[i] == '.')
		{
			i++;
			calkowite = false;	
			if (i >= wyraz.size()) break;
		}
		if (calkowite)
		{
			wynik += ((T)wyraz[i] - '0') * pow(10, wyraz.size()-it-i-1);
		}
			
		else
		{
			wynik += ((T)wyraz[i] - '0') * pow(10, (0 - i_po_przecinku));
			i_po_przecinku++;
		}
			
	}
	return wynik;
}