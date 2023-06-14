#include <iostream>
#include "funkcje.h"
#include <stdio.h>
#include <string>
#include <vector>

int main()
{
	wektor w1{ 1,3 };
	wektor w2{ 3,4 };
	wektor w3;

	//zad2
	std::cout << "\nZad 2\n";
	w3 = dodaj_wektory(w1, w2);
	std::cout << "x3=" << w3.x << std::endl;
	std::cout << "y3=" << w3.y << std::endl;

	//zad3
	std::cout << "\n\nZad 3\n";
	w3= odejmij_wektory(w1, w2);
	std::cout << "x3=" << w3.x << std::endl;
	std::cout << "y3=" << w3.y << std::endl;

	//zad4
	std::cout << "\n\nZad 4\n";
	std:: cout << dlugosc_wektorow(w1, w2);

	//zad5
	int k = 3;
	std::cout << "\n\nZad 5\n";
	w3 = skaluj_wektor(w1, k);
	std::cout << w3.x << " " << w3.y << std::endl;

	//zad6
	std::cout << "\n\nZad 6\n";
	std::cout << "Iloczyn skalarny: " <<iloczyn_skalarny(w1,w1)<< std::endl;

	//zad8-10
	std::cout << "\n\nZad 8-10\n";
	car v1;

	
	v1._kolo[0]._typ_kola = typ_kola::zimowa;
	v1._kolo[1]._typ_kola = typ_kola::letnia;
	v1._kolo[2]._typ_kola = typ_kola::letnia;
	v1._kolo[3]._typ_kola = typ_kola::letnia;


	SetType(v1, typ_kola::zimowa);
	for (int i = 0;i < 4;i++)
	{
		std::cout << "kolo " << i << ": " << v1._kolo[i]._typ_kola << std::endl;
	}
	CheckCar(v1)? std::cout << "Te same typy kol\n":std::cout << "Rozne typy kol\n";

	//zad11-14
	std::cout << "\n\nZad 11-14\n";
	date data {2000, 10, 15 };
	date data2  {2000, 2, 30 };

	czy_przestepny(data)? std::cout << "Jest przestepny\n": std::cout << "Nie jest przestepny\n" ;

	porownaj_daty(data, data2);

	czy_prawidlowa_data(data2)? std::cout << "Prawidlowa data\n" : std::cout << "Nieprawidlowa data\n";

	//zad15-16
	std::cout << "\n\nZad 15-16\n";
	okrag o1{ 3,5,6 };
	okrag o2{ 4,3,7 };
	switch (funkcja_okregi(o1,o2))
	{
	case(styczne_zewn): std::cout << "Styczne zewn\n";
		break;
	case(styczne_wewn): std::cout << "Styczne wewn\n";
		break;
	case(rozlaczne_zewn): std::cout << "Rozlaczne zewn\n";
		break;
	case(rozlaczne_wewn): std::cout << "Rozlaczne wewn\n";
		break;
	case(wspolsrodkowe): std::cout << "Wspolsrodkowe\n";
		break;
	case(przecinajace): std::cout << "Przecinajace\n";
		break;
	}

	// czêœæ 2 - string

	//zad17-23
	std::cout << "\n\nZad 17-23\n";
	Osoby peop;
	Osoba os1 {"Antek", 5 };
	
	Dodaj_osobe(peop, "Franek", 6);
	Dodaj_osobe(peop, "Adam", 7);
	Dodaj_osobe(peop, "Adas", 12);
	Dodaj_osobe(peop, "Adam", 9);

	wypisz_osoby(peop);


	wypisz_znalezione(peop, znajdz(peop, "Adam"));
	wypisz_znalezione(peop, znajdz_po_wieku(peop, 5,9));

	//zad wektory najbardziej oddalone
	std::cout << "\n\nZad poprzednie z plikmi\n";
	std::string nazwa_pliku_do_wektorow = "zadwekt.txt";
	zapis_do_pliku_wektory(5, nazwa_pliku_do_wektorow);
	std::pair<wektor, wektor> para_wekt=oddalone_wektory(nazwa_pliku_do_wektorow);
	std::cout << "Wek1 x: " << para_wekt.first.x << ", y: " << para_wekt.first.y << "\n";
	std::cout << "Wek2 x: " << para_wekt.second.x << ", y: " << para_wekt.second.y << "\n";
}


	