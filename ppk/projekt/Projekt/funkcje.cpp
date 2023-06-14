/** @file */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "funkcje.h"
#include <map>
#include <unordered_map>
#include <cctype>
#include <algorithm>


bool czytaj_Parametry(int argc, char** argv, Params& params)
{
	bool deflag = false;
	bool brflag = false;
	bool enflag = false;
	for (int i = 1; i < argc - 1; ++i)
	{
		std::string cur = argv[i];
		if (cur == "--en")
		{
			enflag = true;
			break;
		}
		if (cur == "--de")
		{
			deflag = true;
			break;
		}
		if (cur == "--br")
		{
			brflag = true;
			break;
		}
	}
		
	if (enflag)
	{
		params.flaga_dzialania = "en";
		for (int i = 1; i < argc - 1; ++i)
		{
			std::string cur = argv[i];
			if (cur == "-i")
				params.inputFile = argv[++i];
			if (cur == "-o")
				params.outputFile = argv[++i];
			if (cur == "-k")
				params.kluczFile = argv[++i];
		}
		return (params.inputFile != "" && params.outputFile != "" && params.kluczFile != "");
	}
	else if (deflag)
	{
		params.flaga_dzialania = "de";
		for (int i = 1; i < argc - 1; ++i)
		{
			std::string cur = argv[i];
			if (cur == "-i")
				params.inputFile = argv[++i];
			if (cur == "-o")
				params.outputFile = argv[++i];
			if (cur == "-k")
				params.kluczFile = argv[++i];
		}
		return (params.inputFile != "" && params.outputFile != "" && params.kluczFile != "");
	}

	else if (brflag)
	{
		params.flaga_dzialania = "br";
		for (int i = 1; i < argc - 1; ++i)
		{
			std::string cur = argv[i];
			if (cur == "-i")
				params.inputFile = argv[++i];
			if (cur == "-o")
				params.outputFile = argv[++i];
		}
		return (params.inputFile != "" && params.outputFile != "");
	}	
	return false;
	
}
void pomoc(const std::string& progName)
{
	std::cerr << "Witaj w programie Szyfr Vinegera\n";
	std::cerr << "Uzywa sie go tak:\n";
	std::cerr << progName << " --en / --de / --br (szyfrowanie / deszyfrowanie / lamanie kodu(bez klucza))\n";
	std::cerr << progName << " -i <inputFile>\n";
	std::cerr << progName << " -o <outputFile>\n";
	std::cerr << progName << " -k <klucz>\n";
}


void szyfrowanie_znaku(char &znak_tekstu, const std::string& klucz, int& licznik_klucza)
{
	int poz_litery_kolumna = 0;
	int poz_litery_wiersz = 0;
	if (znak_tekstu >= 'a' && znak_tekstu <= 'z')
	{
		znak_tekstu = std::toupper(znak_tekstu);
	}
	if (znak_tekstu >= 'A' && znak_tekstu <= 'Z')
	{
		poz_litery_kolumna = znak_tekstu - 'A';
		poz_litery_wiersz = klucz[(licznik_klucza++) % klucz.size()] - 'A';
		znak_tekstu= char((poz_litery_kolumna + poz_litery_wiersz) % 26 + 'A');
	}
}


void deszyfrowanie_znaku(std::string klucz, char &znak_tekstu, int& licznik_klucza)
{
	if (znak_tekstu >= 'a' && znak_tekstu <= 'z')
	{
		znak_tekstu = std::toupper(znak_tekstu);
	}
	if (znak_tekstu >= 'A' && znak_tekstu <= 'Z')
	{
		char znak_klucza = klucz[(licznik_klucza++) % klucz.size()];
		znak_tekstu= (char)((((int)znak_tekstu - 'A' - (znak_klucza - 'A')) + 26) % 26) + 'A';
	}
	
}

std::string szyfrowanie(const Params& params)
{
	std::string tekst = wczytaj_plik(params.inputFile);
	const std::string klucz = wczytaj_plik(params.kluczFile);	
	long int rozmiar_tekstu = tekst.size();
	std::string zaszyfrowane = "";
	int licznik = 0;
	for (int i = 0;i < rozmiar_tekstu;i++)
	{
		szyfrowanie_znaku(tekst[i], klucz, licznik);
	}
	return tekst;
}

std::string wczytaj_plik(std::string nazwa_pliku)
{
	std::ifstream plikwej(nazwa_pliku);
	if (!plikwej)
	{
		std::cerr << "Error: nie mozna otworzyc pliku :( " << nazwa_pliku << "\n";
		return "";
	}
	std::string tekst="";
	std::string linia;
	while (std::getline(plikwej, linia))
		if (linia != "")
		{
			tekst += linia + " ";
		}

	tekst.erase(tekst.size() - 1);	//usuniecie niepotrzebnej spacji na koncu tekstu
	plikwej.close();
	return tekst;
}

std::string deszyfrowanie(Params &params)
{
	std::string tekst = wczytaj_plik(params.inputFile);
	std::string klucz = wczytaj_plik(params.kluczFile);
	
	long int rozmiar_tekstu = tekst.size();
	long int rozmiar_klucza = klucz.size();
	
	int licznik = 0;
	std::string odszyfrowane = "";
	for (int i = 0;i < rozmiar_tekstu;i++)
	{
		deszyfrowanie_znaku(klucz, tekst[i], licznik);
	}
	return tekst;
}

std::vector<std::string> wyznaczanie_ciagow(std::string& tekst)
{
	std::vector<std::string>ciagi;
	int rozmiar_tekstu = tekst.size();
	std::string ciag="";
	for (int i = 0;i < rozmiar_tekstu - 2;i++)
	{
		ciag += tekst[i];
		ciag += tekst[i + 1];
		ciag += tekst[i + 2];
		
		ciagi.push_back(ciag);
		ciag = "";
	}
	return ciagi;
}

int NWD(int a, int b)
{
	if (b != 0)
		return NWD(b, a % b);

	return a;
}

bool komparator_klucza(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return (a.first > b.first);
}
bool komparator_wartosci(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return (a.second > b.second);
}
std::vector<std::pair<int, int>>sortuj(std::map<int,int>&mapa)
{
	std::vector<std::pair<int, int>> vec;
	
	std::map<int, int> ::iterator it;
	for (it = mapa.begin(); it != mapa.end(); it++)
	{
		vec.push_back(std::make_pair(it->first, it->second));
	}
	
	sort(vec.begin(), vec.end(), komparator_klucza);
	sort(vec.begin(), vec.end(), komparator_wartosci);
	

	return vec;
}

int NWDv2(std::vector<int> &liczby)
{
	int temp;
	int nwd=liczby[0];
	std::map <int, int>ilosc_nwd;
	for (int i = 0;i < liczby.size()-1;i++)
	{
		temp = nwd;
		if ((NWD(liczby[i], liczby[i + 1])) != 1)
			nwd = (NWD(liczby[i], liczby[i + 1]));
		else
			nwd = temp;
		ilosc_nwd[nwd]++;
	}

	auto posortowane = sortuj(ilosc_nwd);
	posortowane.erase(posortowane.begin()+1, posortowane.end());
	int maks = 0;
	for (auto wpis : posortowane)
	{
		if (wpis.first > maks)
			maks = wpis.first;
	}
	return maks;
}


std::vector<int>wyznaczanie_roznic(std::unordered_map<std::string, std::vector<int>>& slowa)
{
	std::vector<int>liczby;
	std::vector<int>roznice;
	for (auto wpis : slowa)
	{
		if (wpis.second.size() > 1)
		{
			for (auto n : wpis.second)
			{
				liczby.push_back(n);
			}

			for (int k = 1;k < liczby.size();k++)
			{
				roznice.push_back(liczby[k] - liczby[0]);
			}
			liczby.clear();
			
		}
	}
	return roznice;
}

int wyznaczanie_dlugosci_klucza(std::vector<std::string>&ciagi)
{
	int rozmiar_ciagu=ciagi.size();
	std::string slowo;
	std::vector<int>odleglosci;
	
	std::unordered_map<std::string, std::vector<int>>  slowa;  
	for (int i = 0;i < rozmiar_ciagu;i++)
	{
		slowa[ciagi[i]].push_back(i);	
	}
	std::vector<int>liczby;
	std::vector<int>roznice=wyznaczanie_roznic(slowa);
	std::cout << "\n";
	int nwd = 0;
	std::unordered_map<int, int> statystycznie_nwd;

	for (int i = 0;i < roznice.size();i++)
	{
		statystycznie_nwd[NWDv2(roznice)]++;
		roznice.insert(roznice.begin(),roznice[roznice.size()-1]);
		roznice.erase(roznice.end()-1);		
	}
	
	int maks = 0;
	std::vector<int>maksy;
	std::vector<int>liczby2;
	for (auto wpis : statystycznie_nwd)
	{
		
		if (wpis.second >= statystycznie_nwd.size()/4)
		{
			maksy.push_back(wpis.second);
			liczby2.push_back(wpis.first);
		}
	}
	nwd= *max_element(liczby2.begin(), liczby2.end());
	
	return nwd;
}

std::string filtrowanie_tekstu(std::string tekst)
{
	std::string tekst_wyjscowy;
	for (int i = 0;i < tekst.size();i++)
	{
		if (tekst[i] >= 97 && tekst[i]<= 122)
		{
			tekst[i] = std::toupper(tekst[i]);
		}
		if (tekst[i] >= 65 && tekst[i] <= 90)
		{
			tekst_wyjscowy += tekst[i];
		}
	}
	return tekst_wyjscowy;
}


char wyznacz_znak_klucza(std::string &tekst, int dlugosc_klucza,int poz_klucza)
{
	int licznik_liter = 0;
	std::map<char, double>  frekwencja;
	std::unordered_map<char, int>  litery;
	for (int j = poz_klucza;j < tekst.size();j += dlugosc_klucza) 
	{
		litery[tekst[j]]++;
		licznik_liter++;
	}
	std::vector<std::pair<char, double>> temp;
	for (int j = poz_klucza;j < tekst.size();j += dlugosc_klucza)
	{
		frekwencja[tekst[j]] = 1.0 * litery[tekst[j]] / licznik_liter;
	}
	int k = 0;
	
	double maks = 0;
	char litera;
	for (auto &wpis : frekwencja)
	{	
		if (wpis.second > maks)
		{
			maks = wpis.second;
			litera = wpis.first;
		}
		k++;
	}
	
	auto it = frekwencja.find(litera);

	return it->first;
}

std::string wyznaczanie_klucza(std::string &tekst, int dlugosc_klucza)
{
	
	std::string klucz="";
	for (int i = 0;i < dlugosc_klucza;i++)
	{
		klucz+= wyznacz_znak_klucza(tekst, dlugosc_klucza, i);
	}
	
	return klucz;
}

std::string lamanie_kodu(Params &params)
{
	std::string tekst = wczytaj_plik(params.inputFile);
	std::string tekst_przefiltrowany=filtrowanie_tekstu(tekst);
	
	long int rozmiar_tekstu = tekst.size();
	std::vector<std::string>ciagi=wyznaczanie_ciagow(tekst_przefiltrowany);
	int dlugosc_klucza=wyznaczanie_dlugosci_klucza(ciagi);
	std::string klucz=wyznaczanie_klucza(tekst_przefiltrowany, dlugosc_klucza);
	
	params.kluczFile = "klucz2.txt";
	std::ofstream klucz_plik(params.kluczFile);
	klucz_plik << klucz;
	klucz_plik.close();
	return deszyfrowanie(params);
}

bool decyzjator(Params& params)
{
	std::ofstream plikwyj(params.outputFile);
	if (params.flaga_dzialania == "en")
	{
		plikwyj << szyfrowanie(params);
		plikwyj.close();
		return true;
	}
	else if (params.flaga_dzialania == "de")
	{
		plikwyj << deszyfrowanie(params);
		plikwyj.close();
		return true;
	}
	else if (params.flaga_dzialania == "br")
	{
		plikwyj << lamanie_kodu(params);
		plikwyj.close();
		return true;
	}
	else
		return false;
}