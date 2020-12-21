#include "../stack/Stack/calculator.h"
#include <string>
#include "gtest.h"

TEST(Calculator, can_set_formula)
{
	Calculator calc;
	ASSERT_NO_THROW(calc.SetFormula("3 + 5"));
}

TEST(Calculator, can_get_infix)
{
	Calculator calc;
	calc.SetFormula("(4 - 5) * 3 + 9 * 2");
	EXPECT_EQ(calc.GetInfix(), "(4 - 5) * 3 + 9 * 2");
}

TEST(Calculator, can_get_postfix)
{
	Calculator calc;
	calc.SetFormula("(4 - 5) * 3 + 9 * 2");
	calc.ToPostfix();
	EXPECT_EQ(calc.GetPostfix(), "4 5- 3* 9 2*+");
}

TEST(Calculator, can_translate_infix_to_postfix)
{
	Calculator calc;
	calc.SetFormula("(4 - 5) * 3 + 9 * 2");
	ASSERT_NO_THROW(calc.ToPostfix());
}

TEST(Calculator, can_add)
{
	Calculator calc;
	calc.SetFormula("2 + 3");
	calc.ToPostfix();
	EXPECT_EQ(calc.CalcPostfix(), 5);
}

TEST(Calculator, can_subtract)
{
	Calculator calc;
	calc.SetFormula("3 - 2");
	calc.ToPostfix();
	EXPECT_EQ(calc.CalcPostfix(), 1);
}

TEST(Calculator, can_multiply)
{
	Calculator calc;
	calc.SetFormula("3 * 2");
	calc.ToPostfix();
	EXPECT_EQ(calc.CalcPostfix(), 6);
}

TEST(Calculator, can_divide)
{
	Calculator calc;
	calc.SetFormula("8 / 2");
	calc.ToPostfix();
	EXPECT_EQ(calc.CalcPostfix(), 4);
}

TEST(Calculator, can_pow)
{
	Calculator calc;
	calc.SetFormula("3 ^ 2");
	calc.ToPostfix();
	EXPECT_EQ(calc.CalcPostfix(), 9);
}

TEST(Calculator, cant_count_wrong_expression)
{
	Calculator calc;
	calc.SetFormula("(7-5(*3");
	calc.ToPostfix();
	ASSERT_ANY_THROW(calc.CalcPostfix());
}

TEST(Calculator, can_count_right_expression)
{
	Calculator calc;
	calc.SetFormula("(25 * 3) / 25 + 60 / (15 - 3)");
	calc.ToPostfix();
	ASSERT_NO_THROW(calc.CalcPostfix());
}

TEST(Calculator, can_count_difficult_expression_right)
{
	Calculator calc;
	calc.SetFormula("(15 ^ 4 - 22 * 18 ^ 2) / 9 - (4532 * (147 + 13)) + 72^3");
	calc.ToPostfix();
	EXPECT_EQ(calc.CalcPostfix(), -347039);
}

TEST(Calculator, throws_when_expression_has_unknown_symbol)
{
	Calculator calc;
	calc.SetFormula("7+b-(33-99)");
	calc.ToPostfix();
	ASSERT_ANY_THROW(calc.CalcPostfix());
}

TEST(Calculator, throws_when_power_is_negative)
{
	Calculator calc;
	calc.SetFormula("2^-3");
	ASSERT_ANY_THROW(calc.ToPostfix());
}