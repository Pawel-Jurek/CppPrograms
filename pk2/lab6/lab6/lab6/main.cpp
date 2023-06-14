#include <iostream>
#include "Napis.h"
#include <vector>
#include <compare>
#include <algorithm>
#include <cctype>



int main()
{
	std::vector<char>test{ 'a','a','a' };
	std::vector<char>test2{ 'b','b','b','b','b','b' };
	Napis <char> napis(test);
	Napis <char> napis2(test2);
	Napis <char> napis3 = napis + napis2;
	Napis <wchar_t> napisw(test);
	Napis <wchar_t> napisw2(test2);
	Napis <wchar_t> napisw3 = napisw + napisw2;
	std::cout << napis << "\n\n";
	napis = napis2;
	//napis3.pokaz_napis();
	std::cout << napis3++ << " ";
	std::cout << napis3 << "\n";
	std::cout << napis3-- << " ";
	std::cout << napis3 << "\n";

	std::cout << ++napis3 << " ";
	std::cout << napis3 << "\n";
	std::cout << --napis3 << " ";
	std::cout << napis3 << "\n";

	//napis3.pokaz_napis();
	//napis3--;
	//napis.pokaz_napis();
	//++napis3;
	//napis3.pokaz_napis();
	//--napis3;
	//napis3.pokaz_napis();

	//test

	std::cout << ((10 <=> 20) < 0) << std::endl;
	std::cout << ((10 <=> 10) < 0) << std::endl;
	std::cout << ((20 <=> 10) < 0) << std::endl;
	std::cout << ((10 <=> 20) == 0) << std::endl;
	std::cout << ((10 <=> 10) == 0) << std::endl;
	std::cout << ((20 <=> 10) == 0) << std::endl;
	std::cout << ((10 <=> 20) > 0) << std::endl;
	std::cout << ((10 <=> 10) > 0) << std::endl;
	std::cout << ((20 <=> 10) > 0) << std::endl;

	Napis <char> n1({ 'a','a' });
	Napis <char> n2({ 'b','b' });
	Napis <char> n3({ 'c' });
	Napis <char>n4({ 'a','a','a' });

	std::cout << std::boolalpha << (n1 < n2) << (n3 > n4) << (n1 < n4) << std::endl;


}