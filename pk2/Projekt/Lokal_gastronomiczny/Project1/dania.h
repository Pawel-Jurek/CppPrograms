/** @file */

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include "funkcje.h"
#include <cstdlib>
#include <conio.h>

/** Klasa opisujaca parametry dania */
class Danie
{
protected:
	std::string nazwa;			/**< nazwa dania */
	int czas_przygotwania;		/**< czas przygotowania dania w minutosekundach (normalnie to byly by minuty, ale czekac az zrobi sie zamowienie kilka minut, to troche bez sensu, dlatego 1min=1sec */
	int wielkosc_porcji;		/**< wielkosc porcji w gramach*/
	double cena;				/**< cena dania w zlotowkach */

public:
	/** Konstruktor klasy Danie inicjuje zmienne wartosciami podanymi do konstruktora
	* @param nazwa nazwa dania
	* @param czas_przygotowania czas przygotowania dania
	* @param wielkosc_porcji wielkosc porcji dania
	* @param cena cena dania
	*/
	Danie(std::string nazwa, int czas_przygotowania, int wielkosc_porcji, double cena) : nazwa(nazwa), czas_przygotwania(czas_przygotowania), wielkosc_porcji(wielkosc_porcji), cena(cena) {}
	
	/** Funkcja zwracajaca czas przygotowania
	* @return funkcja zwraca czas przygotowania dania
	*/
	int pokaz_czas() { return czas_przygotwania; }
	
	/**  Domyslny operator spaceship dla wlasnego typu */
	auto operator<=>(const Danie& rhs) const = default;

	friend std::ostream& operator<< (std::ostream& s, const Danie& danie); /**< zakolegowanie funkcji przeciazajacej operator Dania z klasa Dania */
	friend class Zamowienie;											   /**< zakolegowanie klasy Zamowienie z klasa Danie */
	friend class Zrealizowane_zamowienie;								   /**< zakolegowanie klasy Zrealizowane_zamowienie z klasa Danie */

};

/** Klasa opisujaca parametry Menu */
class Menu
{
protected:
	std::vector<Danie> lista_dan;	/**< vector Dan prezentujacy liste dan */

public:
	/** Konstruktor klasy Menu inicjuje zmienne wartosciami podanymi w pliku, ktorego nazwa jest podawana do konstruktora
	* @param nazwa_pliku nazwa pliku z daniami
	*/
	Menu(std::string nazwa_pliku) 
	{
		std::string linia;
		std::ifstream plikwej(nazwa_pliku);
		if (!plikwej)
		{
			std::cerr << "Error: nie mozna otworzyc pliku :( " << nazwa_pliku << "\n";
		}
		while (getline(plikwej, linia))
		{
			std::istringstream dane(linia);
			std::string nazwa1, cena1, czas1, porcja1;
			dane >> nazwa1 >> czas1 >> porcja1 >> cena1;
			Danie danie(nazwa1, konwerter_ze_stringa<int>(czas1), konwerter_ze_stringa<int>(porcja1), konwerter_ze_stringa<double>(cena1));
			lista_dan.push_back(danie);
		}
	};

	/** Funkcja wyswietlajaca menu */
	void wyswietl_menu() 
	{
		system("cls");
		for (int i = 0; i < lista_dan.size(); i++)
		{
			std::cout << i + 1 << ". "; 
			std::cout << lista_dan[i];
		}
		std::cout << "\n 0 - zatwierdz operacje";
	};
	friend class Zamowienie; /**< zakolegowanie klasy Zamowienie z klasa Menu */
};