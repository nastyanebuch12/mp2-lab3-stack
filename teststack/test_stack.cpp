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

TEST(TStack, can_push_pop)
{
  TStack<int> s(3);
  int x1 = 1;
  int x2 = 2;
  int x3 = 3;

  ASSERT_NO_THROW(s.Push(x1));
  ASSERT_NO_THROW(s.Push(x2));
  ASSERT_NO_THROW(s.Push(x3));

  int y1, y2, y3;

  ASSERT_NO_THROW(y1 = s.Pop()); //y1=x3
  ASSERT_NO_THROW(y2 = s.Pop());
  ASSERT_NO_THROW(y3 = s.Pop());

  EXPECT_EQ(y1, x3);
  EXPECT_EQ(y2, x2);
  EXPECT_EQ(y3, x1);
}

TEST(TStack, throws_when_ask_top_of_empty_stack)
{
    TStack<int> s(3);

    ASSERT_ANY_THROW(s.top());
}

TEST(TStack, throws_when_pop_from_empty_stack)
{
    TStack<int> s(3);

    ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, throws_when_push_to_overflow_stack)
{
    TStack<int> s(2);
    s.Push(1);
    s.Push(2);

    ASSERT_ANY_THROW(s.Push(3));
}

TEST(TStack, return_true_when_use_Full_on_full_stack)
{
    TStack<int> s(2);
    s.Push(1);
    s.Push(2);
    bool is = s.IsFull();

    EXPECT_EQ(true, is);
}
TEST(TStack, return_false_when_use_Full_on_not_full_stack)
{
    TStack<int> s(2);
    s.Push(1);
    bool is = s.IsFull();

    EXPECT_EQ(false, is);
}
TEST(TStack, return_true_when_use_Empty_on_empty_stack)
{
    TStack<int> st(3);

    bool b1 = st.IsEmpty();
    EXPECT_EQ(1, b1);
}
TEST(TStack, return_false_when_use_Empty_on_not_empty_stack)
{
    TStack<int> st(3);
    st.Push(1);
    st.Push(1);

    bool b1 = st.IsEmpty();
    EXPECT_EQ(0, b1);
}
