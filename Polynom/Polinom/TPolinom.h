#include "TList.h"
class TPolinom : public THeadList<TMonom>
{
protected:
	void Print(std::ostream& os) const;
public:
	TPolinom();
	TPolinom(TPolinom& pol);

	TPolinom& operator=(TPolinom& pol);

	void AddMonom(TMonom mon);

	bool operator==(TPolinom& pol);
	bool operator!=(TPolinom& pol);

	TPolinom operator+(TPolinom& pol);
	TPolinom operator-(TPolinom& pol);

	TPolinom operator*(TPolinom& pol);
	TPolinom operator*(TMonom& pol);
	TPolinom operator*(double a);

	friend TPolinom operator*(TMonom& m, TPolinom& pol)
	{
		return pol * m;
	}

	friend TPolinom operator*(double a, TPolinom& pol)
	{
		return pol * a;
	}

	friend std::ostream& operator<<(std::ostream& os, TPolinom& pol)
	{
		pol.Print(os);
		return os;
	}
};

//вывод полинома
void TPolinom::Print(std::ostream& os) const
{
	TNode<TMonom>* _pCurr = pFirst;

	if (_pCurr == pStop)
	{
		os << "0";
		return;
	}

	TMonom m = _pCurr->val;
	double absCoeff = fabs(m.coeff);

	if (m.coeff < 0) os << "- ";


	if (m.IsConst())
	{
		os << absCoeff;
	}

	else
	{
		if (absCoeff != 1) os << absCoeff << "*";
		os << m;
	}

	_pCurr = _pCurr->pNext;

	for (; _pCurr != pStop; _pCurr = _pCurr->pNext)
	{
		TMonom m = _pCurr->val;
		double absCoeff = fabs(m.coeff);

		if (m.coeff < 0) os << " - ";
		else os << " + ";

		if (m.IsConst())
		{
			os << absCoeff;
		}
		else
		{
			if (absCoeff != 1)
				os << absCoeff << "*";
			os << m;
		}
	}
}
//конструктор
TPolinom::TPolinom()
{
	TMonom m(0, 0, -1);
	pHead->val = m;
}
TPolinom::TPolinom(TPolinom& pol)
{
	TMonom m(0, 0, -1);
	pHead->val = m;
	for (pol.Reset(); !pol.IsEnd(); pol.GoNext())
	{
		InsLast(pol.GetCuer());
	}
}
TPolinom& TPolinom::operator=(TPolinom& pol)
{
	while (pFirst != pStop)
	{
		DelFirst();
	}

	pFirst = pLast = pPrev = pCuer = pStop = pHead;
	len = 0;

	pol.Reset();
	while (!pol.IsEnd())
	{
		InsLast(pol.GetCuer());
		pol.GoNext();
	}
	return *this;
}
void TPolinom::AddMonom(TMonom mon)
{
	if (mon.coeff == 0)
		return;

	Reset();

	while (mon < pCuer->val)
	{
		GoNext();
	}

	if (pCuer->val == mon)
	{
		pCuer->val.coeff += mon.coeff;
		if (pCuer->val.coeff == 0)
		{
			DelCuer();
		}
	}

	else
	{
		InsCuer(mon);
	}
}

bool TPolinom::operator==(TPolinom& pol)
{
	TPolinom rtp(pol);
	rtp.Reset();
	Reset();
	while (!IsEnd())
	{
		if (!(pCuer->val == rtp.pCuer->val))
		{
			return false;
		}
		else
		{
			GoNext();
			rtp.GoNext();
		}
	}

	return true;
}
bool TPolinom::operator!=(TPolinom& pol)
{
	return !(this == &pol);
}
TPolinom TPolinom::operator+(TPolinom& pol)
{
	TPolinom res(pol);
	Reset();
	res.Reset();

	while (!IsEnd())
	{
		if (res.pCuer->val > pCuer->val)
		{
			res.GoNext();
		}
		else if (res.pCuer->val < pCuer->val)
		{
			res.InsCuer(pCuer->val);
			GoNext();
		}
		else
		{
			res.pCuer->val.coeff += pCuer->val.coeff;
			if (res.pCuer->val.coeff == 0)
			{
				res.DelCuer();
				GoNext();
			}
			else
			{
				res.GoNext();
				GoNext();
			}
		}
	}
	return res;

}
TPolinom TPolinom::operator*(TPolinom& pol)
{
	TPolinom res;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCuer();
		TPolinom temp = m * pol;
		res = res + temp;
	}

	return res;
}
TPolinom TPolinom::operator*(TMonom& mon)
{
	TPolinom res;

	if (mon.coeff == 0) return res;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCuer();
		res.InsLast(m * mon);
	}

	return res;
}
TPolinom TPolinom::operator*(double a)
{
	TPolinom res;

	if (a == 0) return res;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCuer();
		m.coeff *= a;

		res.InsLast(m);
	}
	return res;
}
TPolinom TPolinom::operator-(TPolinom& pol)
{
	return operator+(pol.operator*(-1));
}