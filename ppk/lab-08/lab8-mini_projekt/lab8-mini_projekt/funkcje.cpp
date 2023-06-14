#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "funkcje.h"

bool readParams(int argc, char** argv, Params& params)
{
	for (int i = 1; i < argc - 1; ++i)
	{
		std::string cur = argv[i];
		if (cur == "-i")
			params.inputFile = argv[++i];
		if (cur == "-o")
			params.outputFile = argv[++i];
	}
	return params.inputFile != "";
}
void help(const std::string& progName)
{
	std::cerr << "Witaj w programie <jakas_fikusna_nazwa>\n";
	std::cerr << "Uzywa sie go tak:\n";
	std::cerr << progName << " -i <inputFile>\n";
}

std::string tresc_polecenia(std::string linia_instrukcji_ze_spacjami)
{
	if ((linia_instrukcji_ze_spacjami.find('r') != std::string::npos) || (linia_instrukcji_ze_spacjami.find('c') != std::string::npos))
		return  linia_instrukcji_ze_spacjami.substr(linia_instrukcji_ze_spacjami.find_first_of("cr")-1);
		
}
std::pair<int, std::string> interpretacja_instrukcji(std::string instr)
{
	std::string linia = tresc_polecenia(instr);
	if (linia.find_first_of(" ")==0) 
		linia.erase(linia.begin()+linia.find_first_of(" "));
	if (linia.find("remove ") != std::string::npos)
	{
		return std::make_pair(Remove_par, parametry_instrukcji(linia));
	}
	if (linia.find("count ") != std::string::npos)
	{
		return std::make_pair(Count_par, parametry_instrukcji(linia));
	}
	if (linia.find("remove")!=std::string::npos) 
	{
		return std::make_pair(Remove, "-");
	}	
	if (linia.find("count")!=std::string::npos)
	{
		return std::make_pair(Count, "-");
	}	
	if (linia.find("replace ") != std::string::npos)
	{
		return std::make_pair(Replace, parametry_instrukcji(linia));
	}
}
std::string parametry_instrukcji(std::string instrukcja)
{
	int i = instrukcja.find_first_of(" ")+1;
	std::string parametry;
	while (97 <= instrukcja[i] && instrukcja[i] <= 122)
	{
		parametry += instrukcja[i];
		i++;
		if (instrukcja[i] == ' ')
		{
			parametry += instrukcja[i];
			i++;
		}
	}
	return parametry;
}
void remove(std::string& tekst)
{
	for (int i = 0;i < tekst.size();i++)
	{
		if (tekst[i] == 9 || tekst[i] == 32) tekst.erase(i,1);
	}
}
void odwroc(std::vector<int>&poz)
{
	for (int i = 0; i < poz.size() / 2;i++)
	{
		std::swap(poz[i], poz[poz.size() - i - 1]);
	}
}
void remove_xyz(std::string& tekst, std::string parametry)
{
	std::size_t m = 0;
	std::vector<int> pozycje;
	do
	{
		m = tekst.find_first_of(parametry, m);
		if (m != std::string::npos)
		{
			pozycje.push_back(m);
			m++;
		}

	} while (m != std::string::npos);
	
	odwroc(pozycje);
	int pom = 0;


	while (!pozycje.empty())
	{
		tekst.erase(tekst.begin()+pozycje.back()-pom);
		pozycje.pop_back();
		pom++;
	}
}	
void count(std::string& tekst)
{
	int spa = 0,tab = 0;
	for (int i = 0;i < tekst.size();i++)
	{
		if (tekst[i] == 9) tab++;
		if(tekst[i] == 32) spa++;
	}
	tekst = "space: "+std::to_string(spa)+"    tab: "+ std::to_string(tab);
}
int zliczacz_znakow(std::string tekst,char litera)
{
	std::size_t m = 0;
	int licznik=0;
	do
	{
		m = tekst.find_first_of(litera, m); 
		if (m != std::string::npos)
		{
			licznik++;
			m++;
		}
			
	} while (m != std::string::npos);
	return licznik;
}
void count_xyz(std::string& tekst, std::string parametry)
{
	std::string tekst_wyj = "";
	std::string linia_znakow = "";
	for (int i = 0;i < parametry.size();i++)
	{
		tekst_wyj += parametry[i];
		tekst_wyj+=": " + std::to_string(zliczacz_znakow(tekst, parametry[i])) + "  ";
	}
	tekst = tekst_wyj;
}
void replace_x_y(std::string& tekst, std::string parametry)
{
	int i = 0;
	std::string par1 = parametry.substr(0, parametry.find_first_of(' '));
	std::string par2 = parametry.substr(parametry.find_first_of(' ')+1);
	std::vector<std::string>wyrazy = {};
	std::string wyraz;
	while (i < tekst.size())
	{
		if (tekst[i] != ' ')
			wyraz += tekst[i];
		else
		{
			if (wyraz == par1)
				wyrazy.push_back(par2);
			else wyrazy.push_back(wyraz);
			wyraz = {};
		}
		i++;
	}
	tekst = "";
	for (int j = 0;j < wyrazy.size();j++)
	{
		tekst += wyrazy[j]+" ";
	}
}
bool printToScreen(const Params& params)
{
	std::ifstream in(params.inputFile);
	if (!in)
	{
		std::cerr << "Error: cannot open file " << params.inputFile << "\n";
		return false;
	}
	std::string line;
	std::vector<std::string> tekst;
	std::vector<std::pair<int, std::string>> polecenia;
	int i = 0;
	bool czy_wyswietlac = true;
	while (std::getline(in, line))
		if (line != "" && line.find('%') != std::string::npos) {
			if (line.find('%') != std::string::npos)
				polecenia.push_back(interpretacja_instrukcji(line.substr(line.find('%'))));
			else
				polecenia.push_back(std::make_pair(0,"-"));
			tekst.push_back(line.substr(0, line.find('%')));
			switch (polecenia[i].first)
			{
			case(Remove):
				remove(tekst[i]);
				break;

			case(Remove_par):
				remove_xyz(tekst[i], polecenia[i].second);
				break;

			case(Count):
				count(tekst[i]);
				break;

			case(Count_par):
				count_xyz(tekst[i], polecenia[i].second);
				break;
			case(Replace):
				replace_x_y(tekst[i], polecenia[i].second);
				break;
			default:
				czy_wyswietlac = false;
				break;
			}

			if (czy_wyswietlac)
			{
				std::cout << "Tekst przez zmiana: " << line << "\n";
				std::cout << "Tekst po zmianie  : " << tekst[i] << "\n\n";
			}
			i++;
		}
	in.close();
	std::ofstream on(params.outputFile);
	if (!on)
	{
		std::cerr << "Error: cannot open file " << params.outputFile << "\n";
		return false;
	}

	for (int j = 0; j < i; j++) 
		on << tekst[j] << "\n";
	on.close();
	return true;
	
}


