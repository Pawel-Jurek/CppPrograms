#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>  

void wyswietl_wek(std::vector<int> wektor);
std::vector<int>::iterator znajdz_w_wekt(std::vector<int>& wektor, int wartosc);
std::vector<std::vector<double>> wczytaj_macierz(std::string nazwa_pliku);
void wypisz_macierz(std::vector<std::vector<double>> macierz);
std::vector<std::vector<double>> dodaj_macierze(std::vector<std::vector<double>>macierz1, std::vector<std::vector<double>>macierz2);
void zapis_do_pliku(std::vector<std::vector<double>> const& macierz, std::string const& nazwa_pliku);

struct Osoba
{
	std::string imie;
	int wiek;
};
void dodaj_osobe(std::vector<Osoba>& osoby);

void sortuj_leksy(std::vector<Osoba>& osoby);
void sortuj_odwro_leksy(std::vector<Osoba>& osoby);
void wypisz_os(std::vector<Osoba> const& osoby);
bool porownaj_imiona(Osoba os1, Osoba os2);
bool porownaj_wieki(Osoba os1, Osoba os2);
void sortuj_wiek_rosn(std::vector<Osoba>& osoby);
void sortuj_wiek_mal(std::vector<Osoba>& osoby);
bool porownaj_imiona2(Osoba os1, Osoba os2);
void sortuj_imie_wiek(std::vector<Osoba>& osoby);