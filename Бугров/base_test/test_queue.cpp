//#include "all.h"
#include "Queue.h"
#include <gtest.h>

TEST(Queue, can_create_empty_queue)
{
	ASSERT_NO_THROW(Queue<int> q);
}
TEST(Queue, can_copy_empty_queue)
{
	Queue<int> q;
	ASSERT_NO_THROW(Queue<int> p(q));
}
TEST(Queue, copied_queue_has_own_memory)
{
	Queue<char> q;
	Queue<char> q1 = q;
	EXPECT_NE(&q1, &q);
}
TEST(Queue, can_get_size)
{
	Queue<int>q;
	EXPECT_EQ(q.size(), 0);
}
TEST(Queue, can_show_that_queue_is_empty)
{
	Queue<int> q;
	EXPECT_EQ(q.is_empty(), true);
}
TEST(Queue, can_push_element)
{
	Queue<int>q;
	q.push(5);
	EXPECT_EQ(q[0], 5);
	EXPECT_EQ(q.size(), 1);
	EXPECT_EQ(q.is_empty(), false);
}
TEST(Queue, can_show_that_queue_is_full)
{
	Queue<char> q;
	do q.push('3');
	while (q.size() < MaxQueueSize);
	EXPECT_EQ(q.is_full(), true);
	EXPECT_EQ(q.is_empty(), false);
}
TEST(Queue, cant_push_element_to_full_queue)
{
	Queue<double>q;
	do q.push(3.14);
	while (q.size() < MaxQueueSize);
	ASSERT_ANY_THROW(q.push(3.15));
}
TEST(Queue, can_get_element)
{
	Queue<int>q;
	q.push(5);
	EXPECT_EQ(q.get(), 5);
	EXPECT_EQ(q.size(), 1);
	EXPECT_EQ(q.is_empty(), false);
}
TEST(Queue, can_pop_element)
{
	Queue<int>q;
	q.push(5);
	EXPECT_EQ(q.pop(), 5);
	EXPECT_EQ(q.size(), 0);
	EXPECT_EQ(q.is_empty(), true);
}
TEST(Queue, cant_get_and_pop_element_from_empty_queue)
{
	Queue<int>q;
	ASSERT_ANY_THROW(q.get());
	ASSERT_ANY_THROW(q.pop());
}