#include "calculator.h"

void Calculator::SetFormula(std::string str)
{
	formula = str;
}

bool Calculator::CheckBrackets()
{
	int i = 0;
	char a = '(';
	for (int i = 0; i < formula.size(); i++)
	{
		if (formula[i] == '(')
			st_c.Push( '(' );
		if (formula[i] == ')')
		{
			if (st_c.Empty())
				return false;
			st_c.Pop();
		}
			
	}
	if (st_c.Empty())
		return true;
	return false;
}