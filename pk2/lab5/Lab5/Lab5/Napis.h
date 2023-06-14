#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <compare>



class Napis
{
protected:
	std::vector<char>znaki;
	int dlugosc_napisu = znaki.size();

public:
	Napis():znaki(),dlugosc_napisu(0) {};
	Napis(std::vector<char>znaki) :znaki(znaki), dlugosc_napisu(znaki.size()) {}
	void dodaj_znak(char znak) 
	{ 
		znaki.push_back(znak); 
		dlugosc_napisu++; 
	}
	friend std::ostream& operator<< (std::ostream& s, const Napis& v);

	auto operator<=>(const Napis& rhs) const = default;

	void pokaz_napis()
	{
		std::cout << "\n";
		for (int i = 0; i < znaki.size(); i++)
		{
			std::cout << znaki[i];
		}
		std::cout << "\n";
	}

	Napis& operator=(const Napis& other) {
		
		if (&other != this) {
			this->znaki.resize(0);
			for (int i = 0; i < other.dlugosc_napisu  ; i++)
			{
				std::cout << i << ", ";
				this->znaki.push_back(other.znaki[i]);
			}
		}
		this->dlugosc_napisu = this->znaki.size();
		return *this;
	}

	Napis operator+(const Napis other) {
		std::vector<char>nowy;
		for (int i = 0; i < this->dlugosc_napisu; i++)
		{
			nowy.push_back(this->znaki[i]);
		}
		for (int i = 0; i < other.dlugosc_napisu; i++)
		{
			nowy.push_back(other.znaki[i]);
		}
		return nowy;
	}

	Napis& operator++()
	{
		std::transform(this->znaki.begin(), this->znaki.end(), this->znaki.begin(), ::toupper);
		return *this;
	}
	
	Napis& operator--()
	{
		std::transform(this->znaki.begin(), this->znaki.end(), this->znaki.begin(), ::tolower);
		return *this;
	}

	Napis operator++(int)
	{
		auto this2 = *this;
		std::transform(this->znaki.begin(), this->znaki.end(), this->znaki.begin(), ::toupper);
		return this2;
	}

	Napis operator--(int)
	{
		auto this2 = *this;
		std::transform(this->znaki.begin(), this->znaki.end(), this->znaki.begin(), ::tolower);
		return this2;
	}

	~Napis() {}//{ std::cout << "Destruktor napisu"; }
};

std::ostream& operator<< (std::ostream& s, const Napis& n)
{
	for (int i = 0; i < n.dlugosc_napisu; i++)
		s << n.znaki[i];
	return s;
}
