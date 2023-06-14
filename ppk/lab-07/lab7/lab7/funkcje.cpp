#include <iostream>
#include <cmath>
#include "funkcje.h"
#include <string>
#include <fstream>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <vector>

int rand_int(int low = 0, int high = 99)
{
    static std::default_random_engine re{ std::random_device{}() };
    using Dist = std::uniform_int_distribution<int>;
    static Dist uid{};
    return uid(re, Dist::param_type{ low,high });
}

bool zapis_do_pliku1(std::string nazwa_pliku, int n, int p, int k)
{
    std::ofstream plik(nazwa_pliku);
    for (int i = 0; i < n; i++)
    {
        plik << rand_int(p, k)<<"\n";
        if (i == n - 1)
        {
            plik.close();
            return true;
        }
    }
    return false;
    plik.close();
}
double srednia(std::vector<double> spis)
{
    double suma=0;
    for (int i = 0; i < spis.size(); i++)
    {
        suma += spis[i];
    }
    return suma / spis.size();
}
double odchylenie_standardowe(std::vector<double> spis)
{
    double licznik = 0;
    for (int i = 0; i < spis.size(); i++)
    {
        licznik += pow((srednia(spis) - spis[i]), 2);
    }
    return sqrt(licznik / spis.size());
}
wyniki results(std::string nazwa_pliku) 
{
    wyniki w;
    std::ifstream plik(nazwa_pliku);
    double liczba;
    int k = 0;
    std::vector<double> liczby;
    while (plik >> liczba)
    {
        liczby.push_back(liczba);
        k++;
    }
    w.ilosc = k;
    w.srednia_liczb = srednia(liczby);
    w.odchylenie_standardowe_liczb = odchylenie_standardowe(liczby);
    plik.close();
    return w;
}

void tabliczka_mnozenia(std::string nazwa_pliku, int rozmiar)
{
    std::ofstream plik (nazwa_pliku);
    plik << std::setw(5);
    plik << "";
    for (int i = 0; i <= rozmiar; i++)
    {
        if (i != 0)
        {
            plik << std::setw(4);
            plik << i << "|";
        }
        for (int j = 1; j <= rozmiar; j++)
        {
            if (i == 0)
                plik << std::setw(4)<< j;
            else
                plik << std::setw(4)<< i * j;
        }
        plik << std::endl;

        if (i == 0)
        {
            plik << std::setw(5);
            plik << "";
            for (int j = 1; j <= rozmiar; j++) plik << "----";
            plik << std::endl;
        }
    }
    plik.close();
}
std::string alfabet = "abcdefghijklmnopqrstuvwxyz";
void histogram(std::string nazwa_pliku)
{
    std::ifstream plik(nazwa_pliku);
    int k = 0;
    std::string tekst="";
    std::string wyraz="";
    std::vector<int>ilosc_wystapien;
    while (plik >> wyraz)
    {
        tekst += wyraz + " ";
        k++;
    }
    std::cout << tekst<<"\n\n";
    for (auto& znak : tekst)
    {
        if (std::isupper(znak))
            znak=std::tolower(znak);
    }
    for (int i = 0; i < alfabet.size();i++)
    {
        std::size_t miejsce = 0;
        k = 0;
        while (true)
        {
            miejsce=tekst.find(alfabet[i], miejsce);
            if (miejsce == std::string::npos)
                break;
            miejsce++;
            k++;
        }
        ilosc_wystapien.push_back(k);
    }
    plik.close();
    wypisz_wyniki(ilosc_wystapien);
    std::cout << "\n\n";
    narysuj_wyniki(ilosc_wystapien);
}

void wypisz_wyniki(std::vector<int>ilosc_wystapien)
{
    for (int i = 0; i < alfabet.size();i++)
    {
        if (ilosc_wystapien[i] > 0)
            std::cout << alfabet[i] << ": " << ilosc_wystapien[i] << std::endl;
    }
}

std::string zrob_gwiazdki(std::vector<int>ilosc_wystapien, int litera, int maks_wyst)
{
    std::string ciag="";
    //skalowanie
    if (maks_wyst > 60)
    {
        for (int i = 0;i < 60*ilosc_wystapien[litera]/maks_wyst;i++)
            ciag += char(254);
    }
    else
    {
        for (int i = 0;i < ilosc_wystapien[litera];i++)
            ciag += char(254);
    }
    return ciag;
}

void narysuj_wyniki(std::vector<int>ilosc_wystapien)
{
    int maks_wyst = *std::max_element(ilosc_wystapien.begin(), ilosc_wystapien.end());
    for (int i = 0; i < alfabet.size();i++)
    {
        if (ilosc_wystapien[i] > 0)
            std::cout << alfabet[i] << ": " << zrob_gwiazdki(ilosc_wystapien, i, maks_wyst) << std::endl;
    }
}