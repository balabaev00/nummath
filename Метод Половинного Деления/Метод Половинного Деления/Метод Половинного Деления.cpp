

#include "pch.h"
#include <iostream>

using namespace std;

double f(double x)
{
	return 4 * x + pow(2, x) + 6;
}
double df(double x)
{
	return  4 + pow(2, x)*log(2);
}

int main()
{
	double a = -10, b = 10, eps = 0.0001;
	double c, x;
	while (b - a > 2 * eps)
	{
		c = (a + b) / 2;
		if (f(a)*f(c) < 0)
		{
			b = c;
		}
		else
		{
			if (f(b)*f(c) < 0)
			{
				a = c;
			}
		}
		x = (a + b) / 2;
		cout << x << endl;
	}
	cout << "Result" << x << endl;
	system("pause");
}


