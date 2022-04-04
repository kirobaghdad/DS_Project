#include "Company.h"
#include "UI.h"

Company::Company(int NC_Num, int SC_Num,int VIPC_Num, int NT_Speed,int ST_Speed,int VIPT_Speed,int NT_Capacity,int ST_Capacity,int VIPT_Capacity,int NT_Checkup_Duration,int ST_Checkup_Duration,int VIPT_Checkup_Duration)
:
NC_Num ( NC_Num >= 0 ? NC_Num : 0),
SC_Num (SC_Num >= 0 ? SC_Num : 0),
VIPC_Num (VIPC_Num >= 0 ? VIPC_Num : 0),

NT_Speed ( NT_Speed >= 0 ? NT_Speed : 0),
ST_Speed ( ST_Speed >= 0 ? ST_Speed : 0),
VIPT_Speed ( VIPT_Speed >= 0 ? VIPT_Speed : 0),

NT_Capacity ( NT_Capacity >= 0 ? NT_Capacity : 0),
ST_Capacity ( ST_Capacity >= 0 ? ST_Capacity : 0),
VIPT_Capacity ( VIPT_Capacity >= 0 ? VIPT_Capacity : 0),

NT_Checkup_Duration (NT_Checkup_Duration >= 0 ? NT_Checkup_Duration : 0),
ST_Checkup_Duration (ST_Checkup_Duration >= 0 ? ST_Checkup_Duration : 0),
VIPT_Checkup_Duration (VIPT_Checkup_Duration >= 0 ? VIPT_Checkup_Duration : 0)

{
	UI userInterface;
	currentTime.setDay(0);
	currentTime.setHour(0);
}

bool Company::offHours() {
	if (currentTime.getHour() < 5 || currentTime.getHour() > 23) {
		return true;
	}
	else return false;
}
