#include <iostream>
#include <string>
#include <fstream>
#include "funkcje.h"

void testy()
{
	std::cout << "filtrowanie_tekstu: ";
	if (filtrowanie_tekstu("Ala ma Kota!.12") == "ALAMAKOTA")
		std::cout << "okej";
	else
		std::cout << "blad";
}