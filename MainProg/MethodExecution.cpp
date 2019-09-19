#include<iostream>
#include<locale>
#include"IncArr.h"

using namespace std;

void main()
{
	setlocale(0, "");

	unsigned n, m;


	cout << "Кол-во строк = "; cin >> n;
	cout << "Кол-во столбцов (учитывая результирующий) = "; cin >> m;

	float **SLAU = makeArray(n, m);


	cout << "Инициализируйте матрицу (последний - ответ)" << endl;

	SLAU = incArray(SLAU, n, m);




	system("pause");
}