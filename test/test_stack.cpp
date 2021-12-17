#include "stack.h"
//#include <gtest.h>
#include "gtest/gtest.h"


TEST(stack, can_create_with_positive_size) {
    ASSERT_NO_THROW(TStack<int> tStack(10));
}

TEST(stack, can_not_create_with_negative_size) {
    ASSERT_ANY_THROW(TStack<int> tStack(-10););
}

TEST(stack, can_create_copied_stack) {
    TStack<int> v(10);

    ASSERT_NO_THROW(TStack<int> v1(v));
}

TEST(stack, can_push_new_element) {
    TStack<int> v(2);
    v.push(5);
    EXPECT_EQ(5, v.top());
}

TEST(stack, cant_push_element_when_stack_is_full) {
    TStack<int> v(2);
    v.push(5);
    v.push(7);
    ASSERT_NO_THROW(v.push(9));
}

TEST(stack, can_pop_element) {
    TStack<int> v(2);
    v.push(5);
    v.pop();
    EXPECT_TRUE(v.empty());
}

TEST(stack, can_get_element) {
    TStack<int> v(2);
    v.push(5);
    EXPECT_EQ(5, v.top());
}

TEST(stack, cant_get_element_when_stack_is_empty) {
    TStack<int> v(2);
    ASSERT_ANY_THROW(v.top());
}

TEST(stack, cant_pop_element_when_stack_is_empty) {
    TStack<int> v(2);
    ASSERT_ANY_THROW(v.pop());
}

TEST(stack, new_stack_is_empty) {
    TStack<int> v(2);
    EXPECT_TRUE(v.empty());
}


TEST(stack, can_count_elements_without_elements) {
    TStack<int> v(5);
    EXPECT_EQ(0, v.getSize());
}

TEST(stack, can_count_elements_with_elements) {
    TStack<int> v(5);
    v.push(1);
    v.push(2);
    EXPECT_EQ(2, v.getSize());
}

TEST(stack, can_count_elements_with_all_elemets) {
    TStack<int> v(2);
    v.push(1);
    v.push(2);
    EXPECT_EQ(2, v.getSize());
}

TEST(stack, can_over_allocate_memory) {
    TStack<int> v(1);
    v.push(1);
    v.push(2);
    v.push(3);
    EXPECT_EQ(3, v.getSize());
}
