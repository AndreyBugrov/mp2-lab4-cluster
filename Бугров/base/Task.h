#pragma once
#include "Ans.h"
#include "MaxValues.h"
class Task
{
protected:
	int appear;//появление +
	int dur;//длительность +
	int begin;//такт начала выполнения *
	int proc;//число необходимых процессоров *
	int num;//порядковый номер задания +
	int remains;//оставшееся число тактов выполнения
public:
	//CPU, serial_number, _appear, _dur
	Task(size_t CPU = 0, size_t serial_number = 0, size_t _appear = 0, size_t _dur = 0) :appear(0), begin(-1), num(serial_number)
	{
		if (_dur > MaxDur)
			throw ans::out_of_range;
		else
			dur = _dur;
		if (CPU > MaxProc)
			throw ans::out_of_range;
		else
			proc = CPU;
		remains = dur;
	}
	bool execute()
	{
		remains--;
		return(remains == 0);
	}
	bool is_new()const
	{
		return(begin < 0);
	}
	void start(size_t clock_cycle)
	{
		//Проверка на более чем первый старт отсутствует, потому что в кластере и так это проверяется
		begin = clock_cycle;
	}
	int get_proc() const
	{
		return proc;
	}
};