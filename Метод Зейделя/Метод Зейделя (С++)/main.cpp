
#include "pch.h"
#include <iostream>

using namespace std;

const unsigned SIZE = 50;
const unsigned n = 5;
const float e = 0.001;


/*Обнуление двумерного массива*/
void null_array(float a[SIZE][SIZE], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < n; j++)
			a[i][j] = 0;
}

/*Обнуление одномерного массива*/
void null_one_array(float a[SIZE], unsigned n)
{
	for (unsigned j = 0; j < n; j++)
		a[j] = 0;
}

/*Вывод двумерного массива на экран*/
void print_array(float a[SIZE][SIZE], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
			cout << a[i][j] << "	";
		cout << endl;
	}
}

/*Вывод одномерного массива на экран*/
void print_one_array(float a[SIZE], unsigned n)
{
	for (unsigned j = 0; j < n; j++)
		cout << a[j] << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	float a[SIZE][SIZE] = { {25,4,7,-3,-1},{-8,42,8,-9,-3},
	{-6,4,34,4,-8},{-8,4,7,36,9},{6,-6,-2,-4,29} };
	float b[SIZE] = { 32,60,84,96,23 };
	float x_old[SIZE];
	float x[SIZE];
	float m = 0;
	float s = 0;
	float v = 0;
	float r = 0;
	/*Обнуление массивов*/
	null_one_array(x, n);
	null_one_array(x_old, n);
	/*Вывод начальных значений*/
	cout << "Матрица a" << endl;
	print_array(a, n);
	cout << "Матрица b" << endl;
	print_one_array(b, n);
	/*Проверка условия на совместимость*/
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			if (j != i)
			{
				if (abs(a[i][j] >= abs(a[i][i])))
				{
					cout << "Не совместимы" << endl;
					break;
				}
			}
		}
	}
	/*Основной метод*/
	do
	{
		for (unsigned i = 0; i < n; i++)
			x_old[i] = x[i];
		m = 0;
		for (unsigned i = 0; i < n; i++)
		{
			s = 0;
			for (unsigned j = 0; j < n; j++)
			{
				if (j < i)
					s += a[i][j] * x[j];
				else
					if (j > i)
						s += a[i][j] * x_old[j];
				x[i] = (b[i] - s) / a[i][i];
			}
			m = abs(x_old[i] - x[i]);
		}
	} while (m > e);
	cout << "Массив x" << endl;
	print_one_array(x, n);
	system("pause");
}
