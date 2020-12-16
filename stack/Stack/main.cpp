#include <iostream>
#include "tstack.h"
#include "calculator.h"

using namespace std;

void main()
{
	Calculator calc;
	calc.SetFormula("(2+2*)2+2)");
	if (calc.CheckBrackets() == true)
		std::cout << "Good" << endl;
	else
		std::cout << "Bad" << endl;
}