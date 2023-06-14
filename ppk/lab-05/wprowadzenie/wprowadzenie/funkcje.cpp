#include "funkcje.h"
#include <random>
#include <iostream>
#include <vector>
#include <utility>  

using namespace std;
enum typ_rownania { oznaczony, sprzeczny, nieoznaczony };

int rand_int(int low = 0, int high = 99)
{
	static std::default_random_engine re{ std::random_device{}() };
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}

int dodaj(int a, int b)
{
	return a + b;
}

void zmien(int& a, int& b)
{
	int pom;
	pom = a;
	a=b;
	b=pom;
}

void wypelnij(int t[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		t[i] = rand_int(0,99);
	}
}

double potega(int wykladnik, double podstawa)
{
	double wynik = 1;
	if (wykladnik >= 0)
	{
		for (int i = 0; i < wykladnik; i++)
		{
			wynik *= podstawa;
		}
	}
	else
	{
		for (int i = wykladnik; i < 0; i++)
		{
			wynik /= podstawa;
		}
	}
	return wynik;
}

int odleglosc(int a, int b)
{
	if (a > b) return a - b;
	else return b - a;
}

void wyswietl_tablice(int t[], int r)
{
	for (int i = 0; i < r; i++)
	{
		cout << "t[" << i << "]=" << t[i] << endl;
	}
}

void tablica_od_konca_rek(int t[], int n)
{
	cout << "t[" << n << "]=" << t[n] << endl;
	if (n>0) tablica_od_konca_rek(t, n - 1);
}

int fib_rek(int n)
{
	if (n < 3) return 1;
	else return (fib_rek(n - 1) + fib_rek(n - 2));
}

int fib_it(int n)
{
	int nowa = 1;
	int stara = 1;
	for (int i = 2; i < n; i++)
	{
		nowa += stara;
		stara = nowa - stara;
	}
	return nowa;
}
int wyznaczniki(double& x, double& y)
{
	double a1, a2, b1, b2, c1, c2, W, Wx, Wy;

	cout << "a1x+b1y=c1\na2x+b2y=c2" << endl << endl;

	cout << "podaj a1:";cin >> a1;
	cout << "podaj b1:";cin >> b1;
	cout << "podaj c1:";cin >> c1;
	cout << "podaj a2:";cin >> a2;
	cout << "podaj b2:";cin >> b2;
	cout << "podaj c2:";cin >> c2;
	cout << endl;

	W = a1 * b2 - a2 * b1;
	Wx = c1 * b2 - c2 * b1;
	Wy = a1 * c2 - a2 * c1;

	if (W)
	{
		x = Wx / W;
		y = Wy / W;
		return typ_rownania(oznaczony);
	}
	else if (Wx == 0 && Wy == 0)
		return typ_rownania(nieoznaczony);
	else
		return typ_rownania(sprzeczny);
}

void segregacja(int t[], int rozmiar)
{
	int j,poz,mini,pom;
	for (int i = 0; i < rozmiar - 1; i++)
	{
		poz = i;
		mini = t[i];
		for (j = i + 1; j < rozmiar; j++)
		{
			if (mini > t[j])
			{
				mini = t[j];
				poz = j;
			}
		}
		pom = t[i];
		t[i] = t[poz];
		t[poz] = pom;
	}
}

void rown_kwadr(double a, double b, double c, double &x1, double &x2)
{
	double delta;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0) cout << "Rownanie tozsamosciowe\n";
			else cout << "Rownanie sprzeczne\n";
		}
		else x1 = -c / a;
	}
	else
	{
		delta = b * b - (4 * a * c);
		if (delta > 0)
		{
			x1 = (-b - sqrt(delta)) / (a * 2);
			x2 = (-b + sqrt(delta)) / (a * 2);
		}
		else if (delta == 0) x1 = -b / (2 * a);
		else cout << "Brak rozw dla liczb rzeczywistych\n";
	}
}

int hanoi(int n, int miejsce_poczatkowe, int miejsce_docelowe)
{
	static int ilosc_posuniec = 0;
	if (n == 1)
	{
		cout << "Element " << n << " na " << miejsce_docelowe << " z " << miejsce_poczatkowe << endl;
		return ++ilosc_posuniec;
	}
	else
	{
		int miejsce_tymczasowe = 6 - miejsce_docelowe - miejsce_poczatkowe;
		hanoi(n - 1, miejsce_poczatkowe, miejsce_tymczasowe);
		cout << "Element " << n << " na " << miejsce_tymczasowe << " z " << miejsce_poczatkowe<<endl; 
		ilosc_posuniec++;
		hanoi(n - 1, miejsce_tymczasowe, miejsce_docelowe);
	}
	
	return ilosc_posuniec;
}

void wypelnij_wektor (vector<int> &tab)
{
	int rozmiar = rand_int(1, 6);
	for (int i = 0; i < rozmiar; i++)
	{
		tab.push_back(rand_int(0, 99));
	}
}

void wypisz_tab_wek(vector<int> t)
{
	for (int i = 0; i < t.size(); i++)
	{
		cout << "tv[" << i << "]=" << t[i] << endl;
	}
}
pair<int,int> minmax(vector<int> tablica)
{
	int mini=tablica[0], maks=tablica[0];
	pair<int, int>maksmini;
	for (int i = 1; i < tablica.size(); i++)
	{
		if (mini > tablica[i]) mini = tablica[i];
		if (maks < tablica[i]) maks = tablica[i];
	}
	 
	return make_pair(maks, mini);
}

void segr_wek(std::vector<int> &tab)
{
	for (int i = 0; i < tab.size() - 1; i++)
	{
		int poz = i;
		int mini = tab[i];
		for (int j = i + 1; j < tab.size(); j++)
		{
			if (mini > tab[j])
			{
				mini = tab[j];
				poz = j;
			}
		}
		int pom = tab[i];
		tab[i] = tab[poz];
		tab[poz] = pom;
	}
}

