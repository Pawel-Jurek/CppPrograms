/** @file */

#include <iostream>
#include <string>
#include <fstream>
#include "funkcje.h"



int main(int argc, char** argv)
{	
	Params params;
	if (!czytaj_Parametry(argc, argv, params))
	{
		pomoc(argv[0]);
		return 1;
	}
	if (decyzjator(params))
		return 0;
	return 1;

}