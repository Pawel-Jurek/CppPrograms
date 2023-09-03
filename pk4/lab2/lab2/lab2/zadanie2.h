#pragma once
#include <string>
#include <vector>
#include <regex>

/*
Przychodzi do ciebie redaktor znanej gazety,

Czeœæ, potrzebujê twojej pomocy w napisaniu wyra¿enia regularnego na adres email.
Chcê mieæ narzêdzie, które pozwoli mi na ³atwe wyci¹ganie adresów email z ró¿nych Ÿróde³,
takich jak strony internetowe czy newslettery.

Czy móg³byœ napisaæ dla mnie wyra¿enie regularne, które bêdzie wystarczaj¹co skuteczne,
aby wy³apaæ adresy email o ró¿nych formatach, takich jak:
"nazwa@domena.com" czy te¿ "nazwa@subdomena.domena.com"?
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
