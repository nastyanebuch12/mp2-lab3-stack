#include "../stack/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(Tstack, cant_create_stack_with_negative_size)
{
    ASSERT_ANY_THROW(TStack<int> s(-12));
}

TEST(TStack, can_get_size)
{
  TStack<int> s(3);

  EXPECT_EQ(0, s.size());
}

TEST(TStack, new_stack_is_empty)
{
    TStack<int> s(3);
    bool q = s.IsEmpty();

    EXPECT_EQ(true, q);
}

TEST(TStack, can_set_bit)
{
  TStack s(10);

  EXPECT_EQ(0, s.GetBit(3));

  s.SetBit(3);
  EXPECT_NE(0, s.GetBit(3));
}

TEST(TStack, can_clear_bit)
{
  TStack s(10);

  int bitIdx = 3;

  s.SetBit(bitIdx);
  EXPECT_NE(0, s.GetBit(bitIdx));

  s.ClrBit(bitIdx);
  EXPECT_EQ(0, s.GetBit(bitIdx));
}

TEST(TStack, throws_when_create_bitfield_with_negative_length)
{
  ASSERT_ANY_THROW(TStack s(-3));
}

TEST(TStack, throws_when_set_bit_with_negative_index)
{
  TStack s(10);

  ASSERT_ANY_THROW(s.SetBit(-3));
}

TEST(TStack, throws_when_set_bit_with_too_large_index)
{
  TStack s(10);

  ASSERT_ANY_THROW(s.SetBit(11));
}

TEST(TStack, throws_when_get_bit_with_negative_index)
{
  TStack s(10);

  ASSERT_ANY_THROW(s.GetBit(-3));
}

TEST(TStack, throws_when_get_bit_with_too_large_index)
{
  TStack s(10);

  ASSERT_ANY_THROW(s.GetBit(11));
}

TEST(TStack, throws_when_clear_bit_with_negative_index)
{
  TStack s(10);

  ASSERT_ANY_THROW(s.ClrBit(-3));
}

TEST(TStack, throws_when_clear_bit_with_too_large_index)
{
  TStack s(10);

  ASSERT_ANY_THROW(s.ClrBit(11));
}

TEST(TStack, can_assign_bitfields_of_equal_size)
{
  const int size = 2;
  TStack s1(size), s2(size);
  for (int i = 0; i < size; i++)
  {
    s1.SetBit(i);
  }
  s2 = s1;

  EXPECT_NE(0, s2.GetBit(0));
  EXPECT_NE(0, s2.GetBit(1));
}

TEST(TStack, assign_operator_changes_bitfield_size)
{
  const int size1 = 2, size2 = 5;
  TStack s1(size1), s2(size2);
  for (int i = 0; i < size1; i++)
  {
    s1.SetBit(i);
  }
  s2 = s1;

  EXPECT_EQ(2, s2.GetLength());
}

TEST(TStack, can_assign_bitfields_of_non_equal_size)
{
  const int size1 = 2, size2 = 5;
  TStack s1(size1), s2(size2);
  for (int i = 0; i < size1; i++)
  {
    s1.SetBit(i);
  }
  s2 = s1;

  EXPECT_NE(0, s2.GetBit(0));
  EXPECT_NE(0, s2.GetBit(1));
}

TEST(TStack, compare_equal_bitfields_of_equal_size)
{
  const int size = 2;
  TStack s1(size), s2(size);
  for (int i = 0; i < size; i++)
  {
    s1.SetBit(i);
  }
  s2 = s1;

  EXPECT_EQ(s1, s2);
}

TEST(TStack, or_operator_applied_to_bitfields_of_equal_size)
{
  const int size = 4;
  TStack s1(size), s2(size), exps(size);
  // s1 = 0011
  s1.SetBit(2);
  s1.SetBit(3);
  // s2 = 0101
  s2.SetBit(1);
  s2.SetBit(3);

  // exps = 0111
  exps.SetBit(1);
  exps.SetBit(2);
  exps.SetBit(3);

  EXPECT_EQ(exps, s1 | s2);
}

TEST(TStack, or_operator_applied_to_bitfields_of_non_equal_size)
{
  const int size1 = 4, size2 = 5;
  TStack s1(size1), s2(size2), exps(size2);
  // s1 = 0011
  s1.SetBit(2);
  s1.SetBit(3);
  // s2 = 01010
  s2.SetBit(1);
  s2.SetBit(3);

  // exps = 01110
  exps.SetBit(1);
  exps.SetBit(2);
  exps.SetBit(3);

  EXPECT_EQ(exps, s1 | s2);
}

TEST(TStack, and_operator_applied_to_bitfields_of_equal_size)
{
  const int size = 4;
  TStack s1(size), s2(size), exps(size);
  // s1 = 0011
  s1.SetBit(2);
  s1.SetBit(3);
  // s2 = 0101
  s2.SetBit(1);
  s2.SetBit(3);

  // exps = 0001
  exps.SetBit(3);

  EXPECT_EQ(exps, s1 & s2);
}

TEST(TStack, and_operator_applied_to_bitfields_of_non_equal_size)
{
  const int size1 = 4, size2 = 5;
  TStack s1(size1), s2(size2), exps(size2);
  // s1 = 0011
  s1.SetBit(2);
  s1.SetBit(3);
  // s2 = 01010
  s2.SetBit(1);
  s2.SetBit(3);

  // exps = 00010
  exps.SetBit(3);

  EXPECT_EQ(exps, s1 & s2);
}

TEST(TStack, can_invert_bitfield)
{
  const int size = 2;
  TStack s(size), negs(size), expNegs(size);
  // s = 01
  s.SetBit(1);
  negs = ~s;

  // expNegs = 10
  expNegs.SetBit(0);

  EXPECT_EQ(expNegs, negs);
}

TEST(TStack, can_invert_large_bitfield)
{
  const int size = 38;
  TStack s(size), negs(size), expNegs(size);
  s.SetBit(35);
  negs = ~s;

  for(int i = 0; i < size; i++)
    expNegs.SetBit(i);
  expNegs.ClrBit(35);

  EXPECT_EQ(expNegs, negs);
}

TEST(TStack, invert_plus_and_operator_on_different_size_bitfield)
{
  const int firstSze = 4, secondSize = 8;
  TStack firsts(firstSze), negFirsts(firstSze), seconds(secondSize), tests(secondSize);
  // firsts = 0001
  firsts.SetBit(0);
  negFirsts = ~firsts;
  // negFirsts = 1110

  // seconds = 00011000
  seconds.SetBit(3);
  seconds.SetBit(4);

  // tests = 00001000
  tests.SetBit(3);

  EXPECT_EQ(seconds & negFirsts, tests);
}

TEST(TStack, can_invert_many_random_bits_bitfield)
{
  const int size = 38;
  TStack s(size), negs(size), expNegs(size);

  std::vector<int> bits;
  bits.push_back(0);
  bits.push_back(1);
  bits.push_back(14);
  bits.push_back(16);
  bits.push_back(33);
  bits.push_back(37);

  for (unsigned int i = 0; i < bits.size(); i++)
    s.SetBit(bits[i]);

  negs = ~s;

  for(int i = 0; i < size; i++)
    expNegs.SetBit(i);
  for (unsigned int i = 0; i < bits.size(); i++)
    expNegs.ClrBit(bits[i]);

  EXPECT_EQ(expNegs, negs);
}

TEST(TStack, bitfields_with_different_bits_are_not_equal)
{
  const int size = 4;
  TStack s1(size), s2(size);

  s1.SetBit(1);
  s1.SetBit(3);

  s2.SetBit(1);
  s2.SetBit(2);

  EXPECT_NE(s1, s2);
}*/
