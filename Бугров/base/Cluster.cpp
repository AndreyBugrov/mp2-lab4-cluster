#include "Cluster.h"
void Cluster::execute()
{
	if (tasks.empty())
		Downtime++;
	else
		for (int i = 0; i < tasks.size(); i++)
		{
			if (tasks[i].is_new())
				tasks[i].start(clock_cycle);
			Total_load += tasks[i].get_proc();
			if (tasks[i].execute())
			{
				free += tasks[i].get_proc();
				tasks.erase(tasks.begin() + i);
				Done++;
				i--;
			}
		}
	clock_cycle++;
}