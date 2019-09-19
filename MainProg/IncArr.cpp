#include <iostream>

using namespace std;

/**
	Создание массива
**/
float** makeArray(unsigned n, unsigned m)
{
	float **Arr = new float *[n];

	for (int i = 0; i < n; i++)
		Arr[i] = new float[m];

	return Arr;
}

/**
	Инициализация массива
**/
float** incArray(float** Arr, unsigned n, unsigned m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (j != m - 1)
				cout << "a" << i+1 << j+1 << " = ";
			else
				cout << "a" << i+1 << ", n+1 = ";
			cin >> Arr[i][j];
		}
	return Arr;
}