#pragma once
#pragma once
#include <iostream>
using namespace std;

//////////////	TNODE	//////////////

template <class T>
struct TNode
{
	T val;
	TNode* pNext;
};

//////////		TMONOM		//////////

struct TMonom
{
	//����������� � �������
	double coeff;
	int x, y, z;

	//�����������
	TMonom(double _coeff = 0, int _x = 0, int _y = 0, int _z = 0)
	{
		coeff = _coeff;
		x = _x;
		y = _y;
		z = _z;
	}

	//�������� �� �� ��� ������ ������ ��������� ����
	bool IsConst() const
	{
		return x == 0 && y == 0 && z == 0;
	}
	
	//��������� ��������� ��������
	bool operator==(const TMonom& mon)
	{
		return (x == mon.x) && (y == mon.y) && (z == mon.z);
	}

	bool operator<(const TMonom& mon)
	{
		int a, b;
		a = 100 * x + 10 * y + z;
		b = 100 * mon.x + 10 * mon.y + mon.z;
		if (a < b)
			return true;
		else
			return false;
	}
	bool operator>(const TMonom& mon)
	{
		int a, b;
		a = 100 * x + 10 * y + z;
		b = 100 * mon.x + 10 * mon.y + mon.z;
		if (a > b)
			return true;
		else
			return false;
	}

	//��� ����� ������
	friend std::ostream& operator<<(std::ostream& os, TMonom& mon)
	{	
		/* �� �������� �� ����������� ��� ����� ������������ ������
		if (mon.coeff != 1) {
			os << mon.coeff;
		}
		*/ 
		if (mon.x != 0)
		{
			os << "x";
			if (mon.x != 1)
				os << mon.x;
		}
		if (mon.y != 0)
		{
			os << "y";
			if (mon.y != 1)
				os << mon.y;
		}
		if (mon.z != 0)
		{
			os << "z";
			if (mon.z != 1)
				os << mon.z;
		}
		return os;
	}

	//�������� ��������� ������ �� �����
	TMonom operator*(const TMonom& mon)
	{
		TMonom res;
		res.coeff = coeff * mon.coeff;
		res.x = x + mon.x;
		res.y = y + mon.y;
		res.z = z + mon.z;
		return res;
	}
};

