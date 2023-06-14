#include "funkcje.h"
#include "observer.h"

int main()
{
	List lista;
	lista.setAlgo(std::make_shared<PrzezWybor>());
	lista.sort("a.txt", "a.arch");
}