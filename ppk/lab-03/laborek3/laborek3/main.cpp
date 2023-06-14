#include <iomanip>
#include <iostream>
#include <random>
#include <conio.h>
using namespace std;

void zad1()
{
	int n;
	cout << "Podaj liczbe: "; cin >> n;
	for (int i = 1; i <= n; i++)
		cout << i << " ";
	cout << endl;
	int i = 1;
	while (n >= i)
	{
		cout << i << " ";
		i++;
	}
	i = 1;
	cout << endl;
	do
	{
		cout << i << " ";
		i++;
	} while (n >= i);

	cout << endl << endl;
	
	cout << "Podaj liczbe: "; cin >> n;
	for (int i = n; i >= 1; i--)
		cout << i << " ";
	cout << endl;
	i = n;
	while (1 <= i)
	{
		cout << i << " ";
		i--;
	}
	i = n;
	cout << endl;
	do
	{
		cout << i << " ";
		i--;
	} while (1 <= i);
	int start, stop, dzielnik;
	cout << "\n\nPodaj start, stop i dzielnik"<<endl;
	cin >> start >> stop >> dzielnik;
	for (int j = start; j <= stop; j++)
	{
		if (j % dzielnik == 0) cout << j<< " ";
	}
	int pod, wyk;
	double wynik = 1;
	cout << "\n\nPodaj podstawe i wykladnik:" << endl;
	cin >> pod >> wyk;
	if (wyk > 0)
	{
		for (int j = 0; j < wyk; j++)
		{
			wynik *= pod;
		}
	}
	cout << wynik;
}

void zad2()
{
	int a;
	cout << "Podaj liczbe do sprawdzenia czy pierwsza: "; cin >> a;
	bool k = 0;
	for (int i = a - 1; i > 1; i--)
	{
		if (a % i == 0)k=true;
		if (k == true) break;
	}
	if (k)cout << "\nNie jest pierwsza";
	else cout << "\nJest pierwsza";

}

void zad3()
{
	default_random_engine eng;
	uniform_int_distribution<int> liczba(1, 100);
	cout << "Zgadnij liczbe 1-100 w co najwyzej 7 probach\n";
	int i = 0;
	bool k = true;
	int proba;
	int wylosowana = liczba(eng);
	while (i<7 && k)
	{
		cout << i + 1 << ". proba: "; 
		cin >> proba;
		if (proba > wylosowana) 
			cout << "Podana przez ciebie liczba jest za duza\n";
		else if (proba < wylosowana) 
			cout << "Podana przez ciebie liczba jest za mala\n";
		else
		{
			cout << "Zgadles, gratulacje. Ilosc prob: " << i + 1;
			k=false;
		}
		i++;
		cout << endl;
		if (i == 7)
			cout << "Nie udalo ci sie :( \nWylosowana liczba to:" << wylosowana<<endl;
	}
}

void zad4()
{
	int decyzja;
	double a;
	int k = 0;
	double suma = 0;
	double mini, maks;
	double tablica[100] = {};

	do
	{
		cout << "Podaj liczbe: "; cin >> a;
		tablica[k] = a;
		k++;
		suma += a;
		if (k == 1)
		{
			maks = a;
			mini = a;
		}

		if (a > maks) maks = a;
		if (a < mini) mini = a;
		cout << "\nDecyzja (1-kontynuuj, inny znak-stop):";
		cin >> decyzja;
	} while (decyzja==1);

	cout << "\n\nIlosc podanych liczb: " << k;
	cout << "\nSrednia podanych liczb: " << suma / k;
	cout << "\nMinimalna wartosc: " << mini;
	cout << "\nMaksymalna wartosc: " << maks;
	double roznice=0;
	for (int i = 0;i < k;i++)
	{
		roznice += pow(tablica[i] - (suma / k), 2);
	}
	cout << "\nOdchylenie standardowe: " << sqrt((roznice) / k);
	
}

void zad5()
{
	cout << setw(5);
	cout << "";
	for (int i = 0; i < 16; i++)
	{	
		if (i != 0)
		{
			cout << setw(4);
			cout << i<<"|";
		}
		for (int j = 1; j < 16; j++)
		{
			if (i==0)
			{
				cout << setw(4);
				cout << hex << j;
			}
			else
			{
				cout << setw(4);
				cout << hex << i * j;
			}
		}
		cout << endl;
		
		if (i == 0)
		{
			cout << setw(5);
			cout << "";
			for (int j = 1;j < 16;j++) cout << "----";
			cout << endl;
		}
	}
}

int main()
{
	//zad1();
	//zad2();
	//zad3();
	//zad4();
	zad5();
}