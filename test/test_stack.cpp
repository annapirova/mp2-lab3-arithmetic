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


TEST(TStack, equal_stack) {
	TStack<int> s1(2),s2(2);
	s1.push(1);
	s1.push(2);
	s2=s1;
	EXPECT_EQ(s1, s2);

}

TEST(TStack, different_stack_not_equal){
	TStack <int> s1(10),s2(10);
	s1.push(10);
	EXPECT_NE(s1,s2);
}

TEST(TStack, stack_with_different_size_not_equal){
	TStack <int> s1(5),s2(10);
	EXPECT_NE(s1,s2);
}