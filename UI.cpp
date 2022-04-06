#include "UI.h"


UI::UI()
{
	IN.open("Input.txt");  //Open Input File
	Out.open("Output.txt");  //Open Output File

}

UI::~UI()
{
	IN.close();
}

                //============================== File Readers ==============================// 

int UI::getNC_Num()
{
	int NC_Num;
	IN >> NC_Num;
	return NC_Num;
}

int UI::getSC_Num()
{
	int SC_Num;
	IN >> SC_Num;
	return SC_Num;
}

int UI::getVIPC_Num()
{
	int VIPC_Num;
	IN >> VIPC_Num;
	return VIPC_Num;
}


int UI::getNT_Num()
{
	int NT_Num;
	IN >> NT_Num;
	return NT_Num;
}

int UI::getST_Num()
{
	int ST_Num;
	IN >> ST_Num;
	return ST_Num;
}

int UI::getVIPT_Num()
{
	int VIPT_Num;
	IN >> VIPT_Num;
	return VIPT_Num;
}

int UI::getNT_Speed()
{
	int NT_Speed;
	IN >> NT_Speed;
	return NT_Speed;
}

int UI::getST_Speed()
{
	int ST_Speed;
	IN >> ST_Speed;
	return ST_Speed;
}

int UI::getVIPT_Speed()
{
	int VIPT_Speed;
	IN >> VIPT_Speed;
	return VIPT_Speed;
}

int UI::getNT_Capacity()
{
	int NT_Capacity;
	IN >> NT_Capacity;
	return NT_Capacity;
}

int UI::getST_Capacity()
{
	int ST_Capacity;
	IN >> ST_Capacity;
	return ST_Capacity;
}

int UI::getVIPT_Capacity()
{
	int VIPT_Capacity;
	IN >> VIPT_Capacity;
	return VIPT_Capacity;
}

//int UI::getNumOfJourney(int&)
//{
//	IN >> NT_Speed;
//}
int UI::getNT_Checkup_Duration()
{
	int NT_Checkup_Duration;
	IN >> NT_Checkup_Duration;
	return NT_Checkup_Duration;
}

int UI::getST_Checkup_Duration()
{
	int ST_Checkup_Duration;
	IN >> ST_Checkup_Duration;
	return ST_Checkup_Duration;
}

int UI::getVIPT_Checkup_Duration()
{
	int VIPT_Checkup_Duration;
	IN >> VIPT_Checkup_Duration;
	return VIPT_Checkup_Duration;
}

int UI::getAutoPromotionLimit()
{
	int AutoPromotionLimit;
	IN >> AutoPromotionLimit;
	return AutoPromotionLimit;
}

int UI::getMaxW()
{
	int MaxW;
	IN >> MaxW;
	return MaxW;
}

int UI::getNumOfEvents()
{
	int NumOfEvents;
	IN >> NumOfEvents;
	return NumOfEvents;
}

void UI::loadEvents(LinkedQueue <Event*>& E)
{
	Event* ptr = nullptr;
	int day, hours;
	for (int i = 0; i < Company::NumOfEvents; i++)
	{
		char eventTyp;
		char cargoTyp;
		Time eventTime;
		int ID;
		int DIST;
		int LU_Time;
		int cost;
		int extraMoney;
		IN >> eventTyp;
		switch (eventTyp)
		{
		case 'R':
			IN >> cargoTyp;
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			IN >> DIST;
			IN >> LU_Time;
			IN >> cost;
			ptr = new Preparation(eventTime,LU_Time,DIST,cost,ID,cargoTyp);
			E.enqueue(ptr);
			break;
		case 'X':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			//ptr=new CancelEvent();
			E.enqueue(ptr);
			break;
		case 'P':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			IN >> extraMoney;
			ptr = new Promotion(eventTime, ID, extraMoney);
			E.enqueue(ptr);
			break;
		default:
			break;
		}
	}
}

          //============================== Print on Output File ==============================//

void UI::Print(LinkedQueue<Cargo>& DC)
{
	Out << "CDT CID PT WT TID \n";
	Cargo temp;
	Time T;
	while (DC.dequeue(temp))
	{
		//T=temp.getcargoDelivreyTime();
		Out << T.getDay() << ":" << T.getHour() << " ";
		Out << temp.getID()<<" ";
		T = temp.getPT();
		Out << T.getDay() << ":" << T.getHour() << " ";
		//T=temp.getWT();
		Out << T.getDay() << ":" << T.getHour() << " ";
		// the id of truck that delivered the cargo
	}
	Out << "……………………………………………… \n";
	Out << "……………………………………………… \n";
	//get number of each typ of cargo from cagos list and print it
	




	//get number of each typ of trucks from trucks list then print it
}

