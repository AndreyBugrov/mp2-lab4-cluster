#include <gtest.h>
#include "Cluster.h"
TEST(Cluster, can_create_cluster)
{
	ASSERT_NO_THROW(Cluster c);
}
TEST(Cluster, can_push_element)
{
	Cluster c;
	Task t(3, 4, 5, 6);
	ASSERT_NO_THROW(c.push_back(t));
}
TEST(Cluster, can_get_size)
{
	Cluster c;
	Task t(3, 4, 5, 6);
	Task p(2, 1, 4, 4);
	c.push_back(t);
	c.push_back(p);
	EXPECT_EQ(2, c.size());
}
TEST(Cluster, function_of_execution_works)
{
	//CPU, serial_number, _appear, _dur
	Cluster c(9);
	Task t(3, 4, 5, 6);
	c.push_back(t);
	c.push_back(t);
	for (int i = 0; i < 6; i++)
		c.execute();
	EXPECT_EQ(2*3 * 6, c.total_load());
	c.execute();
	EXPECT_EQ(1, c.downtime());
	EXPECT_EQ(2*3 * 6, c.total_load());
	EXPECT_EQ(MaxFreeProc, c.free_proc());
	EXPECT_EQ(2, c.done());
}