#include "../stack/TCalculator.h"

#include "gtest.h"

TEST(TCalculator, can_create_calculator_with_positive_size_of_str)
{
    string s = "1+2";

    ASSERT_NO_THROW(TCalculator calc(s));
}
TEST(TCalculator, can_GetInfix_form_of_calculator)
{
    string s1 = "2+(3*2)";
    string s2;
    TCalculator calc(s1);

    ASSERT_NO_THROW(s2 = calc.GetInfix());
    EXPECT_EQ(s1, s2);
}
TEST(TCalculator, can_SetInfix_form_of_calculator)
{
    string s1 = "2+(3*2)";
    string s2;
    TCalculator calc(s1);

    ASSERT_NO_THROW(calc.SetInfix(s2));
    EXPECT_EQ(calc.GetInfix(), s2);
}
TEST(TCalculator, can_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_correct)
{
    string s1 = "2+(3*2)";
    string s2 = "232*+";
    string s3;
    TCalculator calc(s1);

    ASSERT_NO_THROW(s3 = calc.GetPostfix());
    EXPECT_EQ(s2, s3);
}
TEST(TCalculator, cant_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_incorrect)
{
    string s1 = "2+((3*2)";
    string s2 = "232*+";
    string s3;
    TCalculator calc(s1);
    s3 = calc.GetPostfix();

    EXPECT_NE(s2, s3);
}

TEST(TCalculator, can_calculat_if_the_number_of_brackets_is_correct)
{
    string s = "2+(3*2)";
    TCalculator calc(s);
    double check;

    ASSERT_NO_THROW(check = calc.CalcPostfix());
    EXPECT_EQ(check, 8);
}

TEST(TCalculator, cant_calculat_if_the_number_of_brackets_is_incorrect)
{
    string s = "2+((3*2)";
    TCalculator calc(s);
    double check;

    ASSERT_ANY_THROW(check = calc.CalcPostfix());
    EXPECT_NE(check, 8);
}
