/** @file */

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "funkcje.h"
#include "windows.h" 

/** Klasa Stolik */
class Stolik
{
protected:
	int numer;					/**< numer stolika */
	int max_ilosc_osob;			/**< maksymalna ilosc osob przy danym stoliku */
	int aktualni_uzytkownicy;	/**< liczba aktualnych uzytkownikow stolika */
	bool wolny;					/**< czy stolik wolny */
public:
	/** Konstruktor klasy Stolik inicjuje zmienne wartosciami podanymi do konstruktora, ponadto ustawia stolik na wolny i aktualnych_uzytkownikow na 0
	* @param numer numer stolika
	* @param max_ilosc_osob maksymalna ilosc osob przy danym stoliku
	*/
	Stolik(int numer, int max_ilosc_osob) : numer(numer), max_ilosc_osob(max_ilosc_osob), aktualni_uzytkownicy(0), wolny(true) {}

	/** Funkcja zwraca wartosc maksymalnej liczby osob przy stole
	* @return max_ilosc_osob maksymalna ilosc osob przy danym stoliku
	*/
	int dostep_do_maxa() { max_ilosc_osob; }

	/** Funkcja zwraca numer stolika
	* @return numer numer stolika
	*/
	int dostep_numer_stolika() { return numer; }

	/** Funkcja pokazuje stolik */
	void pokaz_stolik()
	{
		std::cout << numer << ". " << "max ilosc osob: " << max_ilosc_osob << " | ilosc korzystajacych:" << aktualni_uzytkownicy << " | wolny: " << wolny << "\n";
	}
	/** Funkcja zajmuje stolik */
	void zajmij()
	{
		wolny = false;
	}
	friend class ListaStolikow;																			/**< zakolegowanie klasy Stolik z klasa ListaStolikow */
	friend int wyznacz_id_wolny_stolik_min_os(std::vector<Stolik>stoliki, std::vector<int> pozycje);	/**< zakolegowanie klasy Stolik z funkcja wyznacz_id_wolny_stolik_min_os */
};

/** Klasa ListaStolikow */
class ListaStolikow
{
protected:
	std::vector<Stolik>stoliki;			/**< tablica wektorowa Stolikow */
public:
	/** Funkcja zwraca stoliki
	* @return stoliki zwraca stoliki
	*/
	std::vector<Stolik> dostep_stoliki() { return stoliki; }
	
	/** Konstruktor dla klasy ListaStolikow, inicjuje zmienna Stolikami zawartymi w pliku
	* @param nazwa_pliku nazwa pliku ze stolikami
	*/
	ListaStolikow(std::string nazwa_pliku)
	{
		std::ifstream plikwej(nazwa_pliku);
		if (!plikwej)
		{
			std::cerr << "Error: nie mozna otworzyc pliku :( " << nazwa_pliku << "\n";
		}		
		while (true)
		{
			int nr, ilosc;
			plikwej >> nr >> ilosc;
			if (!plikwej.fail())
			{
				Stolik stolik(nr, ilosc);
				stoliki.push_back(stolik);
			}
			else
				break;
		}		
	};

	/** Funkcja wyswietla stoliki */
	void wyswietl_stoliki()
	{
		for (int i = 0; i < stoliki.size(); i++)
		{
			stoliki[i].pokaz_stolik();
		}
	};
	
	/** Funkcja zwalnia stolik */
	void zwolnij_stolik(int poz)
	{
		stoliki[poz].wolny = true;
		stoliki[poz].aktualni_uzytkownicy = 0;
	}

	/** Funkcja szuka stolik i zwraca zajeta pozycje
	* @param ilosc_chetnych ilosc osob dla ktorej przyporzadkowac stolik
	* @return pozycja znalezionego stolika
	*/
	int szukaj_stolika(int ilosc_chetnych)
	{
		bool tmp = false;
		int pozycja_zajeta=0;
		for (int i = 0; i < stoliki.size(); i++)
		{
			if (stoliki[i].wolny == true && stoliki[i].max_ilosc_osob == ilosc_chetnych)
			{
				stoliki[i].zajmij();
				stoliki[i].aktualni_uzytkownicy = ilosc_chetnych;
				pozycja_zajeta = i;
				tmp = true;
				break;
			}
		}
		std::vector<int>nr_stolika_do_rezerwacji;
		nr_stolika_do_rezerwacji.resize(0);
		if (tmp == false)
		{
			for (int i = 0; i < stoliki.size(); i++)
			{
				if (stoliki[i].wolny == true && stoliki[i].max_ilosc_osob >= ilosc_chetnych)
				{
					nr_stolika_do_rezerwacji.push_back(i);
				}
			}
			if (!nr_stolika_do_rezerwacji.empty())
			{
				int poz = wyznacz_id_wolny_stolik_min_os(stoliki, nr_stolika_do_rezerwacji);
				stoliki[poz].zajmij();
				stoliki[poz].aktualni_uzytkownicy = ilosc_chetnych;
				pozycja_zajeta = poz;
				tmp = true;
			}
			
		}
		return pozycja_zajeta;
		if (tmp == false)
			std::cout << "Nie udalo sie znalezc stolika :(\n";
		return -1;
		Sleep(2000);
	};
};