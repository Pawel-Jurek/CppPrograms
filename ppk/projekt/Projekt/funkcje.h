/** @file */
#pragma once

#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include <unordered_map>
#include <map>

/** Struktura zawieraj�ca dane wej�ciowe */
struct Params
{
	std::string flaga_dzialania; /**< flaga m�wi�ca o operacji, kt�r� b�dziemy wykonywa� (szyfrowanie, deszyfrowanie, �amanie kodu) */
	std::string inputFile; /**< nazwa pliku wej�ciowego */
	std::string kluczFile; /**< nazwa pliku zawieraj�cego klucz */
	std::string outputFile; /**< nazwa pliku wyj�ciowego */
};

/** Funkcja zczytuj�ca parametry do programu i zapisuj�ca je do struktury
* @param argc warto�ci parametr�w z kt�rymi zosta� wywo�any program
* @param argv tablica tych warto�ci
* @param params struktura do kt�rej zapisywane s� parametry
* @return funkcja zwraca true, je�eli program zosta� wywo�any z odpowiednimi parametrami. W przeciwnym razie zwraca false
*/
bool czytaj_Parametry(int argc, char** argv, Params& params);

/** Funkcja wy�wietla okno pomocy, gdy czytaj_Parametry zwr�ci false
* @param progName nazwa programu
*/
void pomoc(const std::string& progName);

/** Funkcja szyfruje znak tekstu kolejnym znakiem klucza i je�li znak da�o si� zaszyfrowa� (tzn. a-z, A-Z), to przypisuje go warto�ci orygina�u
* @param znak_tekstu kolejny znak tekstu do zaszyfrowania
* @param klucz klucz kt�rym szyfrujemy
* @param licznik_klucza kolejny znak klucza, a gdy dojdziemy do jego ko�ca, bierze si� go od pocz�tku
*/
void szyfrowanie_znaku(char &znak_tekstu, const std::string &klucz, int& licznik_klucza);

/** Funkcja deszyfruje znak tekstu kolejnym znakiem klucza i je�li znak da�o si� zdeszyfrowa� (tzn. a-z, A-z), to przypisuje go warto�ci orygina�u
* @param klucz klucz kt�rym deszyfrujemy
* @param znak_tekstu kolejny znak tekstu do zdeszyfrowania
* @param licznik_klucza kolejny znak klucza, a gdy dojdziemy do jego ko�ca, bierze si� go od pocz�tku
*/
void deszyfrowanie_znaku(std::string klucz, char& znak_tekstu, int& licznik_klucza);

/** G��wna funkcja szyfruj�ca 
* @param params parametry wejsciowe
* @return funkcja zwraca zaszyfrowany tekst
*/
std::string szyfrowanie(const Params& params);

/** Funkcja wczytuje plik o nazwie z parametr�w wejsciowych
* @param params parametry wejsciowe
* @return funkcja zwraca tekst z tego pliku
*/
std::string wczytaj_plik(std::string nazwa_pliku);

/** G��wna funkcja deszyfruj�ca
* @param params parametry wejsciowe
* @return funkcja zwraca odszyfrowany tekst
*/
std::string deszyfrowanie(Params &params);

/** Funkcja wyznacza trzyliterowe ci�gi
* @param tekst tekst, kt�ry b�dziemy analizowa�
* @return funkcja zwraca te ci�gi
*/
std::vector<std::string> wyznaczanie_ciagow(std::string &tekst);

/** Funkcja wyznacza nwd rekurencyjnie dw�ch liczb metod� euklidesa
* @param a pierwsza liczba
* @param b druga liczba
* @return funkcja zwraca nwd tych dw�ch liczb
*/
int NWD(int a, int b);

/** Funkcja wyznacza statystecznie najwi�ksz� liczb�, dla kt�rej ilo�� powsta�ych nwd jest najwi�ksza
* @param liczby wyniki operacji nwd dla wszystkich ci�g�w
* @return funkcja zwraca jedno statystycznie najcz�stsze i najwi�ksze nwd 
*/
int NWDv2(std::vector<int>& liczby);

/** Funkcja wyznacza d�ugo�� klucza na podstawie najwi�kszej ilo�ci powt�rze� nwd dla danego u�o�enia r�nic odleg�o�ci miedzy powtarzaj�cymi si� ci�gami, oraz zmienia t� kolejno�� dla dok�adniejszego wyniku
* @param ciagi 3 literowe ci�gi u�o�one z kolejnych liter zaszyfrowanego tekstu
* @return funkcja zwraca d�ugo�� klucza
*/
int wyznaczanie_dlugosci_klucza(std::vector<std::string>&ciagi);

/** Funkcja wyznacza tekst sk�adaj�cy si� z samych znak�w A-Z. Du�e litery zostawia, ma�e litery zamienia na du�e, a reszt� znak�w pomija
* @param tekst tekst do przefiltrowania
* @return funkcja zwraca przefiltrowany tekst
*/
std::string filtrowanie_tekstu(std::string tekst);

/** G��wna funkcja do �amania szyfru 
* @param params parametry wejsciowe
* @return funkcja zwraca odszyfrowany tekst
*/
std::string lamanie_kodu(Params &params);

/** G��wna funkcja steruj�ca. Decyduje, kt�r� z operacji b�dziemy wykonywa� na podstawie parametr�w wej�ciowych
* @param params parametry wej�ciowe
* @return funkcja zwraca true je�li by�a odpowiednia flaga dzia�ania i uda�o si� wej�� do odpowiedniego segmentu funkcji zwi�zanego z t� flag�. W przeciwnym razie zwraca false
*/
bool decyzjator( Params& params);

/** Funkcja wyznacza r�nice mi�dzy pierwszym i ka�dym kolejnym wyst�pieniem poszczeg�lnego 3-literowego ci�gu
* @param slowa mapa tych 3-literowych ci�g�w (<ci�g>, <pozycje wyst�pienia>)
* @return funkcja zwraca r�nice pomi�dzy pierwszym i ka�dym kolejnym wyst�pieniem poszczeg�lnego 3-literowego ci�gu
*/
std::vector<int>wyznaczanie_roznic(std::unordered_map<std::string, std::vector<int>> &slowa);

/** Funkcja wyznacza klucz na podstawie jego d�ugo�ci. Sprawdza co n-t� liter� (n-d�ugo�� klucza) i wyznacza najcz�ciej powtarzaj�c� si�. W j�zyku polskim jest to "a", wi�c na tej podstawie obliczamy przesuni�cie
* @param tekst tekst g�owny z kt�rego zczytujemy litery
* @param dlugosc_klucza d�ugo�� klucza
* @return funkcja zwraca klucz
*/
std::string wyznaczanie_klucza(std::string &tekst, int dlugosc_klucza);

/** Funkcja wyznacza liter� klucza na podstawie co n-tej litery (n-d�ugo�� klucza) i wyznacza najcz�ciej powtarzaj�c� si�. W j�zyku polskim jest to "a", wi�c na tej podstawie obliczamy przesuni�cie
* @param tekst tekst g�owny z kt�rego zczytujemy litery
* @param dlugosc_klucza d�ugo�� klucza
* @param poz_klucza zmienna opisuj�ca kt�rego znaku klucza szukamy, co kt�r� liter� wczytujemy
* @return funkcja zwraca liter� klucza
*/
char wyznacz_znak_klucza(std::string &tekst, int dlugosc_klucza, int poz_klucza);

/** Funkcja por�wnuj�ca pary na podstawie warto�ci
* @param a
* @param b
* @return funkcja zwraca true je�li a.second > b.second, w przeciwnym razie false
*/
bool komparator_wartosci(const std::pair<int, int>& a, const std::pair<int, int>& b);

/** Funkcja por�wnuj�ca pary na podstawie klucza
* @param a
* @param b
* @return funkcja zwraca true je�li a.first > b.first, w przeciwnym razie false
*/
bool komparator_klucza(const std::pair<int, int>& a, const std::pair<int, int>& b);

/** Funkcja zamienia map� na wektor i sortuje go
* @param mapa mapa do posortowania
* @return funkcja zwraca posortowanego wektora, utworzonego z mapy
*/
std::vector<std::pair<int, int>>sortuj(std::map<int, int> &mapa);