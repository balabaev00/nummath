#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;
double f(double x)
{
	return 4*x+pow(2,x)+6;
}
double df(double x)
{
	return  4+pow(2,x)*log(2);
}
int main()
{
	double a = -2, b = -1, e = 0.0001;
	double newX = 0;
	double oldX = 0;
	
	if (f(newX)*f(a) < 0)
	{
		oldX = b;
		b = newX;
	}
	else 
		if (f(newX)*f(b) < 0)
		{
			oldX = a;
			a = newX;
		}
	while (abs(oldX - newX) > e)
	{
		oldX = newX;
		newX = (a*f(b) - b * f(a)) / (f(b) - f(a));
		if(f(newX)*f(a) < 0)
		{
			oldX = b;
			b = newX;
		}
		else
			if (f(newX)*f(b) < 0)
			{
				oldX = a;
				a = newX;
			}
	}
	cout << newX << endl;
	system("pause");
}