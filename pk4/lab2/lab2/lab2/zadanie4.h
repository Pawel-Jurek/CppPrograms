#pragma once
#include <regex>
#include <iostream>

/*
Przegl�daj�c zlecone Ci zadania, natrafiasz na zagadk�:

Jest to co�, czego u�ywasz ka�dego dnia, ale nie zwracasz na to uwagi.
Mo�na to znale�� w wielu miejscach, ale zwykle jest to niewidoczne dla oka.
Nawet pomimo tego �e jest to niewidoczne, jest w stanie rozdzieli� dwa s�owa.
Odnale�� to musisz wykorzystuj�c na raz dwa z przydatnych znak�w z biblioteki <regex>
Co to jest?
*/

struct Zadanie4 {

	void result() {
		std::regex reg("(\\d|\\s)");
		std::string anwser = std::regex_replace(zadanie, reg, "");
		std::cout << "Zadanie 4\nRozwiazaniem zagadki jest: " << anwser << "\n\n";
	}

	std::string zadanie = "1113 p223431 37u71532374 s71  43374t7372  16 1 54y67 16722 73132 z 4 n 6 2a 8771 k";
};

