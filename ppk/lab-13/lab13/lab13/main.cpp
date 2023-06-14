#include <iostream>
#include "funkcje.h"
#include <vector>


int main()
{
	auto graf=wczytaj_graf("plik.txt");
	wypisz_polaczana(graf);
	//std::vector<int>a;
	//testy();
}