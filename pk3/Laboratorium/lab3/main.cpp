#include <iostream>
#include "text.h"

int main()
{
	Text jakistext("przyklad");
	std::cout << "Pierwszy tekst:\n";
	std::cout << "'" << jakistext.get_text() << "'\ns = ";
	std::cout << jakistext.get_size();

	Text jakistext2;
	std::cout << "\n\nDrugi tekst:";
	std::cout << "\n'" << jakistext2.get_text() << "'\ns = ";
	std::cout << jakistext2.get_size();

	std::cout << "\n\nPorownanie roznych tekstow:\n";
	std::cout << (jakistext == jakistext2 ? "equal" : "not equal");

	jakistext2 = jakistext;

	std::cout << "\n\nTekst drugi po ustawieniu go na wyrazenie z tekstu pierwszego:";
	std::cout << "\n'" << jakistext2.get_text() << "'\ns = ";
	std::cout << jakistext2.get_size();

	std::cout << "\n\nPorownanie tych samych tekstow:\n";
	std::cout << (jakistext == jakistext2 ? "equal" : "not equal");

	std::cout << "\n\nPo dodaniu tekstow\n";
	std::cout << "'" <<(jakistext + jakistext2) << "'";
	
	Text text3(jakistext(2, 3));
	std::cout << "\n\nWyciety zbior tekstu jako paramtetr do kontruktora kopiujacego:\n";
	std::cout << "'" << text3.get_text()<< "'";
	
	text3--;
	
	std::cout << "\n\nPo odwroceniu:\n";
	std::cout << "'" << text3.get_text() << "'";
}