#include <iostream>
#include "TList.h"
#include "TMonom.h"
#include "TPolinom.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	TPolinom tp1, tp2;
	int n1, n2;
	cout << "Число мономов: ";

	cin >> n1;
	cout << "\n Введите степени и коэф монома: ";
	for (int i = 0; i < n1; i++)
	{
		double coeff;
		int x, y, z;
		cin >> coeff >> x >> y >> z ;
		TMonom tm(coeff, x, y, z);

	    tp1.AddMonom(tm);
	}

	cout << "Итак, полином: " << tp1 << endl;
	
	int k;
	cout << "Введите число для умножения: ";
	cin >> k;
	cout << "Умножение полининома на " << k << " : " << tp1 * k << endl;

	cout << "Введите параметры монома: ";
	double coeff1;
	int x1, y1, z1;
	cin >> coeff1 >> x1 >> y1 >> z1 ;
	TMonom tm(coeff1, x1, y1, z1);

	cout << "Умножение полинома на моном: " << tp1 * tm << endl;
	
	cout << "Введите второй полином. Число мономов в нем: ";
	cin >> n2;
	cout << "\nВведите степени и коэф полинома №2: \n";
	for (int i = 0; i < n2; i++)
	{
		double coeff;
		int x, y, z;
		cin >> coeff >> x >> y >> z;
		TMonom tm(coeff, x, y, z);
		tp2.AddMonom(tm);
	}
	
	cout << "Второй полином: " << tp2 << endl;
	cout << "Сумма двух полиносов: " << tp1 + tp2 << endl;

	cout << "Произведение:" << tp1 * tp2 << endl;
}
