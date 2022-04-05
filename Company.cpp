#include "Company.h"
#include "UI.h"

Company::Company(int NC_Num, int SC_Num,int VIPC_Num, int NT_Speed,int ST_Speed,int VIPT_Speed,int NT_Capacity,int ST_Capacity,int VIPT_Capacity,int NT_Checkup_Duration,int ST_Checkup_Duration,int VIPT_Checkup_Duration)
:
NC_Num ( NC_Num >= 0 ? NC_Num : 0),
SC_Num (SC_Num >= 0 ? SC_Num : 0),
VIPC_Num (VIPC_Num >= 0 ? VIPC_Num : 0),

//NT_Speed ( NT_Speed >= 0 ? NT_Speed : 0),
//ST_Speed ( ST_Speed >= 0 ? ST_Speed : 0),
//VIPT_Speed ( VIPT_Speed >= 0 ? VIPT_Speed : 0),

//NT_Capacity ( NT_Capacity >= 0 ? NT_Capacity : 0),
//ST_Capacity ( ST_Capacity >= 0 ? ST_Capacity : 0),
//VIPT_Capacity ( VIPT_Capacity >= 0 ? VIPT_Capacity : 0),

NT_Checkup_Duration (NT_Checkup_Duration >= 0 ? NT_Checkup_Duration : 0),
ST_Checkup_Duration (ST_Checkup_Duration >= 0 ? ST_Checkup_Duration : 0),
VIPT_Checkup_Duration (VIPT_Checkup_Duration >= 0 ? VIPT_Checkup_Duration : 0)

{   //////////////make UI object///////////////
	UI userInterface;
	//////////////////////////////////////////

	/////////////Load Events List/////////////
	userInterface.loadEvents(Events);
	//////////////////////////////////////////

	currentTime.setDay(0);
	currentTime.setHour(0);
	//Get the constants of UI 
	
	//first: number of Trucks //////////////////
	NT_Num =userInterface.getNumOfNT();
	ST_Num =userInterface.getNumOfST();
	VIPT_Num =userInterface.getNumOfVT();
	///////////////////////////////////////////
	
	//second: Speed //////////////////////////
	NT_Speed = userInterface.getNTSpeed();
	VIPT_Speed = userInterface.getVTSpeed();
	ST_Speed = userInterface.getSTSpeed();
	NT::SetSpeed(NT_Speed);
	ST::SetSpeed(ST_Speed);
	VT::SetSpeed(VIPT_Speed);
	/////////////////////////////////////////////////
	
	//Third: Capacity///////////////////////////////
	NT_Capacity = userInterface.getNTCapacity();
	ST_Capacity = userInterface.getSTCapacity();
	VIPT_Capacity = userInterface.getVTCapacity();
	NT::SetTC(NT_Capacity);
	ST::SetTC(ST_Capacity);
	VT::SetTC(VIPT_Capacity);
   //////////////////////////////////////////////////
	
	//create Trucks //////////////////
	for (int i = 0; i < NT_Num; i++)
	{
		NT * R = new NT;
		NTs.enqueue(*R);
	}
	for (int i = 0; i < ST_Num; i++)
	{
		ST* R = new ST;
		STs.enqueue(*R);
	}
	for (int i = 0; i < VIPT_Num; i++)
	{
		VT* R = new VT;
		VTs.enqueue(*R);
	}
	/////////////////////////////













}

bool Company::offHours() {
	if (currentTime.getHour() < 5 || currentTime.getHour() > 23) {
		return true;
	}
	else return false;
}
