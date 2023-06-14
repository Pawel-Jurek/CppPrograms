#pragma once
#include <memory>
#include <set>
#include <iostream>
#include <chrono>
#include <thread>

class Obserwowany;

class Obserwator
{
public:
	virtual ~Obserwator() {}
	virtual void poinformuj(Obserwowany& subject) = 0;
};

class Obserwowany 
{
protected:
	std::set<Obserwator*> observers;
	void poinformujObserwatorow() {
		for (auto& o : observers) {
			o->poinformuj(*this);
		}
	}

public:
	void zarejestruj(Obserwator* o) {
		observers.insert(o);
	}

	void wyrejestruj(Obserwator* o) {
		observers.erase(o);
	}
};



class Obliczenia: Obserwowany
{
public:
	int i = 0;
	void licz() 
	{
		i++;
		std::chrono::milliseconds opoznienie(1000);
		std::this_thread::sleep_for(opoznienie);
	}
};

class Postep: Obserwator
{

public:
	Obliczenia* wsk_obl;

	void rysuj()
	{
		std::cout << "rysuj";
	}
	void poinformuj(Obserwowany& subject)override
	{
		rysuj();
	}
};