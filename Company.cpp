#include "Company.h"
#include "UI.h"

int ST::TC;
int ST::Speed;
int NT::TC;
int NT::Speed;
int VT::TC;
int VT::Speed;

int Company::NC_Num;
int Company::VIPC_Num;
int Company::SC_Num;

Company::Company()
	:
NT_Num( UI::readNT_Num()/* >= 0 ? UI::readNT_Num() : 0*/),
ST_Num( UI::readST_Num()/* >= 0 ? UI::readST_Num() : 0*/),
VIPT_Num( UI::readVIPT_Num()/* >= 0 ? UI::readVIPT_Num() : 0*/),

NT_Speed ( UI::readNT_Speed()/* >= 0 ? UI::readNT_Speed() : 0*/),
ST_Speed ( UI::readST_Speed()/* >= 0 ? UI::readST_Speed() >= 0 : 0*/),
VIPT_Speed ( UI::readVIPT_Speed()/* >= 0 ? UI::readVIPT_Speed() : 0*/),

NT_Capacity ( UI::readNT_Capacity()/* >= 0 ? UI::readNT_Capacity() : 0*/),
ST_Capacity ( UI::readST_Capacity()/* >= 0 ? UI::readST_Capacity() : 0*/),
VIPT_Capacity ( UI::readVIPT_Capacity()/* >= 0 ? UI::readVIPT_Capacity() : 0*/),

NT_Checkup_Duration (UI::readNT_Checkup_Duration()/* >= 0 ? UI::readNT_Checkup_Duration() : 0*/),
ST_Checkup_Duration (UI::readST_Checkup_Duration()/* >= 0 ? UI::readST_Checkup_Duration() : 0*/),
VIPT_Checkup_Duration (UI::readVIPT_Checkup_Duration()/* >= 0 ? UI::readVIPT_Checkup_Duration() : 0*/),

MaxW (UI::readMaxW() >=0 ? UI::readMaxW() : 0),

AutoPromotionLimit (UI::readAutoPromotionLimit() >= 0 ? UI::readAutoPromotionLimit() : 0)
{  
	
	PC_Num = 0;
	//////////////////////////////////////////
	NC_Num = 0;
	SC_Num = 0;
	VIPC_Num = 0;


	currentTime.setDay(0);
	currentTime.setHour(0);
	//Get the constants of UI 
	
	////first: number of Trucks //////////////////
	//NT_Num =userInterface.getNumOfNT();
	//ST_Num =userInterface.getNumOfST();
	//VIPT_Num =userInterface.getNumOfVT();
	///////////////////////////////////////////
	
	//second: Speed //////////////////////////
	/*NT_Speed = userInterface.getNTSpeed();
	VIPT_Speed = userInterface.getVTSpeed();
	ST_Speed = userInterface.getSTSpeed();*/
	NT::SetSpeed(NT_Speed);
	ST::SetSpeed(ST_Speed);
	VT::SetSpeed(VIPT_Speed);
	/////////////////////////////////////////////////
	
	//Third: Capacity///////////////////////////////
	/*NT_Capacity = userInterface.getNTCapacity();
	ST_Capacity = userInterface.getSTCapacity();
	VIPT_Capacity = userInterface.getVTCapacity();*/
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

const int Company::getNC_Num()
{
	return NC_Num;
}

int Company::getSC_Num() 
{
	return SC_Num;
}

int Company::getVIPC_Num() 
{
	return VIPC_Num;
}
