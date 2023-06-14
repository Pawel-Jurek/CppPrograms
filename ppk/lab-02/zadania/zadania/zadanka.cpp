#include <iostream>
#include <cmath>
using namespace std;
void zadanie1()
{
	int a, b;
	char znak;
	cout << "Podaj pierwsza liczbe,  operator(+,-,*,/,%), druga liczbe: " << endl;
	cin >> a >> znak >>b;

	switch (znak)
	{
	case '+':
	{
		cout << "Wynik dodawania wynosi: " << a + b << endl;
		break;
	}
	case '-':
	{
		cout << "Wynik odejmowania wynosi: " << a - b << endl;
		break;
	}
	case '*':
	{
		cout << "Wynik mnozenia wynosi: " << a * b << endl;
		break;
	}
	case '/':
	{
		if (b == 0) cout << "Nie mnoz przez 0";
		else cout << "Wynik dzielenia wynosi: " << a / b << endl;
		break;
	}
	case '%':
	{
		cout << "Reszta z dzielenia wynosi: " << a % b << endl;
		break;
	}
	default:
		break;
	}
}

void zadanie2()
{
	int A, B;
	cout << "Podaj ilosc osob miesczaca sie w jednej sali: "; cin >> A;
	cout << "Podaj calkowita ilosc osob: "; cin >> B;
	cout << "\nIlosc potrzebnych sal: ";
	if (B % A != 0) cout << B / A + 1;
	else cout << A / B;
}

void zadanie3i4()
{
	double a, b, c;
	double delta;
	cout << "Podaj kolejno wpolczynniki przy x^2, x i wyrazie wolnym" << endl;
	cout << "a,b,c:"; cin >> a >> b >> c;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				cout << "Tozsamosc";
			else cout << " Sprzecznosc";
		}
		else cout << "Wynik: " << -b / a;
	}
	else 
	{
		delta = b * b - (4 * a * c);
		if (delta > 0)
		{
			cout << "Rozwiazaniami sa liczby: " << (-b - sqrt(delta)) / (2 * a) << " oraz " << (-b + sqrt(delta)) / (2 * a);
		}
		else if (delta == 0)
		{
			cout << "Rozwiazeniem jest: " << -b / (2 * a);
		}
		else
		{
			delta *= -1;
			cout << "Rozwiazaniami sa liczby: " << -b / (2 * a) <<" "<< -sqrt(delta)/(2*a) << "i oraz " << -b / (2 * a)<< " " << sqrt(delta) / (2 * a) <<"i";
		}
	}
}

void zadanie5()
{
	int xa, ya, yo, yp, xp, xo, odleglosc1ap, odleglosc2ao;
	cout << "Podaj wspolrzedne punktu a (x,y): "; cin >> xa >> ya;
	cout << "Podaj wspolrzedne punktu o (x,y): "; cin >> xo >> yo;
	cout << "Podaj wspolrzedne punktu p (x,y): "; cin >> xp >> yp;

	cout << "\nPunkt a znajduje sie blizej punktu: ";
	odleglosc1ap = sqrt(pow((xa - xp), 2)+ pow((ya - yp), 2));
	odleglosc2ao = sqrt(pow((xa - xo), 2)+ pow((ya - yo), 2));
	if (odleglosc1ap < 0) odleglosc1ap * -1;
	if (odleglosc2ao < 0) odleglosc2ao * -1;
	if (odleglosc1ap < odleglosc2ao) cout << "P";
	else if (odleglosc1ap > odleglosc2ao) cout << "O";
	else cout << "Znajduja sie w takiej samej odleglosci";
}

void zadanie6()
{
	double a1, a2, b1, b2, c1, c2, x, y, W, Wx, Wy;

	cout << "a1x+b1y=c1\na2x+b2y=c2" << endl << endl;

	cout << "podaj a1:";cin >> a1;
	cout << "podaj b1:";cin >> b1;
	cout << "podaj c1:";cin >> c1;
	cout << "podaj a2:";cin >> a2;
	cout << "podaj b2:";cin >> b2;
	cout << "podaj c2:";cin >> c2;
	cout << endl;

	W = a1 * b2 - a2 * b1;
	Wx = c1 * b2 - c2 * b1;
	Wy = a1 * c2 - a2 * c1;

	if (W)
	{
		x = Wx / W;
		y = Wy / W;
		cout << "x=" << x << endl << "y=" << y << endl;
	}
	else if (Wx == 0 && Wy == 0)
		cout << "uklad nieoznaczony";
	else
		cout << "uklad sprzeczny";
	
}
int main()
{
	//zadanie1();
	//zadanie2();
	//zadanie3i4();
	//zadanie5();
	zadanie6();
}



