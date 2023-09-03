#pragma once
#include <regex>
#include <iostream>
#include <string>

/*
Pracuj�c w lokalnym sklepie spo�ywczym zlecono Ci, zrobi� inwentaryzacj�
wszystkich produkt�w sumuj�c ich cen�. Znaj�c jednak dzia�anie funkcji
regex_iterator() postanawiasz wykorzysta� j� do zsumowania cen produkt�w.

Do wykonania zadania b�dzie Ci r�wnie� potrzebna funkcja std::stod(),
s�u��ca do zamiany typu string na typ double
*/

struct Zadanie5 {

    void result() {
        std::regex reg("\\d+\\.\\d+");
        std::sregex_iterator it(lista.begin(), lista.end(), reg);
        std::sregex_iterator end;

        double cena = 0;

        while (it != end)
        {
            std::smatch match = *it;
            cena += std::stod(match.str());
            it++;
        }
        std::cout <<"Zadanie 5\nLaczna suma produktow: " << cena;

    }

    std::string lista = "Kawa Lavazza Crema e Gusto - 28.50 z�"
        "Mleko UHT 3,2% - 2.75 z�"
        "Ser gouda tarty - 11.90 z�"
        "Chleb pszenny razowy - 4.50 z�"
        "Mas�o ekstra - 8.20 z�"
        "Jajka klasy L - 0.50 z�/szt."
        "Kie�basa wiejska z dzika - 23.70 z�"
        "Jogurt naturalny 2,0% - 2.60 z�"
        "Twar�g p�t�usty - 6.90 z�"
        "Kabanosy ostra w�dka - 15.50 z�"
        "Piwo jasne pe�ne - 3.80 z�"
        "Makaron spaghetti - 3.20 z�"
        "Czekolada mleczna - 4.99 z�"
        "Filet z �ososia - 34.90 z�/kg"
        "Szynka parme�ska - 99.99 z�/kg"
        "Serek wiejski - 3.50 z�"
        "Ketchup �agodny - 4.80 z�"
        "D�em truskawkowy - 6.20 z�"
        "Oliwa z oliwek extra virgin - 18.50 z�";
};

