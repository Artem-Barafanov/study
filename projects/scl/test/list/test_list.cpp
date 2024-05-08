#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

TEST(size, size_no_empty) {
	ABar::DoublyLinkedList<int> list1;
	list1.push_back(5);
	ASSERT_EQ(list1.size(), 1);
}

TEST(push_back, for_empty_list) {
	ABar::DoublyLinkedList<int> list1;
	list1.push_back(7);
	ASSERT_EQ(list1.size(), 1);
	ASSERT_EQ(list1.get()->next->value, 7);
}

TEST(push_back, for_not_empty_list) {
	ABar::DoublyLinkedList<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	ASSERT_EQ(list1.size(), 3);
	ASSERT_EQ(list1.get()->next->next->value, 2);
	ASSERT_EQ(list1.get()->next->next->next->value, 3);
}

TEST(has_item, has_item) {
	ABar::DoublyLinkedList<int> list1;
	list1.push_back(1);
	ASSERT_EQ(list1.has_item(1), true);
}

TEST(has_item, has_no_item) {
	ABar::DoublyLinkedList<int> list1;
	list1.push_back(1);
	ASSERT_EQ(list1.has_item(5), false);
}

TEST(remove_first, has_no_item) {
	ABar::DoublyLinkedList<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	ASSERT_EQ(list1.remove_first(3), false);

}

TEST(remove_first, has_one_item) {
	ABar::DoublyLinkedList<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.remove_first(2);
	ASSERT_EQ(list1.size(), 1);
	ASSERT_EQ(list1.has_item(2), false);
	ASSERT_EQ(list1.get()->next->next->value, 0);
}

TEST(remove_first, has_two_item) {
	ABar::DoublyLinkedList<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(1);
	list1.remove_first(1);
	ASSERT_EQ(list1.size(), 2);
	ASSERT_EQ(list1.has_item(1), true);
	ASSERT_EQ(list1.get()->next->value, 2);
}

/*
TEST(print, ) {
	ABar::Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
}
*/

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
