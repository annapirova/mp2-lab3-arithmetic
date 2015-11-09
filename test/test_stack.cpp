#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack) 
{
	ASSERT_NO_THROW(TStack a);
}

TEST(TStack, can_add_element)
{
	TStack s(4);

	ASSERT_NO_THROW(s.PutElem(3));

}

TEST(TStack, can_not_add_element_in_full_stack)
{
	TStack s(4);

	for(int i = 0; i < 4; i++)
		s.PutElem(1);

	ASSERT_ANY_THROW(s.PutElem(3));

}
