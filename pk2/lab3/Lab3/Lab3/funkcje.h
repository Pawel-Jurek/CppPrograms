#pragma once
#include<string>

class Komponent
{
protected:
	int x, y, szerokosc, wysokosc;

public:
	Komponent() :x(0), y(0), szerokosc(0), wysokosc(0) {}
	Komponent(int x, int y, int szerokosc, int wysokosc) : x(x), y(y), szerokosc(szerokosc), wysokosc(wysokosc) {}
	virtual void rysuj() = 0;


	int pobierz_x() const { return x; }
	int pobierz_wysokosc() const { return wysokosc; }
	int pobierz_szerokosc() const { return szerokosc; }
	int pobierz_y() const { return y; }

	~Komponent();
};

class Kontrolka : public Komponent
{
public:
	Kontrolka() : Komponent() {}
	Kontrolka(int x, int y, int szerokosc, int wysokosc) : Komponent(x, y, szerokosc, wysokosc) {}
	virtual void rysuj() {};
	
	
	//virtual void rysuj() { std::cout<<"Kontrolka !!!\n"; } //{ std::cout << "Rysuj Kontrolkê\n"; };
	~Kontrolka();
};



class Przycisk :public Kontrolka
{
private:
	std::string opis;
public:
	Przycisk() :Kontrolka(), opis("") {}
	Przycisk(int x, int y, int szerokosc, int wysokosc, std::string opis) :Kontrolka(x, y, szerokosc, wysokosc), opis(opis) {};
	std::string pobierz_opis_przycisku() const { return opis; }
	virtual void rysuj() override { std::cout<<"PRZYCISK!!"; }
	~Przycisk();
};

class Pole_tekstowe :public Kontrolka
{
protected:
	int max_dlugosc;
	std::string tresc_pola_tekstowego;
public:
	Pole_tekstowe() :Kontrolka(), max_dlugosc(0), tresc_pola_tekstowego("") {}
	Pole_tekstowe(int x, int y, int szerokosc, int wysokosc, int max_dlugosc, std::string tresc_pola_tekstowego) :Kontrolka(x, y, szerokosc, wysokosc), max_dlugosc(max_dlugosc), tresc_pola_tekstowego(tresc_pola_tekstowego) {};
	virtual void rysuj() override {
		tresc_pola_tekstowego = pobierz_tresc_pola();
		std::cout<<"POLE!!"; 
	}
	std::string pobierz_tresc_pola() const { return tresc_pola_tekstowego;}
	int pobierz_maks_dlugosc_pola() const { return max_dlugosc; }
	int pobierz_dlugosc_tekstu() const { return tresc_pola_tekstowego.length(); }
	virtual std::string pobierz_tresc_pola_tekstowego() { return ""; }// std::string const { return tresc_pola_tekstowego; }
	~Pole_tekstowe();

	int d = 0;
};

class Pola_hasla :public Pole_tekstowe
{
public:
	Pola_hasla() :Pole_tekstowe() {}
	Pola_hasla(int x, int y, int szerokosc, int wysokosc, int max_dlugosc, std::string tresc_pola_tekstowego) :Pole_tekstowe(x, y, szerokosc, wysokosc, max_dlugosc, tresc_pola_tekstowego) {};
	virtual std::string pobierz_tresc_pola_tekstowego();
	~Pola_hasla();
};


class Menu
{
};

class Lista_rozwijana :public Kontrolka
{
	Lista_rozwijana():Kontrolka() {}
	Lista_rozwijana(int x, int y, int szerokosc, int wysokosc) :Kontrolka(x, y, szerokosc, wysokosc) {}
	virtual void rysuj() override
	{
		std::cout << "Lista\n";
	}
	~Lista_rozwijana()
	{
		;
	}
};

class Combo :public Kontrolka, public Pole_tekstowe
{
	Combo() :Pole_tekstowe() {}
	Combo (int x, int y, int szerokosc, int wysokosc, int max_dlugosc, std::string tresc_pola_tekstowego) :Pole_tekstowe(x, y, szerokosc, wysokosc, max_dlugosc, tresc_pola_tekstowego) {};
};

class Okno :public Komponent
{
	std::string tytul;
	static int LiczbaOkien;
	//Combo combo1;
	Kontrolka* pole;
	Kontrolka* przycisk;

	Menu menu;
public:

	Okno();
	Okno(int x, int y, int szerokosc, int wysokosc, std::string tytul, Kontrolka* przycisk, Kontrolka *pole) :Komponent(x, y, szerokosc, wysokosc), tytul(tytul), przycisk(przycisk), pole(pole) {};
	//const Przycisk dostep_przycisk() const { return przycisk; }
	//const dostep_pole() const { return pole; }
	virtual void rysuj() override 
	{ 
		std::cout << "OKNO!!!"; 
		pole->rysuj();
		przycisk->rysuj();
	}


	std::string pobierz_tytul_okna() const { return tytul; }


	void dopasuj_okno();

	~Okno();
};
