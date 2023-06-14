#include <iostream>
#include "funkcje.h"

int main()
{

	Przycisk przycisk(1, 1, 5, 3, "Przycisk");
	//Pole_tekstowe pole(3, 5, 6,2,3, "Ala ma kota");
	Pole_tekstowe pole(1, 2, 3, 4, 100, "Pawel");
	Okno okno(10, 5, 4, 5, "T", &przycisk, &pole);
	Pola_hasla haslo(3, 4, 5, 4, 15, "Ala ma kota");
	Combo combo();
	std::cout << "\n\nWywo³anie okna->rysuj\n";
	Komponent* wsk;
	wsk = &okno;
	wsk->rysuj();
	std::cout << "\n\n" << haslo.pobierz_tresc_pola_tekstowego() << "\n\n";
	okno.dopasuj_okno();
	okno.rysuj();
}