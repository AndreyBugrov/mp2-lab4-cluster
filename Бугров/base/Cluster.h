#pragma once
#include "Task.h"
#include <vector>
int MaxFreeProc = 16;
int MaxProc = 12;
int MaxDur = 6;
class Cluster
{
private:
	int free;
	std::vector<Task> tasks;
	int Done;
	int Total_load;
	int Downtime;
	int clock_cycle;
public:
	Cluster(size_t _clock = 0) :tasks(0), Done(0), Total_load(0), Downtime(0), clock_cycle(_clock)
	{
		free = MaxFreeProc;
	}
	int done()
	{
		return Done;
	}
	int total_load()
	{
		return Total_load;
	}
	int downtime()
	{
		return Downtime;
	}
	void push_back(Task t)
	{
		tasks.push_back(t);
		free -= t.get_proc();
	}
	int size()
	{
		return tasks.size();
	}
	int free_proc()
	{
		return free;
	}
	void execute();
};
