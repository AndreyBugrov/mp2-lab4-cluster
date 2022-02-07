//#include "all.h"
#include "Task.h"
#include <gtest.h>
TEST(Task, can_create_fake_task)
{
	ASSERT_NO_THROW(Task t);
}
TEST(Task, can_create_normal_task)
{
	ASSERT_NO_THROW(Task t(3, 4, 5, 6));
}
TEST(Task, cant_create_task_with_too_large_duration)
{
	ASSERT_ANY_THROW(Task t(3, 4, 5, 7));
}
TEST(Task, cant_create_task_with_too_large_number_of_prosessors)
{
	ASSERT_ANY_THROW(Task t(13, 4, 5, 6));
}
TEST(Task, can_show_wherether_task_is_new)
{
	Task t;
	EXPECT_EQ(t.is_new(), true);
}
TEST(Task, can_start)
{
	Task t;
	t.start(3);
	EXPECT_EQ(t.is_new(), false);
}
TEST(Task, function_of_execution_works)
{
	//CPU, serial_number, _appear, _dur
	Task t(1, 3, 5, 6);
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(false, t.execute());
	EXPECT_EQ(true, t.execute());
}
