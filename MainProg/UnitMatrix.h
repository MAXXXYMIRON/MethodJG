#pragma once

/**
	Поиск не нулевго эл столбца
**/
int searchNotZeroCol(float** Arr, unsigned ColCheck, unsigned Row);

/**
	Инициализация массива с номерами исп. строк
**/
void initArrWithLineNumUsed(int Len);

/**
	Проверка на повторное использование строки
	Запись номера строки, для исключения её повторного использования
**/
bool notReturnRow(unsigned ColCheck);


/**
	Деление строки, с этим эл на этот эл
**/
float* splitLine(float* Row, unsigned Col);

/**
	Домножение этой строки на эл других строк,
	(кроме строк с нулём) и вычитание из них этой строки
**/
float** zeroingLineItem(float** Arr, unsigned Row, unsigned Col, unsigned numString, unsigned numColumn);

/**
	Вычитание одной строки из другой
**/
float* subLine(float* Minuend, float* Subtrahend, unsigned Col, unsigned numColumn);

/**
	Рекурсивный вызов функций
**/
float** recCallToFunc(float** Arr, unsigned Row, unsigned Col, unsigned numIteration);

/**
	Преобразование матрицы по методу Жардана-Гауса
**/
float** matrixJardanGaus(float** Arr, unsigned Row, unsigned Col);

/**
	Вывод результата
**/
void outResult(float** Arr, unsigned Row, unsigned Col);