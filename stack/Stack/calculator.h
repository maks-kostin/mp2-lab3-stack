#pragma once

#include "tstack.h"
#include <iostream>

#include <string>


class Calculator
{
	std::string formula;
	TStack<char> st_c;
	TStack<double> st_d;
	std::string infix;
	std::string postfix;
public:
	Calculator() : st_c(100), st_d(100)
	{
		infix = "";
		postfix = "";
	}
	void SetFormula(std::string str);
	string GetInfix();
	string GetPostfix();
	void ToPostfix();
	bool CheckBrackets();
	double CalcPostfix();
	int Priority(char elem);
};

#include "calculator.h"
#include <string>
#include <stdlib.h>

void Calculator::SetFormula(std::string str)
{
	infix = str;
}

string Calculator::GetInfix()
{
	return infix;
}

string Calculator::GetPostfix()
{
	return postfix;
}

bool Calculator::CheckBrackets()
{
	int i = 0;
	char a = '(';
	for (i = 0; i < formula.size(); i++)
	{
		if (formula[i] == '(')
			st_c.Push('(');
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

void Calculator::ToPostfix()
{
	postfix = "";
	string src = "(" + infix + ")";
	char elem = '!';
	unsigned int i = 0;
	st_c.Clear();
	while (i < src.size())
	{
		if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' || src[i] == '^')
		{
			elem = st_c.Pop();
			while (Priority(elem) >= Priority(src[i]))
			{
				postfix += elem;
				elem = st_c.Pop();
			}
			if (src[i] == '^' && src[i + 1] == '-')
				throw "negative number after ^";
			st_c.Push(elem);
			st_c.Push(src[i]);
			postfix += " ";
		}
		else
			if (src[i] == '(')
			{
				st_c.Push(src[i]);
			}
			else
				if (src[i] == ')')
				{
					elem = st_c.Pop();
					while (elem != '(')
					{
						postfix += elem;
						elem = st_c.Pop();
					}
				}
				else
				{
					if ((src[i] >= '0' && src[i] <= '9' && src[i]) || src[i] == '.')
					{
						postfix += src[i];
					}
				}
		i++;
	}
}

int Calculator::Priority(char elem)
{
	switch (elem)
	{
	case '(':
	case ')':
		return 1;
		break;
	case '+':
	case '-':
		return 2;
		break;
	case '*':
	case '/':
		return 3;
		break;
	case '^':
		return 4;
		break;
	}
	return 0;
}

double Calculator::CalcPostfix()
{
	unsigned int i = 0;
	st_d.Clear();
	while (i < postfix.size())
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			if (st_d.Empty())
				throw "No operands";
			double k2 = st_d.Pop();
			if (st_d.Empty())
				throw "No operands";
			double k1 = st_d.Pop();
			switch (postfix[i])
			{
			case '+':
				st_d.Push(k1 + k2);
				break;
			case '-':
				st_d.Push(k1 - k2);
				break;
			case '*':
				st_d.Push(k1 * k2);
				break;
			case '/':
				st_d.Push(k1 / k2);
				break;
			case '^':
				st_d.Push(pow(k1, k2));
				break;
			default:
				throw "Unknown operation";
			}
		}

		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			double tmp = 0;
			char* endn = 0;
			tmp = strtod(&postfix[i], &endn);
			st_d.Push(tmp);
			while (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '^' && postfix[i] != ' ')
				i++;
			i--;
		}
		i++;
	}
	if (st_d.Empty())
		throw "Nothing to return";
	double res = st_d.Pop();
	if (!(st_d.Empty()))
		throw "Stack isn't empty";
	return res;
}
