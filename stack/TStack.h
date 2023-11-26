#pragma once
#include <iostream>
#include <locale.h>
#include <math.h>
#include <string.h>
using namespace std;

template<class T>
class TStack
{
	T* pMem; //������
	int MaxSize; //������ �����
	int CurrInd; //������ �������
public:
	TStack(int _MaxSize = 10) //�����������
	{
		if (_MaxSize < 1) throw ("Wrong size!\n");
		MaxSize = _MaxSize;
		pMem = new T[MaxSize];
		CurrInd = -1;
	}
	TStack(const TStack& s) //����������� �����������
	{
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
		CurrInd = s.CurrInd;
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
	bool IsEmpty() const 
	{
		if (CurrInd < 0)
			return true;
		else
			return false;
	}
	bool IsFull() const 
	{
		if (CurrInd == MaxSize - 1)
			return true;
		else
			return false;
	}
	T Pop() //�������� �������� � ������� �����
	{
		if (CurrInd == -1)
			throw "Empty";
		CurrInd--;
		return pMem[CurrInd + 1];
	}
	void Push(const T& val) //�������� ���� �� ������� �����
	{
		if (CurrInd + 1 >= MaxSize)
			throw "Overflow";
		pMem[CurrInd + 1] = val;
		CurrInd++;
	}
	void Clear() //�������� ����
	{				
		CurrInd = -1;
		delete[] pMem;
	}

	friend istream& operator>>(istream& istr, TStack& s)
	{
		for (int i = 0; i < s.MaxSize; i++)
			istr >> s.pMem[i];
		return istr;
	}
	friend ostream& operator<<(ostream& ostr, const TStack& s)
	{
		if (s.CurrInd == -1) {
			ostr << "Stack Is Empty" << endl;
		}
		else {
			for (int i = 0; i < s.CurrInd; i++)
				ostr << s.pMem[i] << ' ';
			ostr << endl;
		}
		return ostr;
	}
};

