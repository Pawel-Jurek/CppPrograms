#include <iostream>
using namespace std;
int main()
{
	int a, b;
	char znak;
	cout << "Podaj pierwsza liczbe: " << endl;
	cin >> a;
	cout << "Podaj znak dzialania (+,-,*,/): " << endl;
	cin >> znak;
	cout << "Podaj druga liczbe: " << endl;
	cin >> b;
	switch (znak)
	{
	case '+':
	{
		cout << "Wynik dodawania wynosi: " << a + b << endl;
		break;
	}
	default:
		break;
	}
}



