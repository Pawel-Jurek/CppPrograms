#include <fstream>
#include <iostream>
#include <string>
#include "funkcje.h"
#include <list>
#include <vector>

std::vector<std::list<int>> wczytaj_graf(std::string nazwa_pliku)
{
	std::ifstream plik;
	plik.open(nazwa_pliku);
	std::vector<std::list<int>>graf;
	graf.resize(0);
	int a;
	int b;
	while (plik>>a>>b)
	{
		if (graf.size() <= a)
		{
			graf.resize(a+1);
		}
		graf[a].push_back(b);
		if (graf.size() <= b)
		{
			graf.resize(b + 1);
		}
		graf[b].push_back(a);
		std::cout << "\n";
	}
	return graf;
}
void wypisz_polaczana(std::vector<std::list<int>> graf)
{
	for (int i=0;i<graf.size();i++)
	{
		for (auto const& j : graf[i]) {
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
}

void testy()
{
	std::vector<int>a;
	std::vector<std::list<int>>b;
	
	a.resize(6);
	a.push_back(2);
	a.resize(10);
	a.push_back(2);
	//a.resize(2);
	//a.push_back(2);
	for (auto z : a)
	{
		std::cout << z << " ";
	}
	std::cout << "\n";
	a.resize(0);
	a.push_back(2);
	b.resize(1);
	b[0].push_back(3);
	b.resize(2);
	b[1].push_back(2);
	//b.resize(0);
	b[0].push_back(3);
	wypisz_polaczana(b);

}