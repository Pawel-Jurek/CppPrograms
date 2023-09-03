export module Square;
import Pow;
export class Kwadrat
{
	double dlugosc_boku;
public:
	Kwadrat() :dlugosc_boku(1) {};
	Kwadrat(double a) :dlugosc_boku(a) {};
	double Pole() {
		//return dlugosc_boku * dlugosc_boku;		rozwi¹zanie dla zadania 2
		return Potega(dlugosc_boku, 2);
	}
};