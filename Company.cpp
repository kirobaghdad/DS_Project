#include "Company.h"
#include "UI.h"

Company::Company()
:
NC_Num ( (UI::getNC_Num()) >= 0 ? UI::getNC_Num() : 0),
SC_Num (UI::getSC_Num() >= 0 ? UI::getSC_Num() : 0),
VIPC_Num (UI::getVIPC_Num() >= 0 ? UI::getVIPC_Num() : 0),

NT_Num((UI::getNT_Num()) >= 0 ? UI::getNC_Num() : 0),
ST_Num(UI::getST_Num() >= 0 ? UI::getSC_Num() : 0),
VIPT_Num(UI::getVIPC_Num() >= 0 ? UI::getVIPC_Num() : 0),

NT_Speed ( UI::getNT_Speed() >= 0 ? UI::getNT_Speed() : 0),
ST_Speed ( UI::getST_Speed() >= 0 ? UI::getST_Speed() >= 0 : 0),
VIPT_Speed ( UI::getVIPT_Speed() >= 0 ? UI::getVIPT_Speed() : 0),

NT_Capacity ( UI::getNT_Capacity() >= 0 ? UI::getNT_Capacity() : 0),
ST_Capacity ( UI::getST_Capacity() >= 0 ? UI::getST_Capacity() : 0),
VIPT_Capacity ( UI::getVIPT_Capacity() >= 0 ? UI::getVIPT_Capacity() : 0),

NT_Checkup_Duration (UI::getNT_Checkup_Duration() >= 0 ? UI::getNT_Checkup_Duration() : 0),
ST_Checkup_Duration (UI::getST_Checkup_Duration() >= 0 ? UI::getST_Checkup_Duration() : 0),
VIPT_Checkup_Duration (UI::getVIPT_Checkup_Duration() >= 0 ? UI::getVIPT_Checkup_Duration() : 0),

MaxW (UI::getMaxW() >=0 ? UI::getMaxW() : 0),

AutoPromotionLimit (UI::getAutoPromotionLimit() >= 0 ? UI::getAutoPromotionLimit() : 0)
{  
	
	PC_Num = 0;
	//////////////////////////////////////////

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
