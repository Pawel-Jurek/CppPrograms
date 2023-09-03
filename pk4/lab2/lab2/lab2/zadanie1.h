#pragma once
#include <regex>
#include <iostream>

/*
Kto� pozamienia� niekt�re s�owa z pocz�tku ksi��ki na ananasy!

U�ywaj�c biblioteki <regex> usu� slowa "ananasa", "Ananasa", "ANANASA" z podanego tekstu.
*/

struct Zadanie1 {

	void result() {
		std::regex ananas ("ananasa|Ananasa|ANANASA");
		text = std::regex_replace(text, ananas, "");
		std::cout<<"Zadanie 1\nTekst po usunieciu ananasow:\n" << text << "\n\n";
	}

	std::string text = "Przychodzisz do mojego domu w dzien slubu mojego Ananasa"
		"i prosisz mnie o dokonanie ananasa, i mowisz - tu glos ananasa"
		"stal sie szyderczym przedrzeznianiem - zaplace, ile Ananasa zechce."
		"Nie, nie jestem obrazony, ale co ja zrobilem, ze mnie traktujesz tak bez ANANASA?";
};
