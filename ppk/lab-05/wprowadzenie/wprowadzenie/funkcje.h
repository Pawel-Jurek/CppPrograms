#pragma once
#include <iostream>
#include <vector>

int rand_int(int low , int high);
int dodaj(int a, int b);
void zmien(int &a, int &b);
void wypelnij(int t[], int roz);
double potega(int wykladnik, double podstawa);
int odleglosc(int a, int b);
void wyswietl_tablice(int t[], int roz);
void tablica_od_konca_rek(int t[], int roz);
int fib_rek(int n);
int fib_it(int n);
int wyznaczniki(double &x1, double &x2);
void segregacja(int t[], int rozmiar);
void rown_kwadr(double a, double b, double c, double &x1, double &x2);
int hanoi(int n, int mp , int md);
void wypelnij_wektor(std::vector<int> &tab);
void wypisz_tab_wek(std::vector<int> tab);
std::pair<int,int> minmax(std::vector<int> tablica);
void segr_wek(std::vector<int> &tab);