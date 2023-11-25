#pragma once
class TCalculator
{
private:
	string expr;
	TStack<char> st;
piblic:
	bool CheckExpression();
};