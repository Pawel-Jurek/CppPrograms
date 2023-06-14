/** @file */
#pragma once

#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include <unordered_map>
#include <map>

/** Struktura zawieraj¹ca dane wejœciowe */
struct Params
{
	std::string flaga_dzialania; /**< flaga mówi¹ca o operacji, któr¹ bêdziemy wykonywaæ (szyfrowanie, deszyfrowanie, ³amanie kodu) */
	std::string inputFile; /**< nazwa pliku wejœciowego */
	std::string kluczFile; /**< nazwa pliku zawieraj¹cego klucz */
	std::string outputFile; /**< nazwa pliku wyjœciowego */
};

/** Funkcja zczytuj¹ca parametry do programu i zapisuj¹ca je do struktury
* @param argc wartoœci parametrów z którymi zosta³ wywo³any program
* @param argv tablica tych wartoœci
* @param params struktura do której zapisywane s¹ parametry
* @return funkcja zwraca true, je¿eli program zosta³ wywo³any z odpowiednimi parametrami. W przeciwnym razie zwraca false
*/
bool czytaj_Parametry(int argc, char** argv, Params& params);

/** Funkcja wyœwietla okno pomocy, gdy czytaj_Parametry zwróci false
* @param progName nazwa programu
*/
void pomoc(const std::string& progName);

/** Funkcja szyfruje znak tekstu kolejnym znakiem klucza i jeœli znak da³o siê zaszyfrowaæ (tzn. a-z, A-Z), to przypisuje go wartoœci orygina³u
* @param znak_tekstu kolejny znak tekstu do zaszyfrowania
* @param klucz klucz którym szyfrujemy
* @param licznik_klucza kolejny znak klucza, a gdy dojdziemy do jego koñca, bierze siê go od pocz¹tku
*/
void szyfrowanie_znaku(char &znak_tekstu, const std::string &klucz, int& licznik_klucza);

/** Funkcja deszyfruje znak tekstu kolejnym znakiem klucza i jeœli znak da³o siê zdeszyfrowaæ (tzn. a-z, A-z), to przypisuje go wartoœci orygina³u
* @param klucz klucz którym deszyfrujemy
* @param znak_tekstu kolejny znak tekstu do zdeszyfrowania
* @param licznik_klucza kolejny znak klucza, a gdy dojdziemy do jego koñca, bierze siê go od pocz¹tku
*/
void deszyfrowanie_znaku(std::string klucz, char& znak_tekstu, int& licznik_klucza);

/** G³ówna funkcja szyfruj¹ca 
* @param params parametry wejsciowe
* @return funkcja zwraca zaszyfrowany tekst
*/
std::string szyfrowanie(const Params& params);

/** Funkcja wczytuje plik o nazwie z parametrów wejsciowych
* @param params parametry wejsciowe
* @return funkcja zwraca tekst z tego pliku
*/
std::string wczytaj_plik(std::string nazwa_pliku);

/** G³ówna funkcja deszyfruj¹ca
* @param params parametry wejsciowe
* @return funkcja zwraca odszyfrowany tekst
*/
std::string deszyfrowanie(Params &params);

/** Funkcja wyznacza trzyliterowe ci¹gi
* @param tekst tekst, który bêdziemy analizowaæ
* @return funkcja zwraca te ci¹gi
*/
std::vector<std::string> wyznaczanie_ciagow(std::string &tekst);

/** Funkcja wyznacza nwd rekurencyjnie dwóch liczb metod¹ euklidesa
* @param a pierwsza liczba
* @param b druga liczba
* @return funkcja zwraca nwd tych dwóch liczb
*/
int NWD(int a, int b);

/** Funkcja wyznacza statystecznie najwiêksz¹ liczbê, dla której iloœæ powsta³ych nwd jest najwiêksza
* @param liczby wyniki operacji nwd dla wszystkich ci¹gów
* @return funkcja zwraca jedno statystycznie najczêstsze i najwiêksze nwd 
*/
int NWDv2(std::vector<int>& liczby);

/** Funkcja wyznacza d³ugoœæ klucza na podstawie najwiêkszej iloœci powtórzeñ nwd dla danego u³o¿enia ró¿nic odleg³oœci miedzy powtarzaj¹cymi siê ci¹gami, oraz zmienia t¹ kolejnoœæ dla dok³adniejszego wyniku
* @param ciagi 3 literowe ci¹gi u³o¿one z kolejnych liter zaszyfrowanego tekstu
* @return funkcja zwraca d³ugoœæ klucza
*/
int wyznaczanie_dlugosci_klucza(std::vector<std::string>&ciagi);

/** Funkcja wyznacza tekst sk³adaj¹cy siê z samych znaków A-Z. Du¿e litery zostawia, ma³e litery zamienia na du¿e, a resztê znaków pomija
* @param tekst tekst do przefiltrowania
* @return funkcja zwraca przefiltrowany tekst
*/
std::string filtrowanie_tekstu(std::string tekst);

/** G³ówna funkcja do ³amania szyfru 
* @param params parametry wejsciowe
* @return funkcja zwraca odszyfrowany tekst
*/
std::string lamanie_kodu(Params &params);

/** G³ówna funkcja steruj¹ca. Decyduje, któr¹ z operacji bêdziemy wykonywaæ na podstawie parametrów wejœciowych
* @param params parametry wejœciowe
* @return funkcja zwraca true jeœli by³a odpowiednia flaga dzia³ania i uda³o siê wejœæ do odpowiedniego segmentu funkcji zwi¹zanego z t¹ flag¹. W przeciwnym razie zwraca false
*/
bool decyzjator( Params& params);

/** Funkcja wyznacza ró¿nice miêdzy pierwszym i ka¿dym kolejnym wyst¹pieniem poszczególnego 3-literowego ci¹gu
* @param slowa mapa tych 3-literowych ci¹gów (<ci¹g>, <pozycje wyst¹pienia>)
* @return funkcja zwraca ró¿nice pomiêdzy pierwszym i ka¿dym kolejnym wyst¹pieniem poszczególnego 3-literowego ci¹gu
*/
std::vector<int>wyznaczanie_roznic(std::unordered_map<std::string, std::vector<int>> &slowa);

/** Funkcja wyznacza klucz na podstawie jego d³ugoœci. Sprawdza co n-t¹ literê (n-d³ugoœæ klucza) i wyznacza najczêœciej powtarzaj¹c¹ siê. W jêzyku polskim jest to "a", wiêc na tej podstawie obliczamy przesuniêcie
* @param tekst tekst g³owny z którego zczytujemy litery
* @param dlugosc_klucza d³ugoœæ klucza
* @return funkcja zwraca klucz
*/
std::string wyznaczanie_klucza(std::string &tekst, int dlugosc_klucza);

/** Funkcja wyznacza literê klucza na podstawie co n-tej litery (n-d³ugoœæ klucza) i wyznacza najczêœciej powtarzaj¹c¹ siê. W jêzyku polskim jest to "a", wiêc na tej podstawie obliczamy przesuniêcie
* @param tekst tekst g³owny z którego zczytujemy litery
* @param dlugosc_klucza d³ugoœæ klucza
* @param poz_klucza zmienna opisuj¹ca którego znaku klucza szukamy, co któr¹ literê wczytujemy
* @return funkcja zwraca literê klucza
*/
char wyznacz_znak_klucza(std::string &tekst, int dlugosc_klucza, int poz_klucza);

/** Funkcja porównuj¹ca pary na podstawie wartoœci
* @param a
* @param b
* @return funkcja zwraca true jeœli a.second > b.second, w przeciwnym razie false
*/
bool komparator_wartosci(const std::pair<int, int>& a, const std::pair<int, int>& b);

/** Funkcja porównuj¹ca pary na podstawie klucza
* @param a
* @param b
* @return funkcja zwraca true jeœli a.first > b.first, w przeciwnym razie false
*/
bool komparator_klucza(const std::pair<int, int>& a, const std::pair<int, int>& b);

/** Funkcja zamienia mapê na wektor i sortuje go
* @param mapa mapa do posortowania
* @return funkcja zwraca posortowanego wektora, utworzonego z mapy
*/
std::vector<std::pair<int, int>>sortuj(std::map<int, int> &mapa);