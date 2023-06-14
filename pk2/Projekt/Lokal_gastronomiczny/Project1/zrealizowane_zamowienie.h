/** @file */

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "funkcje.h"
#include "dania.h"
#include "zamowienia.h"
#include <map> 

/** Klasa Zrealizowane_zamowienie dziedziczaca publicznie po klasie Obserwator */
class Zrealizowane_zamowienie :public Obserwator
{
protected:
	std::map<Danie, int> ilosc;					/**< kontener typu mapa, bedacy magazynem zrealizowanych dan */
	static std::vector<Zamowienie>zamowienia;	/**< vector Zamowien */
	
public:

	/** Funkcja dodajaca nowe dania do "magazynu", ktore uprzednio zostaly zrealizowane 
	* @param zam zamowienie, ktore zostalo zamowione
	*/
	void aktualizuj(Zamowienie& zam) override
	{	
		auto zamowione = zam.pobierz_zamowione();
		for (int i = 0; i < zamowione.size(); i++)
		{
			ilosc[zamowione[i]]++;
		}
	}
	
	/** Funkcja nic nie robi, ale musi byc jako ze jest pochodna od virtualnej */
	void odwolaj() override {}

	/** Funkcja pokazujaca statystyki, to znaczy zawartosc magazynu */
	void pokaz_statystyki()
	{
		std::cout << "Statystyki:\n\n";
		
		for (auto &wpis : ilosc)
		{
			std::cout << wpis.first.nazwa << " " << wpis.second<<"\n";
		}
		Sleep(2000);		
	}
	friend class Zamowienie; /**< zakolegowanie klasy Zamowienie z klasa Zrealizowane_zamowienie */

};