#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "TMonom.h"
using namespace std;

template <class T>
class TList 
{
protected:
	TNode<T>* pFirst, * pCuer, * pPrev, * pLast, * pStop;
	int len;
public:
	TList();
	~TList();

	bool IsEmpty();
	void InsFirst(T value);
	void InsLast(T value);
	void InsCuer(T value);

	void DelFirst();
	void DelCuer();
	void GoNext();
	bool IsEnd();

	void Reset();
	T GetCuer();

};

template<class T>
TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pCuer = pPrev = pLast = pStop;
	len = 0;
}

template<class T>
TList<T>::~TList()
{
	while (pFirst != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	pLast = pPrev = pCuer = pStop;
	len = 0;
}

template<class T>
bool TList<T>::IsEmpty()
{
	return pFirst == nullptr;
}

template<class T>
void TList<T>::InsFirst(T value)
{
	TNode<T>* newNode = new TNode<T>;
	newNode->val = value;
	newNode->pNext = pFirst;
	pFirst = newNode;
	len++;
	if (len == 1)
	{
		pLast = pFirst;
		pCuer = pFirst;
	}
}

template<class T>
void TList<T>::InsLast(T value)
{
	if (len > 0) 
	{
		TNode<T>* newNode = new TNode<T>;
		newNode->val = value;
		newNode->pNext = pStop;
		pLast->pNext = newNode;
		pLast = newNode;

		len++;
	}
	else
	{
		InsFirst(value);
	}
}

template<class T>
void TList<T>::InsCuer(T value)
{
	if (pCuer == pFirst) 
	{
		InsFirst(value);
	}
	else if (pCuer == pLast)
	{
		InsLast(value);
	}
	else {
		TNode<T>* newNode = new TNode<T>;
		newNode->val = value;
		newNode->pNext = pCuer;
		pCuer = newNode;
		pPrev->pNext = pCuer;
		len++;
	}
}

template<class T>
void TList<T>::DelFirst()
{
	if (IsEmpty())
	{
		throw "Empty!";
	}

	if (pCuer == pFirst)
	{
		pPrev = pStop;
		pCuer = pCuer->pNext;
	}

	TNode<T>* newNode = pFirst;
	pFirst = newNode->pNext;
	delete newNode;
	len--;
	if (pFirst == pStop) 
	{
		pLast = pStop;
	}
}

template<class T>
void TList<T>::DelCuer()
{
	if (IsEmpty())
	{
		throw "Empty!";
	}

	if (pCuer == pFirst) 
	{
		DelFirst();
	}
	else {
		TNode<T>* newNode = pCuer;
		pCuer = newNode->pNext;
		pPrev->pNext = pCuer;
		delete newNode;
		len--;
	}
}

template<class T>
void TList<T>::GoNext()
{
	pPrev = pCuer;
	pCuer = pCuer->pNext;
}

template<class T>
bool TList<T>::IsEnd()
{
	return pCuer == pStop;
}

template<class T>
T TList<T>::GetCuer()
{
	return pCuer->val;
}

template<class T>
void TList<T>::Reset()
{
	pPrev = pStop;
	pCuer = pFirst;
}

///////////////////		THEADLIST		////////////////////////////

template <class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList();
	~THeadList();
	void InsFirst(T elem);
	void DelFirst();
};

template<class T>
THeadList<T>::THeadList()
{
	len = 0;
	pHead = new TNode<T>;
	pHead->pNext = pHead;
	pFirst = pLast = pPrev = pCuer = pStop = pHead;
}

template<class T>
THeadList<T>::~THeadList()
{
	while (pFirst != pStop) 
	{
		TNode<T>* newNode = pFirst;
		pFirst = pFirst->pNext;
		delete newNode;
	}
	delete pHead;
}

template<class T>
void THeadList<T>::InsFirst(T elem)
{
	TList::InsFirst(elem);
	pHead->pNext = pFirst;
}

template<class T>
void THeadList<T>::DelFirst()
{
	TList::DelFirst();
	pHead->pNext = pFirst;
}
