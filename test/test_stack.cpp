#include "stack.h"
#include <gtest.h>


TEST(TStack, can_create_stack) {
	ASSERT_NO_THROW(TStack<int> s);
}
TEST(TStack, can_create_stack_whith_size) {
	ASSERT_NO_THROW(TStack<int> s(10));
}
TEST(TStack, can_not_create_stack_whith_negativ_length) {
	ASSERT_ANY_THROW(TStack<int> s(-10));
}
TEST(TStack, copied_stack_has_its_own_memory)
 {
	TStack <int> s1(2);
	TStack <int> s2(s1);
	EXPECT_NE(&s2,&s1);
 }

TEST(TStack, can_add_element) {
	TStack<int> s(10);
	int a=1;	
	ASSERT_NO_THROW(s.push(a););
}
TEST(TStack, can_not_put_from_empty_stack) {
	TStack<int> s(10);
	int a;
	ASSERT_ANY_THROW(a = s.put());
}


TEST(TStack, can_pick_and_not_delete_element){
	TStack<int> s(10);
	int a=1;
	s.push(a);
	int b;
	b=s.peek();
	EXPECT_EQ(a, s.put());
}




