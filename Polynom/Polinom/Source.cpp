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
	cout << "Количество мономов в первом полиноме: \n";

	cin >> n1;
	cout << "Коэффициент какждого монома и его степени при x, y, z: \n";
	for (int i = 0; i < n1; i++)
	{
		double coeff;
		int x, y, z;
		cin >> coeff >> x >> y >> z ;
		TMonom tm(coeff, x, y, z);

	    tp1.AddMonom(tm);
	}
	
	cout << "Первый полином: \n" << tp1 << endl;
	
	int k;
	cout << "Умножить полином на число: ";
	cin >> k;
	cout << k << " * (" << tp1 <<")"<< endl << "="<<endl;
	tp1 = tp1 * k;
	cout << tp1 << endl;

	cout << "Ввод коэффициента и степеней для генерации следующего монома: \n";
	double coeff1;
	int x1, y1, z1;
	cin >> coeff1 >> x1 >> y1 >> z1 ;
	TMonom tm(coeff1, x1, y1, z1);

	cout << "Умножение полинома на моном: \n";
	cout <<"("<< tp1 << ") * " <<tm.coeff <<"*"<< tm << endl;
	tp1 = tp1 * tm ;
	cout << tp1 << endl;

	cout << "Ввод количества мономов для второго полинома: \n";
	cin >> n2;

	cout << "Ввод коэффициентов и степеней при x, y, z для второго полинома: \n";
	for (int i = 0; i < n2; i++)
	{
		double coeff;
		int x, y, z;
		cin >> coeff >> x >> y >> z;
		TMonom tm(coeff, x, y, z);
		tp2.AddMonom(tm);
	}
	cout << endl;
	cout << "Второй полином: \n" << tp2 << endl << endl;

	cout << "Сумма двух полиномов: \n" <<tp1<<endl<<"+"<<endl<<tp2<< endl;
	tp1 = tp1 + tp2;
	cout << "=" << endl << tp1<<endl<<endl;
	cout << "Произведение:\n" << tp1 << endl << "*" << endl << tp2 << endl;
	tp1 =tp1 * tp2 ;
	cout << "=\n" << endl << tp1 << endl;
}
