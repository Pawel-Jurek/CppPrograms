#include <iostream>
#include <string>
#include <fstream>
#include "funkcje.h"


int main(int argc, char** argv)
{
	Params params;
	if (!readParams(argc, argv, params))
	{
		help(argv[0]);
		return 1;
	}
	if (printToScreen(params))
		return 0;
	return 1;

}

