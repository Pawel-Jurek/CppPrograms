#pragma once
#include<iostream>
#include<string>
#include<vector>
struct Params
{
	std::string inputFile;
	std::string outputFile;
};

bool readParams(int argc, char** argv, Params& params);
void help(const std::string& progName);
bool printToScreen(const Params& params);
enum opcje_edycji { Remove = 1, Remove_par, Count, Count_par, Replace, Wrong };
std::string tresc_polecenia(std::string linia_instrukcji_ze_spacjami);
std::pair<int, std::string> interpretacja_instrukcji(std::string instr);
std::string parametry_instrukcji(std::string instrukcja);
void remove(std::string& tekst);
void remove_xyz(std::string& tekst, std::string parametry);
void count(std::string& tekst);
void count_xyz(std::string& tekst, std::string parametry);
int zliczacz_znakow(std::string tekst, char litera);
void replace_x_y(std::string& tekst, std::string parametry);
void odwroc(std::vector<int>& poz);
bool save_to_file(const Params& params);

