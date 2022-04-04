#pragma once
#include "Time.h"
class Company
{
private:
	Time currentTime;

	const int NC_Num;
	const int SC_Num;
	const int VIPC_Num;

	const int NT_Speed;
	const int ST_Speed;
	const int VIPT_Speed;

	const int NT_Capacity;
	const int ST_Capacity;
	const int VIPT_Capacity;

	const int NT_Checkup_Duration;
	const int ST_Checkup_Duration;
	const int VIPT_Checkup_Duration;


public:
	Company(int, int, int, int, int, int, int, int, int, int, int, int);
	bool offHours();

};

