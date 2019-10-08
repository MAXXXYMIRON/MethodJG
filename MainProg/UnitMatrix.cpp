#include<iostream>
#include<cstdlib>
#include"UnitMatrix.h"

using namespace std;

int *ArrWithLineNumUsed;
int LenAWLNU = 0;

/**
	Проверка на повторное использование строки
	Запись номера строки, для исключения её повторного использовани
**/
bool notReturnRow(unsigned ColCheck)
{
	for (int i = 0; i < LenAWLNU; i++)
		if (ColCheck == ArrWithLineNumUsed[i]) return 0;

	for (int i = 0; i < LenAWLNU; i++)
		if (ArrWithLineNumUsed[i] == -1)
		{
			ArrWithLineNumUsed[i] = ColCheck;
			break;
		}
	return 1;
}


/**
	Поиск не нулевго эл столбца
	Вернет номер строки, в которой находится элемент
**/
int searchNotZeroCol(float** Arr, unsigned ColCheck, unsigned Row)
{
	for (int i = 0; i < Row; i++)

		if (Arr[i][ColCheck] != 0 && notReturnRow(i))

			return i;
}


/**
	Деление строки, с этим эл на этот эл
**/
float* splitLine(float* Row, unsigned Col)
{
	float divider = 0;

	for (int i = 0; i < Col - 1; i++)
		if (Row[i] != 0)
		{
			divider = Row[i];

			for (int j = i; j < Col; j++)
				Row[j] /= divider;

			break;
		}
	return Row;
}


/**
	Домножение этой строки на эл других строк,
	(кроме строк с нулём) и вычитание из них этой строки
**/
float** zeroingLineItem(float** Arr, unsigned Row, unsigned Col, unsigned numString, unsigned numColumn)
{
	for (int i = 0; i < Row; i++)
		if (i != numString)
			Arr[i] = subLine(Arr[i], Arr[numString], Col, numColumn);

	return Arr;
}


/**
	Вычитание одной строки из другой
**/
float* subLine(float* Minuend, float* Subtrahend, unsigned Col, unsigned numColumn)
{
	float multi = Minuend[numColumn];

	for (int i = 0; i < Col; i++)
	{
		Minuend[i] -= Subtrahend[i] * multi;
	}

	return Minuend;
}


/**
	Инициализация массива с номерами исп. строк
**/
void initArrWithLineNumUsed(int Len)
{
	ArrWithLineNumUsed = new int(Len);
	for (int i = 0; i < Len; i++)
	{
		ArrWithLineNumUsed[i] = -1;
	}
}

/**
	Рекурсивный вызов функций
	numIteration - номер столбца, по которому проводится поиск не нулевого эл
**/
float** recCallToFunc(float** Arr, unsigned Row, unsigned Col, unsigned numIteration)
{
	//Находим не нулевой эл. в столбце numIteration и делим строку на него
	int StringUse = searchNotZeroCol(Arr, numIteration, Row);
	Arr[StringUse] = splitLine(Arr[StringUse], Col);

	//Домнажаем полученную строку на элементы столбца из других строк 
	//и отнимаем её из них
	Arr = zeroingLineItem(Arr, Row, Col, StringUse, numIteration);

	Arr = (numIteration != Col - 2) ? recCallToFunc(Arr, Row, Col, numIteration + 1) : Arr;

	return Arr;
}

/**
	Преобразование матрицы по методу Жардана-Гауса
**/
float** matrixJardanGaus(float** Arr, unsigned Row, unsigned Col)
{
	//Инициализация массива с номерами использованных строк
	LenAWLNU = Row;
	initArrWithLineNumUsed(LenAWLNU);
	
	//Приведение матрицы к еденичному виду
	Arr = recCallToFunc(Arr, Row, Col, 0);

	return Arr;
}


/**
	Вывод результата
**/
void outResult(float** Arr, unsigned Row, unsigned Col)
{
	cout << endl;

	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			if (Arr[i][j] == 1)
			{
				cout << "x" << j + 1 << " = ";
				cout.width(10);
				cout << Arr[i][Col - 1] << endl;
				break;
			}
}