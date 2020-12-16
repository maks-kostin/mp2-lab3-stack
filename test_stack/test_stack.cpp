#include "../stack/Stack/tstack.h"

#include "gtest.h"

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Stack<int> bf(3));
}

TEST(Stack, cant_pop_if_stack_is_empty)
{
	Stack<int> st(3);
	ASSERT_ANY_THROW(st.Pop());
}