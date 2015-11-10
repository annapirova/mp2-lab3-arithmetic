#include "stack.h"
#include <gtest.h>

TEST(TStack, copied_stack_has_its_own_memory)
 {
	TStack <int> s1(2);
	TStack <int> s2(s1);
	EXPECT_NE(&s2,&s1);
 }

TEST(TStack, second)
{
	/*TStack<int> s1(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);*/

}