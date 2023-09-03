#pragma once
#include <string>
#include <vector>
#include <regex>

/*
Przychodzi do ciebie redaktor znanej gazety,

Cze��, potrzebuj� twojej pomocy w napisaniu wyra�enia regularnego na adres email.
Chc� mie� narz�dzie, kt�re pozwoli mi na �atwe wyci�ganie adres�w email z r�nych �r�de�,
takich jak strony internetowe czy newslettery.

Czy m�g�by� napisa� dla mnie wyra�enie regularne, kt�re b�dzie wystarczaj�co skuteczne,
aby wy�apa� adresy email o r�nych formatach, takich jak:
"nazwa@domena.com" czy te� "nazwa@subdomena.domena.com"?
*/

struct Zadanie2 {

	void result() {
		std::regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		std::cout << "Zadanie 2\n";
		for (auto& email : email_addresses)
		{
			if (std::regex_match(email, emailRegex))
				std::cout << "Email: " << email << " <- jest poprawny\n";
			else
				std::cout << "Email: " << email << " <- jest niepoprawny\n";
		}
		std::cout << "\n";
	}

	std::vector<std::string> email_addresses = {
		"shqtjm27kz@hotmail.com",
		"krazycaucazian@@otpku.com",
		"mattrkid@otpku.mailcuk.com",
		"yuliyabikb.ulato@timeroom.com",
		"jan.kowalski@student.polsl.com",
	};
};
