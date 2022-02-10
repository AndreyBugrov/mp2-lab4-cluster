#pragma once
#include "Queue.h"	
#include "Cluster.h"
#include <utility>
static double q = 0.5;
static int MaxCycle = 50;
int MaxQueueSize = 16;
using namespace std;
void get_constants();
pair<vector<int>, double> emulation();
pair<vector<int >, double>create_stats(int task_num, int overflows, int done, int queue_remains, int cluster_remains, double average_load, int downtime);