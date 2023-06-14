/** @file */

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include "funkcje.h"
#include "zamowienia.h"
#include "zrealizowane_zamowienie.h"
#include "dania.h"
#include <iomanip>


/** Klasa Pracownik dziedziczaca publicznie po klasie Obserwator */
class Pracownik: public Obserwator
{
protected:
	std::string imie;		/**< imie pracownika */
	std::string nazwisko;	/**< nazwisko pracownika */
	bool aktywny;			/**< czy aktywny */
	int czas_na_ile_zajety;	/**< czas na ile zajety */
	/* Metoda wirtualna aktualizuj */
	virtual void aktualizuj(Zamowienie& h) {}; 
public:
	/** Konstruktor klasy Pracownik inicjujacy zmienne wartosciami podanymi w konstruktorze, ponadto ustawiajacy status aktywny na false i czas_na_ile_zajety na 0
	* @param imie imie pracownika
	* @param nazwisko nazwisko pracownika
	*/
	Pracownik(std::string imie, std::string nazwisko) :imie(imie),nazwisko(nazwisko), aktywny(false), czas_na_ile_zajety(0) {}
	
	/** Metoda zwracajaca imie pracownika
	* @return imie
	*/
	std::string dostep_imie() { return imie; }

	/** Metoda zwracajaca nazwisko pracownika
	* @return nazwisko
	*/
	std::string dostep_nazwisko() { return nazwisko; }
	
	/** Metoda zwracajaca czy pracownik jest aktywny
	* @return aktywny (true / false)
	*/
	bool dostep_aktywny() { return aktywny; }

	/** Metoda wirtualna wyswietlajaca pracownika */
	virtual void wyswietl_pracownika() = 0;

	/** Metoda wirtualna szukajaca wolnego pracownika */
	virtual Pracownik* znajdz_wolnego_pracownika()=0;

	/** Metoda wirtualna zajmujaca wolnego pracownika */
	virtual void zajmij_wolnego_pracownika()=0;
};

/** Klasa Kucharz dziedziczaca publicznie po klasie Pracownik */
class Kucharz :public Pracownik
{
public:
	/** Konstruktor klasy Kucharz inicjujacy zmienne wartosciami podanymi w konstruktorze, korzysta z konstruktora klasy bazowej Pracownik
	* @param imie imie pracownika
	* @param nazwisko nazwisko pracownika
	*/
	Kucharz(std::string imie, std::string nazwisko) :Pracownik(imie, nazwisko) {}
	
	/** Funkcja aktualizuje kucharza, to znaczy przydziela mu zamowienie i karze mu je zrobic
	* @param zam zamowienie przekazane do realizacji
	*/
	void aktualizuj(Zamowienie& zam) override 
	{
		std::cout << "Kucharz w akcji\n";
		aktywny = true;
		auto zamowione=zam.pobierz_zamowione();
		for (int i = 0; i < zamowione.size(); i++)
		{
			czas_na_ile_zajety+=zamowione[i].pokaz_czas();
		}
		std::cout << "Kucharz zajety na:" << czas_na_ile_zajety << " sec\n";
		//Sleep(czas_na_ile_zajety * 1000);
		czas_na_ile_zajety = 0;
		aktywny = false;
		std::cout << "\n\nZamowienie dla stolika nr: " << zam.dostep_stolik().dostep_numer_stolika() << " jest gotowe\n";
	}

	/** Funkcja dezaktywuje kucharza */
	void odwolaj() override
	{
		aktywny = false;
	}

	/** Funkcja wyswietla pracownika -> tutaj kucharza */
	void wyswietl_pracownika() override
	{
		std::cout << std::setw(10) <<  "Kucharz | "<<std::setw(13) << imie << " | " << std::setw(16) << nazwisko << " | " <<std::setw(8) << aktywny <<" | " << std::setw(15)  << czas_na_ile_zajety << "\n";
	}
	/** Funkcja szuka wolnego pracownika i ponadto znajduje takowego
	* @return wskaznik na wolnego pracownika, no w tym przypadku nie da sie ukryc ze to bedzie kucharz. A jesli nie znajdzie wolnego to wtedy zwraca nullptr
	*/
	Pracownik* znajdz_wolnego_pracownika() override
	{
		if (!aktywny)
		{
			return this;
		}
		return nullptr;
	}

	/** Funkcja zajmuje wolnego pracownika w tym przypadku kucharza */
	void zajmij_wolnego_pracownika() override
	{
		aktywny = true;
	}
};

/** Klasa Kelner dziedziczaca publicznie po klasie Pracownik */
class Kelner :public Pracownik
{
public:
	/** Konstruktor klasy Kelner inicjujacy zmienne wartosciami podanymi w konstruktorze, korzysta z konstruktora klasy bazowej Pracownik
	* @param imie imie pracownika
	* @param nazwisko nazwisko pracownika
	*/
	Kelner(std::string imie, std::string nazwisko) :Pracownik(imie, nazwisko) {}
	
	/** Funkcja aktualizuje kelnera, to znaczy przydziela mu zamowienie i karze mu je dostarczyc
	* @param zam zamowienie przekazane do realizacji
	*/
	void aktualizuj(Zamowienie& h) override
	{
		aktywny = true;
		std::cout << "\nKelner w akcji\n";
		Sleep(5000);
		std::cout << "Zamowienie dostarczone do stolika nr: "<<h.dostep_stolik().dostep_numer_stolika()<<"\n\n";
		Sleep(2000);
		aktywny = false;
	}

	/** Funkcja dezaktywuje kelnera */
	void odwolaj() override
	{
		aktywny = false;
	}	

	/** Funkcja wyswietla pracownika -> tutaj kelnera */
	void wyswietl_pracownika() override
	{
		std::cout << std::setw(10) << "Kelner | " << std::setw(13) << imie << " | " << std::setw(16) << nazwisko << " | " << std::setw(8) << aktywny << " | " << std::setw(15) << czas_na_ile_zajety << "\n";
	}

	/** Funkcja szuka wolnego pracownika i ponadto znajduje takowego
	* @return wskaznik na wolnego pracownika, no w tym przypadku nie da sie ukryc ze to bedzie kelner. A jesli nie znajdzie wolnego to wtedy zwraca nullptr
	*/
	Pracownik* znajdz_wolnego_pracownika() override
	{
		if (!aktywny)
		{
			return this;
		}
		return nullptr;
	}

	/** Funkcja zajmuje wolnego pracownika w tym przypadku kelnera */
	void zajmij_wolnego_pracownika() override
	{
		aktywny = true;
	}
};
/** Klasa Kuchnia */
class Kuchnia
{
protected:
	std::vector<Pracownik*> pracownicy;		/**< Tablica typu vetor przetrzymujaca wskazniki na pracownikow */

public:
	/** Konstruktor klasy Kuchnia inicjuje tablice pracownikami podanymi w pliku, ktorego nazwa jest podawana do konstruktora
	* @param nazwa_pliku nazwa pliku z pracownikami
	*/
	Kuchnia(std::string nazwa_pliku)
	{
		std::ifstream plikwej(nazwa_pliku);
		if (!plikwej)
		{
			std::cerr << "Error: nie mozna otworzyc pliku :( " << nazwa_pliku << "\n";
		}
		while (true)
		{
			std::string rola, imie, nazwisko;
			plikwej >> rola >> imie >> nazwisko;
			if (!plikwej.fail())
			{				
				
				if (rola == "kucharz")
				{		
					Pracownik* pracownik = new Kucharz(imie, nazwisko);
					pracownicy.push_back(pracownik);	
				}
				else if (rola == "kelner")
				{
					Pracownik* pracownik = new Kelner(imie, nazwisko);
					pracownicy.push_back(pracownik);
				}				
			}
			else
				break;
		}
	};

	/** Funkcja wyswietla sklad personelu kuchennego */
	void pokaz_sklad_kuchni()
	{
		std::cout << "\nLista pracownikow:\n";
		std::cout << std::setw(10) << "Rola | " << std::setw(13) << "Imie" << " | " << std::setw(16) << "Nazwisko" << " | " << std::setw(8) << "Aktywny  | " << std::setw(15) << "Na ile zajety" << "\n";
		std::cout <<"-------------------------------------------------------------------------\n";
		
		for (int i = 0; i < pracownicy.size(); i++)
		{
			pracownicy[i]->wyswietl_pracownika();
		}
		Sleep(3000);
	}

	/** Funkcja szuka wolnego kelnera
	* @return wskaznik na wolnego kelnera. A jesli nie znajdzie wolnego to wtedy zwraca nullptr
	*/
	Pracownik* znajdz_wolnego_kelnera()
	{
		for (int i = 0; i < pracownicy.size(); i++)
		{
			auto b = pracownicy[i]->znajdz_wolnego_pracownika();
			if (b == nullptr)
				continue;
			Kelner* ptr = dynamic_cast<Kelner*>(b);			
			if (ptr)
			{
				zajmij_pracownika(b);
				return b;
			}
		}
		std::cout << "\nBrak wolnego kelnera!!\nSprobuj ponownie za chwile\n";
		return nullptr;
	}
	
	/** Funkcja szuka wolnego kucharza
	* @return wskaznik na wolnego kucharza. A jesli nie znajdzie wolnego to wtedy zwraca nullptr
	*/
	Pracownik* znajdz_wolnego_kucharza()
	{
		for (int i = 0; i < pracownicy.size(); i++)
		{
			auto b = pracownicy[i]->znajdz_wolnego_pracownika();
			if (b == nullptr)
				continue;
			Kucharz* ptr = dynamic_cast<Kucharz*>(b);
			if (ptr)
			{
				zajmij_pracownika(b);
				return b;
			}
		}
		std::cout << "\nBrak wolnego kucharza!!\nSprobuj ponownie za chwile\n";
		return nullptr;
	}

	/** Funkcja zajmuje wolnego pracownika 
	* @param pracownik wskaznik na pracownika
	*/
	void zajmij_pracownika(Pracownik* pracownik)
	{
		pracownik->zajmij_wolnego_pracownika();
	}

	/** Destruktor klasy Kuchnia czysci pamiec */
	~Kuchnia()
	{
		for (int i = 0; i < pracownicy.size(); i++)
		{
			delete(pracownicy[i]);
		}
	}
};