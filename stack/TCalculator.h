#pragma once
#include <string>
#include <cmath>
#include "TStack.h"
class TCalculator
{
	string  infix, postfix;
	TStack<char> c = TStack<char>(10); // ���� ��� ��������
	TStack<double> d = TStack<double>(10);; // ���� ��� �����
	int prioritet(char op)
	{
		if (op == '(' || op == ')')
			return 0;
		if (op == '+' || op == '-')
			return 1;
		if (op == '*' || op == '/')
			return 2;
		if (op == '^')
			return 3;
	}
public:
	double Calc();
	void ToPostfix();
	TCalculator(string& str) :infix(str) { ToPostfix(); };
	void SetInfix(string str);
	string GetPostfix();
	string GetInfix();
	double CalcPostfix();

};
