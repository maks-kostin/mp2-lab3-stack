#pragma once

#include "tstack.h"
#include "iostream"

#include <string>


class Calculator
{
	std::string formula;
	Stack<char> st_c;
public:
	void SetFormula(std::string str);
	bool CheckBrackets();
};
