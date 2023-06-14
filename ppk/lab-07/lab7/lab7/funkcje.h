#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>

int rand_int(int low , int high);
bool zapis_do_pliku1(std::string nazwa_pliku, int n, int p, int k);

struct wyniki
{
	int ilosc;
	double srednia_liczb, odchylenie_standardowe_liczb;
};

wyniki results(std::string nazwa_pliku);
double odchylenie_standardowe(std::vector<double> spis);
double srednia(std::vector<double> spis);

void tabliczka_mnozenia(std::string nazwa_pliku, int n);

void histogram(std::string nazwa_pliku);
std::string zrob_gwiazdki(std::vector<int>ilosc_wystapien, int litera, int maks_wyst);
void wypisz_wyniki(std::vector<int>ilosc_wystapien);
void narysuj_wyniki(std::vector<int>ilosc_wystapien);