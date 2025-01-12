
#include "pch.h"
#include <iostream>

using namespace std;

constexpr auto SIZE = 50;

void print_arr(float a[SIZE][SIZE], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			cout << a[i][j] << "         ";
		}
		cout << endl;
	}
}

void reset_arr(float a[SIZE][SIZE], unsigned n)
{
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < n; j++)
			a[i][j] = 0;
}

float determ(float a[SIZE][SIZE])
{
	float det;
	det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
	return det;
}

void obrat(float a[SIZE][SIZE], float newArr[SIZE][SIZE])
{
	float det = determ(a);
	newArr[0][0] = a[1][1] / det;
	newArr[0][1] = -a[0][1] / det;
	newArr[1][0] = -a[1][0] / det;
	newArr[1][1] = a[0][0] / det;
}

void minusa(float first[SIZE][SIZE],float second[SIZE][SIZE],float result[SIZE][SIZE])
{
	unsigned n = 2;
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < n; j++)			
			result[i][j] = first[i][j] - second[i][j];
}

void multi(float first[SIZE][SIZE], float second[SIZE][SIZE], float result[SIZE][SIZE])
{
	unsigned n = 2;
	float temp;
	for (unsigned i = 0; i < n; i++) 
	{
		for (unsigned l = 0; l < n; l++)
		{
			temp = 0;
			for (unsigned j = 0; j < n; j++)
			{
				temp += first[i][j] * second[j][l];
			}
			result[i][l] = temp;
		}
	}
}

void multi_value(float first[SIZE][SIZE], float value,float result[SIZE][SIZE])
{
	unsigned n = 2;
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < n; j++)
			result[i][j] = first[i][j] * value;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	unsigned n = 4;
	float a[SIZE][SIZE] = { {-1,-1,-1,-2},{2,3,4,3},{-2,0,1,-6}, {-2,-2,-3,-3} };
	float M[SIZE][SIZE];
	M[0][0] = a[0][0];
	M[0][1] = a[0][1];
	M[1][0] = a[1][0];
	M[1][1] = a[1][1];
	float N[SIZE][SIZE];
	N[0][0] = a[0][2];
	N[0][1] = a[0][3];
	N[1][0] = a[1][2];
	N[1][1] = a[1][3];
	float P[SIZE][SIZE];
	P[0][0] = a[2][0];
	P[0][1] = a[2][1];
	P[1][0] = a[3][0];
	P[1][1] = a[3][1];
	float Q[SIZE][SIZE];
	Q[0][0] = a[2][2];
	Q[0][1] = a[2][3];
	Q[1][0] = a[3][2];
	Q[1][1] = a[3][3];
	cout << "Матрица A:" << endl;
	print_arr(a, n);
	cout << "Матрица M:" << endl;
	print_arr(M, 2);
	cout << "Матрица N:" << endl;
	print_arr(N, 2);
	cout << "Матрица P:" << endl;
	print_arr(P, 2);
	cout << "Матрица Q:" << endl;
	print_arr(Q, 2);
	/*Находим обратные матрицы*/
	float obrM[SIZE][SIZE];
	obrat(M, obrM);
	cout << "Матрица обратная M:" << endl;
	print_arr(obrM, 2);
	float obrQ[SIZE][SIZE];
	obrat(Q, obrQ);
	cout << "Матрица обратная Q:" << endl;
	print_arr(obrQ, 2);
	/*Находим X*/
	float temp[SIZE][SIZE];
	float temp_two[SIZE][SIZE];
	multi(N, obrQ, temp);
	multi(temp, P, temp_two);
	minusa(M, temp_two, temp);
	cout << "M-N*Q^(-1)*P" << endl;
	print_arr(temp, 2);
	float X[SIZE][SIZE];
	obrat(temp, X);
	cout << "Матрица X:" << endl;
	print_arr(X, 2);
	/*Находим V*/
	float V[SIZE][SIZE];
	multi(P, obrM, temp);
	multi(temp, N, temp_two);
	minusa(Q, temp_two, temp);
	obrat(temp, V);
	cout << "Матрица V:" << endl;
	print_arr(V, 2);
	/*Находим U*/
	float U[SIZE][SIZE];
	multi_value(V, -1, temp);
	multi(temp, P, temp_two);
	multi(temp_two, obrM, U);
	cout << "Матрица U:" << endl;
	print_arr(U, 2);
	/*Находим Y*/
	float Y[SIZE][SIZE];
	multi_value(X, -1, temp);
	multi(temp, N, temp_two);
	multi(temp_two, obrQ, Y);
	cout << "Матрица Y:" << endl;
	print_arr(Y, 2);

	system("pause");
}


