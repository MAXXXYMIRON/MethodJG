#include<iostream>
#include<locale>
#include"IncArr.h"
#include"UnitMatrix.h"

using namespace std;

void main()
{
	setlocale(0, "");

	unsigned n, m;


	cout << "���-�� ����� = "; cin >> n;
	cout << "���-�� �������� (�������� ��������������) = "; cin >> m;

	float **SLAU = makeArray(n, m);


	cout << "��������������� ������� (��������� - �����)" << endl;

	SLAU = incArray(SLAU, n, m);
	//SLAU = fastIncArray(SLAU, n, m);

	outArray(SLAU, n, m);

	SLAU = matrixJardanGaus(SLAU, n, m);
	cout << endl;
	outArray(SLAU, n, m);

	outResult(SLAU, n, m);

	system("pause");
}