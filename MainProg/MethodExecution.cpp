#include<iostream>
#include<locale>
#include"IncArr.h"

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




	system("pause");
}