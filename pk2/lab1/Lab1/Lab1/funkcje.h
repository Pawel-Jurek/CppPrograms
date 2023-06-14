#pragma once
#include<string>

class Przycisk
{
public:
	Przycisk();
	std::pair<double, double> wielkosc_przycisku();
	~Przycisk();

private:
	std::string opis;
	int x, y;
};

class Pole
{
public:
	Pole();
	std::pair<double, double> wielkosc_pola();
	~Pole();

private:
	int dlugosc, x, y;
};

class Okno
{
	std::string tytul;
	int x, y;
	static int LiczbaOkien;
	Przycisk* przycisk;
	Pole* pole;
public:
	Okno();
	//Przycisk* button() { return zmienna_guzikowa; }
	//Pole* box() { return zmienna_polowa; }
	
	void dopasuj_okno(Okno& okno);

	//const Przycisk* getPrzycisk() const { return przycisk; }
	//const Pole* getPole() const { return pole; }
	

	~Okno();
};




