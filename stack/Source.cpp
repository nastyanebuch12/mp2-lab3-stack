#include "Header.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str = "(2+2)*2+(3+4)";
	TStack<int> s(20);
	int res=0;
	while (!s.IsEmpty())
		s.Pop();

	//в виде функции
	for (int i = 0; i < s.size(); i++)
	{
		if (str[i] == '(')
			s.Push(str[i]);
		if (str[i] == ')')
		{
			if (!s.IsEmpty())
				s.Pop();
			else
				res = 1;
		}
	}
	if (s.IsEmpty())
		res = 2;
}