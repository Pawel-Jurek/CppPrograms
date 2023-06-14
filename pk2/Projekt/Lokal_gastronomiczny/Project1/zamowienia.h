/** @file */

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include "dania.h"
#include <memory>
#include "windows.h" 


/** Deklaracja zapowiadajaca klasy obserwowanej */
class Zamowienie;

/** Klasa Obserwator */
class Obserwator {
public:
	/** destruktor witualny */
	virtual ~Obserwator() {}							
	
	/** Metoda czysto wirtualna aktualizujaca obserwatorow
	* @param zamowienie zamowienie przeslane do oberwatorow 
	*/
	virtual void aktualizuj(Zamowienie& zamowienie) = 0;

	/** Metoda czysto wirtualna odwolujaca obserwatorow
	* @param zamowienie zamowienie przeslane do oberwatorow
	*/
	virtual void odwolaj() = 0;	
};

/** Klasa Zamowienie */
class Zamowienie
{
protected:
	static int ctr;							/**< licznik zamowien */
	Stolik stolik;							/**< stolik do ktorego ma byc zrealizowane zamowienie */
	std::vector<Danie>zamowione_dania;		/**< tablica wektorowa Dan */
	Menu* menu;								/**< wskaznik na klase Menu */
	std::set<Obserwator*> obserwatorzy;		/**< kontener typu set przetrzymujacy wskazniki na obserwatorow */

	/** Funkcja powiadamiajaca obserwatorow */
	void powiadom() {
		for (auto& o : obserwatorzy) {
			o->aktualizuj(*this);
		}
	}

	/** Funkcja anulujaca dzialanie obserwatorow */
	void anuluj() {
		for (auto& o : obserwatorzy) {
			o->odwolaj();
		}
	}
public:
	/** Konstruktor klasy Zamowienie inicjujacy zmienne obiektami podanymi w wejsciu i inkrementujacy ilosc zamowien (ctr)
	* @param menu wskaznik na menu
	* @param stolik stolik dla ktorego jest zamowienie
	*/
	Zamowienie(Menu* menu, Stolik stolik) : menu(menu), stolik(stolik) { ctr++; };
	
	/** Funkcja zwraca zamowione dania
	* @return zamowione_dania
	*/
	std::vector<Danie>pobierz_zamowione() const { return zamowione_dania; }
	
	/** Funkcja zwraca stolik
	* @return stolik
	*/
	Stolik dostep_stolik() { return stolik; }
	
	/** Funkcja pozwalajaca dopisac obserwatora do zbioru obserwatorow
	* @param obserwator obserwator do dodania
	*/
	void dopisz(Obserwator* obserwator) {
		obserwatorzy.insert(obserwator);
	}

	/** Funkcja pozwalajaca usunac obserwatora do zbioru obserwatorow
	* @param obserwator obserwator do usunieca z listy
	*/
	void wypisz(Obserwator* obserwator) {
		obserwatorzy.erase(obserwator);
	}

	/** Funkcja do skladania zamowienia 
	* @return true jesli sie udalo zamowic, false jesli nie
	*/
	bool zloz_zamowienie()
	{
		while (true)
		{
			pokaz_menu_dzialania_zamowienie();
			prezentuj_aktualne_zakupy();
			std::cout << "\n\nTwoj wybor: ";
			char instruktator;
			std::cin >> instruktator;
			
			switch (instruktator)
			{
			case 'd':
				for (;;)
				{
					menu->wyswietl_menu();
					prezentuj_aktualne_zakupy();
					std::cout << "\nDodaj danie do zamowienia: ";
					static int numer;
					std::cin >> numer;
					if (numer > 0 && numer <= menu->lista_dan.size())
					{
						dodaj_danie_do_zamowienia(numer);
					}
					else if (numer > 0)
					{
						prezentuj_aktualne_zakupy();
						menu->wyswietl_menu();
						std::cout << "\nBrak potrawy o podanym numerze :(";
						Sleep(2000);
					}
					else
						break;
				}
				break;
			case 'u':
				for (;;)
				{
					menu->wyswietl_menu();
					prezentuj_aktualne_zakupy();
					int numer;
					std::cout << "Podaj pozycje dania do usuniecia: "; std::cin >> numer;
					if (numer > 0 && numer <= zamowione_dania.size())
					{
						zamowione_dania.erase(zamowione_dania.begin() + numer - 1);
						prezentuj_aktualne_zakupy();
					}
					else if (numer > 0)
					{
						prezentuj_aktualne_zakupy();
						menu->wyswietl_menu();
						std::cout << "\nBrak potrawy o podanym numerze :(";
						Sleep(2000);
					}
					else
						break;
				}
				break;
			case 'v':
				if (!zamowione_dania.empty())
				{
					std::cout << "Twoje zamowienie zostalo dodane do kolejki w kuchni\n";
					powiadom();
				}
				else
				{
					std::cout << "\nTwoja lista zakupow jest pusta, zamowienie nie zostalo zrealizowane\n";
					anuluj();
				}
				Sleep(3000);
				system("cls");
				return true;
			case 'x':
				anuluj();
				return false;
			}
			
		}
		
	}

	/** Funkcja dodaje danie do zamowienia
	* param poz pozycja dania z menu
	*/
	void dodaj_danie_do_zamowienia(int poz)
	{
		zamowione_dania.push_back(menu->lista_dan[poz-1]);
		pokaz_zamowione_rzeczy();
		oblicz_czas_przygotowania();
		oblicz_koszt();
	}

	/** Funkcja obliczajaca koszt zamowienia
	* @return calkowity koszt zamowienia
	*/
	double oblicz_koszt()
	{
		double koszt = 0;
		for (int i = 0; i < zamowione_dania.size(); i++)
		{
			koszt += zamowione_dania[i].cena;
		}
		std::cout << "\nKoszt twojego zamowienia: " << koszt<<"zl\n";
		return koszt;
	}

	/** Funkcja obliczajaca czas przygotowania zamowienia
	* @return calkowity czas przygotowania zamowienia
	*/
	double oblicz_czas_przygotowania()
	{
		double czas = 0;
		for (int i = 0; i < zamowione_dania.size(); i++)
		{
			czas += zamowione_dania[i].czas_przygotwania;
		}
		std::cout << "\nCzas oczekiwania na twoje zamowienie: " << czas<<"sec";
		return czas;
	}

	/** Funkcja pokazujaca zamowione rzeczy */
	void pokaz_zamowione_rzeczy()
	{
		std::cout << "\nTwoje zamowienie:\n";
		for (int i = 0; i < zamowione_dania.size(); i++)
		{
			std::cout << i + 1 << ". " << zamowione_dania[i].nazwa<<"\n";
		}
	}
	/** Funkcja prezentujaca aktualne zakupy */
	void prezentuj_aktualne_zakupy()
	{
		std::cout << "\n\nZamowienie nr: "<<ctr<<" dla stolika nr : " << stolik.dostep_numer_stolika()<<"\n";
		pokaz_zamowione_rzeczy();
		oblicz_czas_przygotowania();
		oblicz_koszt();
	}
};