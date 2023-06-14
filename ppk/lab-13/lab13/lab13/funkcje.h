#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>

void testy();
void wypisz_polaczana(std::vector<std::list<int>> graf);
std::vector<std::list<int>> wczytaj_graf(std::string nazwa_pliku);