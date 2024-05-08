#include <gtest/gtest.h>

#include "vector.hpp"

TEST(size_arr, size_empty) {
	ABar::Vector<int> vec;
	ASSERT_EQ(vec.size_arr(), 0);
}

TEST(push_back, less_then_capacity) {
	ABar::Vector<int> vec;
	vec.push_back(12);
	ASSERT_EQ(vec.size_arr(), 1);
	ASSERT_EQ(vec[0], 12);
	
}

TEST(push_back, more_then_capacity) {
	ABar::Vector<int> vec;
	vec.push_back(12);
	vec.push_back(13);
	vec.push_back(14);
	ASSERT_EQ(vec.size_arr(), 3);
	ASSERT_EQ(vec[2], 14);

}

TEST(has_item, has_item) {
	ABar::Vector<int> vec;
	vec.push_back(5);
	ASSERT_EQ(vec.has_item(5), true);
}

TEST(has_item, has_no_item) {
	ABar::Vector<int> vec;
	vec.push_back(5);
	ASSERT_EQ(vec.has_item(7), false);
}

TEST(insert, less_then_capacity) {
	ABar::Vector<int> vec;
	vec.push_back(12);
	vec.insert(0, 11);
	ASSERT_EQ(vec[0], 11);
	ASSERT_EQ(vec[1], 12);
}

TEST(insert, more_then_capacity) {
	ABar::Vector<int> vec;
	vec.push_back(12);
	vec.push_back(14);
	ASSERT_EQ(vec.insert(1, 13), false);
}

TEST(remove_first, has_no_item) {
	ABar::Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	ASSERT_EQ(vec.remove_first(3), false);

}

TEST(remove_first, has_one_item) {
	ABar::Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.remove_first(2);
	ASSERT_EQ(vec.size_arr(), 1);
	ASSERT_EQ(vec.has_item(2), false);

}

TEST(remove_first, has_two_item) {
	ABar::Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(1);
	vec.remove_first(1);
	ASSERT_EQ(vec.size_arr(), 2);
	ASSERT_EQ(vec.has_item(1), true);
	ASSERT_EQ(vec[0], 2);
	ASSERT_EQ(vec[1], 1);
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
