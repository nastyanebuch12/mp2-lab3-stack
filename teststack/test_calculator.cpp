#include "../stack/TCalculator.h"

#include "gtest.h"

TEST(TCalculator, can_create_calculator_with_positive_size_of_str)
{
    string a = "1+2";

    ASSERT_NO_THROW(TCalculator calc(a));
}
TEST(TCalculator, can_get_infix_form_of_calculator)
{
    string a = "2+(3*5)";
    string b;
    TCalculator calc(a);

    ASSERT_NO_THROW(b = calc.get_infix());
    EXPECT_EQ(a, b);
}
TEST(TCalculator, can_set_infix_form_of_calculator)
{
    string a = "2+(3*5)";
    string b;
    TCalculator calc(a);

    ASSERT_NO_THROW(calc.set_infix(b));
    EXPECT_EQ(calc.get_infix(), b);
}
TEST(TCalculator, can_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_correct)
{
    string a = "2+(3*5)";
    string b = "235*+";
    string c;
    TCalculator calc(a);

    ASSERT_NO_THROW(c = calc.get_postfix());
    EXPECT_EQ(c, b);
}
TEST(TCalculator, cant_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_incorrect)
{
    string a = "2+((3*5)";
    string b = "235*+";
    string c;
    TCalculator calc(a);
    c = calc.get_postfix();

    EXPECT_NE(c, b);
}

TEST(TCalculator, can_calculat_if_the_number_of_brackets_is_correct)
{
    string a = "2+(3*5)";
    TCalculator calc(a);
    double check;

    ASSERT_NO_THROW(check = calc.CalcPostfix());
    EXPECT_EQ(17, check);
}

TEST(TCalculator, cant_calculat_if_the_number_of_brackets_is_incorrect)
{
    string a = "2+((3*5)";
    TCalculator calc(a);
    double check;

    ASSERT_ANY_THROW(check = calc.CalcPostfix());
    EXPECT_NE(17, check);
}
