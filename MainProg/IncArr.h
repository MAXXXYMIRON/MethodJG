#pragma once

/**
	Создание массива
**/
float** makeArray(unsigned n, unsigned m);

/**
	Инициализация массива
**/
float** incArray(float** Arr, unsigned n, unsigned m);

/**
	Рандомная инициализация матрицы
**/
float** fastIncArray(float** Arr, unsigned n, unsigned m);

/**
	Вывод массива
**/
void outArray(float** Arr, unsigned n, unsigned m);