#include "../stack/Stack/tstack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> bf(3));
}

TEST(TStack, cant_pop_if_stack_is_empty)
{
	TStack<int> st(3);
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> st(MAX_STACK_SIZE + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st(15);

	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> st(5);
	st.Push(2);
	st.Push(4);
	st.Push(3); 
	TStack<int> st1(st);

	EXPECT_EQ(st, st1);
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> st(5), st1(st);

	EXPECT_NE(&st, &st1);
}

TEST(TStack, can_get_maxsize)
{
	TStack<int> st(4);

	EXPECT_EQ(4, st.GetMaxSize());
}

TEST(TStack, can_get_size)
{
	TStack<int> st(3);
	st.Push(2);
	EXPECT_EQ(1, st.GetSize());
}

TEST(TStack, can_push_and_pop)
{
	TStack<int> st(3);
	st.Push(2);
	EXPECT_EQ(2, st.Pop());
}

TEST(TStack, throws_when_pop_empty_stack)
{
	TStack<int> st(2);
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, throws_when_push_full_stack)
{
	TStack<int> st(1);
	st.Push(2);
	ASSERT_ANY_THROW(st.Push(3));
}

TEST(TStack, can_get_top)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);
	EXPECT_EQ(2, st.Top());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);
	st.Clear();
	EXPECT_EQ(st.GetSize(), 0);
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack <int> st(2);
	for (int i = 0; i < 2; i++)
	{
		st.Push(1);
	}
	st = st;
	EXPECT_EQ(1, st[0]);
	EXPECT_EQ(1, st[1]);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	const int size = 2;
	TStack <int> st(size), st1(size);

	for (int i = 0; i < size; i++)
	{
		st.Push(1);
	}
	st1 = st;

	EXPECT_EQ(1, st1[0]);
	EXPECT_EQ(1, st1[1]);
}

TEST(TStack, assign_operator_change_stack_size)
{
	const int size1 = 3, size2 = 5;
	TStack <int> st1(size1), st2(size2);
	for (int i = 0; i < size1 - 1; i++)
	{
		st1.Push(1);
	}
	st2 = st1;
	EXPECT_EQ(3, st2.GetMaxSize());
	EXPECT_EQ(2, st1.GetSize());
}

TEST(TStack, can_assign_stacks_of_different_size)
{

	const int size1 = 3, size2 = 5;
	TStack <int> st1(size1), st2(size2);
	for (int i = 0; i < size1; i++)
	{
		st1.Push(1);
	}
	st2 = st1;
	EXPECT_EQ(1, st2[0]);
	EXPECT_EQ(1, st2[1]);
}

TEST(TStack, throws_when_set_element_with_negative_index)
{
	TStack<int> st(3);

	ASSERT_ANY_THROW(st[-1]);
}

TEST(TStack, throws_when_set_element_with_too_large_index)
{
	TStack<int> st(4);

	ASSERT_ANY_THROW(st[5]);
}


