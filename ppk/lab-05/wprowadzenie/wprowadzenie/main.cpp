#include <iostream>
#include <random>
#include <vector>
#include <utility>
#include "funkcje.h"
using namespace std;

int main()
{
	enum typ_rownania { oznaczony, sprzeczny, nieoznaczony };
	cout << dodaj(5, 10)<<"\n";

	cout << "\n\nzad1\n";
	//zad1
	double x = 5, y = 7;
	int a1 = 2, b1 = 4;
	zmien(a1, b1);
	cout << y << " " << x;
	
	//zad2
	cout << "\n\nzad2\n";
	constexpr int roz = 5;
	int tab1[roz];
	wypelnij(tab1,roz);
	cout << endl;
	for (int i=0; i < roz; i++)
	{
		cout <<"t["<<i<<"]=" << tab1[i] << "\n";
	}

	//zad3
	cout << "\n\nzad3\n";
	cout << potega(-3, 10);

	//zad4
	cout << "\n\nzad4\n";
	int a, b;
	a = 6;
	b = 2;
	cout << odleglosc(a, b);

	//zad5
	cout << "\n\nzad5\n";
	wyswietl_tablice(tab1, roz);

	//zad6
	cout << "\n\nzad6\n";
	tablica_od_konca_rek(tab1, roz-1);

	//zad7
	cout << "\n\nzad7\n";
	cout << "Iteracyjcnie:  " << fib_it(6) << endl;
	cout << "Rekurencyjnie: " << fib_rek(6) << endl;

	/*
	//zad8
	cout << "\n\nzad8\n";

	switch (wyznaczniki(x, y)) 
	{
	case oznaczony: cout << "Uklad oznaczony" <<endl;
		break;
	case nieoznaczony: cout << "Uklad nieoznaczony" <<endl;
		break;
	case sprzeczny: cout << "Uklad sprzeczny" <<endl;
		break;
	default: 
		break;
	}
	cout << "\n x=" << x << "  y=" << y << endl;
	*/
	//zad9
	cout << "\n\nzad9\n";
	constexpr int rozmiar = 6;
	int t[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		t[i] = rand_int(0,99);
		cout << "t[" << i << "]= " << t[i] << endl;
	}
	cout << "\n\n";

	segregacja(t, rozmiar);

	for (int i = 0; i < rozmiar; i++)
	{
		cout << "t[" << i << "]= " << t[i] << endl;
	}

	//zad10
	cout << "\n\nzad10\n";
	double x1=0, x2=0;
	rown_kwadr(1, 5, 6, x1, x2);
	cout << "x1: " << x1 << "  x2: " << x2 << endl;

	//zad11
	cout << "\n\nzad11\n";
	int wielkosc = 4;
	int miejsce_pocz=1, miejsce_doc=3;
	cout<<hanoi(wielkosc, miejsce_pocz, miejsce_doc);
	
	//zad12
	cout << "\n\nzad12\n";
	vector<int> tab_vector;
	wypelnij_wektor(tab_vector);
	
	//zad13
	cout << "\n\nzad13\n";
	wypisz_tab_wek(tab_vector);

	//zad14
	cout << "\n\nzad14\n";
	pair<int, int> wartosci = minmax(tab_vector);
	cout << wartosci.first << " " << wartosci.second;

	//zad15
	cout << "\n\nzad15\n";
	segr_wek(tab_vector);
	wypisz_tab_wek(tab_vector);
}


