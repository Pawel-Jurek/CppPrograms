#include "set.h"
#include <string>

int main()
{
	try {
		Set<int> set{};
		Set<int> set2{};
		Set<int> set3{};
		for (int i = 0; i < 10; i++)
		{
			set.add_element(i);
			set2.add_element(i + 5);
			set3.add_element(i + 2);
		}

		std::cout << "set1: " << set;
		std::cout << "set2: " << set2;
		std::cout << "set3: " << set3;
		std::cout << "Czesc wspolna 1 i 2:\n";
		std::cout << set * set2;
		std::cout << "suma 1 i 2:\n";
		std::cout << set + set2;
		std::cout << "roznica 1 i 2:\n";
		std::cout << set - set2;

		std::cout << "\nset1: " << set;
		std::cout << "set2: " << set2;
		std::cout << "set3: " << set3;

		std::cout << "\n\nOperacje na zbiorach\n\nSuma setow s3+=s1\n";
		set3 += set;
		std::cout << "set3: " << set3;
		std::cout << "\nRoznica setow s3-=s1\n";
		set3 -= set;
		std::cout << "set3: " << set3;
		std::cout << "\nCzesc wspolna setow s3*=s2\n";
		set3 *= set2;
		std::cout << "set3: " << set3;
		Set<int> set4(set3);
		std::cout << "\nset4 utworzony konstruktorem kopiujacym s3: " << set4 << "size: " << set4.get_size();
		set.clear();
		std::cout << "\nWyczyszczony set1:" << set;
		set2.clear();
		std::cout << "\nWyczyszczony set2:" << set2;
		set3.clear();
		std::cout << "\nWyczyszczony set3:" << set3;
		set4.clear();
		std::cout << "\nWyczyszczony set4:" << set4;
	}
	catch(...){
		std::cout << "\n\nBlad w operacjach na setach typu int!!\n\n";
	}
	try{
		Set<std::string> set5;
		Set<std::string> set6;

		std::cout << "\n\nTest stringowych setow:\n";
		set5.add_element("ala");
		set5.add_element("ma");
		set5.add_element("kota");
		set6.add_element("tomek");
		set6.add_element("ma");
		set6.add_element("psa");

		std::cout << "\nset5: " << set5;
		std::cout << "set6: " << set6;

		std::cout << "\nsuma: " << set5 + set6;
		std::cout << "roznica: " << set5 - set6;
		std::cout << "cz. wspolna: " << set5 * set6;

		set5 += set6;
		std::cout << "\nset5 po dodaniu seta6: " << set5;
		set5.clear();
		std::cout << "\nWyczyszczony set5:" << set5;
		set6.clear();
		std::cout << "\nWyczyszczony set6:" << set6;
	}
	catch (...) {
		std::cout << "\n\nBlad w operacjach na setach typu string!!\n\n";
	}
	
}