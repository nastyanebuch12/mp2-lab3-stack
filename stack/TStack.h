#pragma once
#include<string>
#include <iostream>
template<class T>
class TStack
{
	T* pMem;
	int MaxSize;
	int CurrInd;
public:
	TStack(int _MaxSize=10)
	{
		CurrInd = -1;
		MaxSize = _MaxSize;
		pMem = new T[MaxSize]);
	}
	TStack(const TStack& s)
	{
		CurrInd = s.CurrInd;
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
		for (int i = 0; i <= CurrInd; i++)
			pMem[i] = s.pMem[i];
	}
	~TStack() { delete[] pMem; }
	int size() const { return CurrInd + 1; }
	int top() const
	{
		if (CurrInd == -1)
			throw "Empty";
		return pMem[CurrInd];
	}
	bool IsEmpty() const { return CurrInd == -1; }
	bool IsFull() const { return CurrInd == MaxSize - 1; }
	T Pop()
	{
		if (CurrInd == -1)
			throw "Empty";
		CurrInd--;
		return pMem[CurrInd + 1];
	}
	void Push(const T& val)
	{
		if (CurrInd + 1 >= MaxSize)
			throw "Overflow";
		pMem[CurrInd + 1] = val;
		CurrInd++;
	}
	friend ostream& operator<<(ostream& out, const TStack& s)
	{
		for (int i = 0; i <= s.CurrInd; i++)
			out << s.pMem[i] << ' ';
		return out;
	}
	TStack operator=(const TStack s)
	{

	}
	TStack Clear(TStack s)
	{
		s.CurrInd = -1;
	}
};

