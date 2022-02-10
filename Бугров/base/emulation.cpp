#include "emulation.h"
#include <random>
using namespace std;
void get_constants()
{
	do
	{
		cout << "¬ведите значение q, 0<=q<=1. ƒробную часть отдел€йте точкой\n";
		cin >> q;
	} while (!(0 <= q && q <= 1));
	do
	{
		cout << "¬ведите S - максимальный размер очереди, 5<=S<=50\n";
		cin >> MaxQueueSize;
	} while (!(5 <= MaxQueueSize && MaxQueueSize <= 50));
	do
	{
		cout << "¬ведите P - число процессоров в кластере, 1<=P<=64\n";
		cin >> MaxFreeProc;
	} while (!(1 <= MaxFreeProc && MaxFreeProc <= 64));
	MaxProc = MaxFreeProc - (MaxFreeProc / 8);
	do
	{
		cout << "¬ведите T - число тактов работы кластера, 10<=T<=10 000\n";
		cin >> MaxCycle;
	} while (!(10 <= MaxCycle && MaxCycle <= 10000));
}

pair<vector<int>, double> emulation()
{
	Queue<Task> queue;
	Cluster cluster;
	std::mt19937 mersenne(time(NULL));
	int task_num = 1;
	int overflows = 0;
	double q1;
	for (int i = 0; i < MaxCycle; i++)
	{
		q1 = double(mersenne()) / mersenne.max();
		if (q1 >= q)
		{
			try
			{
				//CPU, serial_number, _appear, _dur
				Task task(mersenne() % MaxProc + 1, task_num, i, mersenne() % MaxDur + 1);
				task_num++;
				queue.push(task);
			}
			catch (ans)
			{
				overflows++;
			}
		}
		while (!queue.is_empty())
			if (queue.get().get_proc() <= cluster.free_proc())
				cluster.push_back(queue.pop());
			else
				break;
		cluster.execute();
	}
	double average_load = double(cluster.total_load()) / double(MaxCycle * MaxFreeProc);
	return create_stats(task_num, overflows, cluster.done(), queue.size(), cluster.size(), average_load, cluster.downtime());
}

pair<vector<int >, double>create_stats(int task_num, int overflows, int done, int queue_remains, int cluster_remains, double average_load, int downtime)
{
	pair<vector<int>, double>stats;
	stats.first = { task_num, overflows, done, queue_remains, cluster_remains, downtime };
	stats.second = average_load;
	return stats;
}