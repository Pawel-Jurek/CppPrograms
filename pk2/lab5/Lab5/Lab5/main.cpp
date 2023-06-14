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
	Napis napis(test);
	Napis napis2(test2);
	Napis napis3 = napis + napis2; 
	std::cout << napis<<"\n\n";
	napis = napis2;
	//napis3.pokaz_napis();
	std::cout << napis3++ << " ";
	std::cout << napis3 <<"\n";
	std::cout << napis3-- << " ";
	std::cout << napis3  << "\n";
	
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

	Napis n1({ 'a','a' });
	Napis n2({ 'b','b' });
	Napis n3({ 'c' });
	Napis n4({ 'a','a','a'});

	std::cout << std::boolalpha << (n1 < n2) << (n3 > n4) << (n1 < n4) << std::endl;


}
