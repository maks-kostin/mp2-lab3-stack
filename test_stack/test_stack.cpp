#include "../stack/Stack/tstack.h"

#include "gtest.h"

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Stack<int> bf(3));
}

