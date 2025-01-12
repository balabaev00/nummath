

#include "pch.h"
#include <iostream>
#include <locale.h>

using namespace std;

const unsigned SIZE = 50;
const unsigned n = 5;

void print_arr(float arr[SIZE][SIZE], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n + 1; j++)
		{
			if (j != n)
			{
				cout.precision(3);
				cout << arr[i][j] << "	 ";
			}
		}
		cout << endl;
	}

}

void arr_null(float arr[SIZE][SIZE], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < n + 1; j++)
			arr[i][j] = 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	float a[SIZE][SIZE] = { { -0.74,0.47,-0.15,-0.3,0.81 }, { 0.01,-0.65,-0.64,0.58,-0.04}, { -0.33,0.01,-0.61,-0.95,0.19},
	{ -0.96,-0.42,-0.03,0.68,-0.71 } , {0.07,0.73,-0.97,0.84,-0.35} };
	float c[SIZE] = { -0.97, -0.86,-0.82,0.99,-0.11 };
	float y[SIZE];
	float x[SIZE];
	float t[SIZE][SIZE];
	float b[SIZE][SIZE];
	arr_null(t, n);
	arr_null(b, n);
	float sum;
	float sum2;

	// Первый слой
	for (int i = 0; i < n; i++)
	{
		b[i][0] = a[i][0];
		t[0][i] = a[0][i] / b[0][0];
	}

	cout << "Матрица T" << endl;
	print_arr(t, n);

	cout << "Матрица B" << endl;
	print_arr(b, n);

	// Второй шаг второго слоя
	for (int k = 1; k < n; k++)
	{
		for (int i = k; i < n; i++)
		{
			sum = 0;
			for (int m = 0; m < k; m++)
				sum += b[i][m] * t[m][k];
			b[i][k] = a[i][k] - sum;
		}
		for (int j = k + 1; j < n; j++)
		{
			sum = 0;
			for (int m = 0; m < k; m++)
				sum += b[k][m] * t[m][j];
			t[k][j] = (a[k][j] - sum) / b[k][k];
		}
	}

	for (int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				t[i][j] = 1;
		}


	cout << "Матрица T" << endl;
	print_arr(t, n);

	cout << "Матрица B" << endl;
	print_arr(b, n);
	
	y[0] = c[0]/b[0][0];
	for (int i = 1; i < n; i++)
	{
		sum = 0;
		for (int m = 0; m < i; m++)
			sum += b[i][m] * y[m];
		y[i] = (c[i] - sum) / b[i][i];
	}

	// Вывод y на экран
	cout << "Вектор Y" << endl;
	for (int i = 0; i < n; i++)
	{
		cout.precision(3);
		cout << y[i] << endl;
	}

	x[n - 1] = y[n - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		sum = 0;
		for (int m = i + 1; m < n; m++)
			sum += t[i][m] * x[m];
		x[i] = y[i] - sum;
	}

	// Вывод y на экран
	cout << "Вектор X" << endl;
	for (int i = 0; i < n; i++)
	{
		cout.precision(3);
		cout << x[i] << endl;
	}

	system("pause");
}


