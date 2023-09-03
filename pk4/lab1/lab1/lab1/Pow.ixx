export module Pow;

export double Potega(int a, int n)
{
	int result=1;
	bool negation = false;
	if (n < 0)
	{
		n = -n;
		negation = true;
	}
	for (int i = 0; i < n; ++i)
	{
		result *= a;
	}
	if (!negation)
	{
		return result;
	}
	return 1. / result;
	
};