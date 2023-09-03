#pragma once
#include <regex>
#include <iostream>

/*
Ktoœ pozamienia³ niektóre s³owa z pocz¹tku ksi¹¿ki na ananasy!

U¿ywaj¹c biblioteki <regex> usuñ slowa "ananasa", "Ananasa", "ANANASA" z podanego tekstu.
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
