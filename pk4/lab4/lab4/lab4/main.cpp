#include <ranges>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

namespace vs = std::views;
namespace rg = std::ranges;
void zadanie1(int wartosc = 4)
{
	//a
	std::vector<int> wektorLiczb{ 1,2,3,4,5,6,7,8,9,10 };
	auto wynik = wektorLiczb | vs::filter([](int i) {return i < 8; })
		| vs::take(4);

	for (const auto& num : wynik)
		std::cout << num << " ";

	std::cout << "\n";

	//b
	std::vector<std::string> wektorStringow{ "aaa","aaaa", "aab", "bwaawa", "z", "kkakk", "zzk", "kdfa" };
	rg::sort(wektorStringow, {}, [](const std::string& s) {return s.size(); });
	for (const auto& s : wektorStringow)
		std::cout << s << " ";

	std::cout << "\n";

	//c
	auto it = rg::find_if(wektorLiczb, [&](int x) {return x > wartosc; });

	if (it != wektorLiczb.end())
		std::cout << "Najmniejszym elementem, ktory jest wiekszy od " << wartosc << " jest " << *it << "\n\n";
	else
		std::cout << "Nie znaleziono elementu, ktory jest wiekszy od " << wartosc << "\n\n";
		
}

class Person
{
private:
	std::string imie;
	std::string nazwisko;
	int wiek;
public:
	Person(std::string p_imie, std::string p_nazwisko, int p_wiek) :imie(p_imie), nazwisko(p_nazwisko), wiek(p_wiek) {};
	~Person() = default;
	inline int getAge() const { return wiek; }
	void repr() const { std::cout << imie << " " << nazwisko << " " << wiek << "\n"; }
};

void zadanie2()
{
	std::ifstream plikWejsciowy("ludzie.txt");
	if (!plikWejsciowy)
		std::cout<<"Blad wczytywania pliku\n";
	std::vector<Person> ludzie;
	std::string imie, nazwisko;
	int wiek;

	while (plikWejsciowy >> imie >> nazwisko >> wiek)
	{
		ludzie.emplace_back(Person(imie, nazwisko, wiek));
	}

	auto przefiltrowaniLudzie = ludzie | vs::filter([](const Person& p) {
		return p.getAge() >= 18 && p.getAge() <= 25;
		});
	for (const auto& p : przefiltrowaniLudzie)
	{
		p.repr();
	}
}

void zadanie3(std::string doZaszyfrowania = "PrzykladowyTekst")
{
	std::cout << "\nTekst do zaszyfrowania:\t" << doZaszyfrowania << "\n";
	auto zaszyfrowany = doZaszyfrowania | vs::transform([](char c) {
		if (std::isdigit(c))
		{
			return ((c) % '9' ? static_cast<char>(c + 1) : '0');
		}
		else if (std::isalpha(c))
		{
			if (std::islower(c))
				return ((c) % 'a' ? static_cast<char>(c - 1) : 'z');
			else
				return ((c) % 'A' ? static_cast<char>(c - 1) : 'Z');
		}
		else
			return c;
		});

	std::cout << "Zaszyfrowany tekst:\t" << std::string{ zaszyfrowany.begin(), zaszyfrowany.end()} << "\n";
}

int main()
{
	zadanie1();
	zadanie2();
	zadanie3("abc   xyz   ABC    XYZ   0123   789");
}