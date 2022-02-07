#pragma once
#include "Ans.h"
#include "MaxValues.h"
class Task
{
protected:
	int appear;//��������� +
	int dur;//������������ +
	int begin;//���� ������ ���������� *
	int proc;//����� ����������� ����������� *
	int num;//���������� ����� ������� +
	int remains;//���������� ����� ������ ����������
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
		//�������� �� ����� ��� ������ ����� �����������, ������ ��� � �������� � ��� ��� �����������
		begin = clock_cycle;
	}
	int get_proc() const
	{
		return proc;
	}
};