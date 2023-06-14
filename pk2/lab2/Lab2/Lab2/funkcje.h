#pragma once
#include<string>

class Komponent
{
protected:
	int x, y, szerokosc, wysokosc;

public:
	Komponent() :x(0), y(0), szerokosc(0), wysokosc(0) {}
	Komponent(int x, int y, int szerokosc, int wysokosc) : x(x), y(y), szerokosc(szerokosc),wysokosc(wysokosc) {}
	
	int pobierz_x() const { return x; }
	int pobierz_wysokosc() const { return wysokosc; }
	int pobierz_szerokosc() const { return szerokosc; }
	int pobierz_y() const { return y; }
	
	/*
	virtual const int pobierz_x() const{ return 0; }
	virtual int pobierz_y() const { return 0; }
	virtual int pobierz_wysokosc() const { return 0; }
	virtual int pobierz_szerokosc() const { return 0; }
	*/
	~Komponent();
};

class Kontrolka : public Komponent
{
public:
	Kontrolka() : Komponent() {}
	Kontrolka(int x, int y, int szerokosc, int wysokosc) : Komponent(x, y, szerokosc, wysokosc) {}
	~Kontrolka();
};



class Przycisk :public Kontrolka
{
private:
	std::string opis;
public:
	Przycisk() :Kontrolka(), opis("") {}
	Przycisk(int x, int y, int szerokosc, int wysokosc, std::string opis) :Kontrolka(x, y, szerokosc, wysokosc), opis(opis) {};
	std::string pobierz_opis_przycisku() const { return opis;}
	~Przycisk();
};

class Pole_tekstowe :public Kontrolka
{
protected:
	int max_dlugosc;
	std::string tresc_pola_tekstowego;
public:
	Pole_tekstowe() :Kontrolka(), max_dlugosc(0),tresc_pola_tekstowego("") {}
	Pole_tekstowe(int x, int y, int szerokosc, int wysokosc, int max_dlugosc, std::string tresc_pola_tekstowego) :Kontrolka(x, y, szerokosc, wysokosc), max_dlugosc(max_dlugosc), tresc_pola_tekstowego(tresc_pola_tekstowego) {};
	int pobierz_maks_dlugosc_pola() const { return max_dlugosc; }
	int pobierz_dlugosc_tekstu() const { return tresc_pola_tekstowego.length(); }
	std::string pobierz_tresc_pola_tekstowego() const { return tresc_pola_tekstowego; }
	~Pole_tekstowe();

	int d = 0;
};

class Pola_hasla :public Pole_tekstowe
{
public:
	Pola_hasla() :Pole_tekstowe() {}
	Pola_hasla(int x, int y, int szerokosc, int wysokosc, int max_dlugosc, std::string tresc_pola_tekstowegoowego) :Pole_tekstowe(x, y, szerokosc, wysokosc, max_dlugosc, tresc_pola_tekstowegoowego) {};
	std::string pobierz_tresc_pola_tekstowego();
	~Pola_hasla();
};

/*
class Menu
{

};
*/

class Okno :public Komponent
{
	std::string tytul;
	static int LiczbaOkien;
	Przycisk przycisk;
	Pole_tekstowe pole;
	//Menu menu;
public:
	
	Okno();
	Okno(int x, int y, int szerokosc, int wysokosc, std::string tytul, Przycisk przycisk, Pole_tekstowe pole) :Komponent(x, y, szerokosc, wysokosc), tytul(tytul), przycisk(przycisk), pole(pole) {};
	const Przycisk dostep_przycisk() const { return przycisk; }
	const Pole_tekstowe dostep_pole() const { return pole; }
	std::string pobierz_tytul_okna() const { return tytul; }
	

	void dopasuj_okno();

	~Okno();
};

