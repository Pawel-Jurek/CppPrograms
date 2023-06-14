/** @file */

#include <iostream>
#include <string>
#include "funkcje.h"
#include "dania.h"
#include "pracownicy.h"
#include "zamowienia.h"
#include "zrealizowane_zamowienie.h"
#include "stolik.h"
#include <cstdio>
#include <stdio.h>
#include "windows.h"
#include <conio.h>

int main()
{
	Menu menu("lista_dan.txt");
	ListaStolikow stoliki("lista_stolikow.txt");
	Zrealizowane_zamowienie zrealizowane;
	Kuchnia kuchnia("pracownicy.txt");

	while (true)
	{
		pokaz_menu_dzialania_wstep();
		std::cout << "\n\nTwoj wybor: ";
		char instruktator;
		std::cin >> instruktator;
		static int chetni = 0;
		switch (instruktator)
		{
			case 'z':	
			{
				system("cls");
				std::cout << "Na ile osob rezerwowac stolik? \n";
				stoliki.wyswietl_stoliki();
				std::cout << "\n\nTwoj wybor: ";
				std::cin >> chetni;
				int poz=stoliki.szukaj_stolika(chetni);
				Kucharz* kucharz= dynamic_cast<Kucharz*>(kuchnia.znajdz_wolnego_kucharza());
				Kelner* kelner= dynamic_cast<Kelner*>(kuchnia.znajdz_wolnego_kelnera());
				Zamowienie* zamowienie = new Zamowienie(&menu, stoliki.dostep_stoliki()[poz]);
				zamowienie->dopisz(kucharz);
				zamowienie->dopisz(kelner);
				zamowienie->dopisz(&zrealizowane);
				kuchnia.pokaz_sklad_kuchni();
				zamowienie->zloz_zamowienie();
				stoliki.zwolnij_stolik(poz);
				zamowienie->wypisz(kucharz);
				zamowienie->wypisz(kelner);
				zamowienie->wypisz(&zrealizowane);
				delete zamowienie;
				break;
			}
			case 's':
			{
				system("cls");
				zrealizowane.pokaz_statystyki();
				break;
			}		
			default:
			{
				system("cls");
				std::cout << "Dziekujemy za skorzystanie z uslugi!!\n";
				return 0;
			
			}		
		}
	}

}