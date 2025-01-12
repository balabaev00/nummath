#include "pch.h"
#include <iostream>
#include <math.h>

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
	double a = -2, b = -1, e = 0.0001;
	while (fabs(b - a) > e)
	{
		a = b - f(b) / df(b);
		b = b - (a - b) / (f(a) - f(b))*f(b);
	}
	cout << b << endl;
	system("pause");
}