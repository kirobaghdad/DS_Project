#include "Company.h"
#include "UI.h"




Company::Company()
{  
	currentTime.setDay(0);
	currentTime.setHour(0);
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

int Company::getNumOfEvents()
{
	return NumOfEvents;
}

Time Company::getCargoAvgWait()
{
	return cargoAvgWait;
}

int Company::getPC_Num()
{
	return PC_Num;
}

int Company::getNT_Num()
{
	return NT_Num;
}

int Company::getST_Num()
{
	return ST_Num;
}

int Company::getVIPT_Num()
{
	return VIPT_Num;
}

int Company::getAvgActiveTime()
{
	return avgActiveTime;
}

int Company::getAvgutilization()
{
	return avgutilization;
}

void Company::Simulatorfunction()
{
}

//============================== Get from Input File ==============================//
void Company::LoadingFunction()
{
	IN.open("Input.txt");  //Open Input File
	Out.open("Output.txt");  //Open Output File
	// Trucks num 
	IN >> NT_Num;
	IN >> ST_Num;
	IN >> VIPT_Num;

	// Truck Speed 
	IN >> NT_Speed;
	IN >> ST_Speed;
	IN >> VIPT_Speed;
	// Capacity
	IN >> NT_Capacity;
	IN >> ST_Capacity;
	IN >> VIPT_Capacity;

	//===========================================//
	//create Trucks //////////////////
	for (int i = 0; i < NT_Num; i++)
	{
		Truck*R = new Truck('N', NT_Capacity, NT_Speed);
		NTs.enqueue(*R);
	}
	for (int i = 0; i < ST_Num; i++)
	{
		Truck* R = new Truck('S', ST_Capacity,ST_Speed);
		STs.enqueue(*R);
	}
	for (int i = 0; i < VIPT_Num; i++)
	{
		Truck* R = new Truck('V', VIPT_Capacity, VIPT_Speed);
		VTs.enqueue(*R);
	}
	//===========================================//
	//Duration
	IN >> NT_Checkup_Duration;
	IN >> ST_Checkup_Duration;
	IN >> VIPT_Checkup_Duration;
	IN >> J;
	//Others_Variables
	IN >> AutoPromotionLimit;
	IN >> MaxW;

    //Events
	IN >> NumOfEvents;

	//create event 
	Event* ptr = nullptr;
	int day, hours;
	for (int i = 0; i < Company::getNumOfEvents(); i++)
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
			ptr = new Preparation(eventTime, LU_Time, DIST, cost, ID, cargoTyp);
			Events.enqueue(ptr);
			break;
		case 'X':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			//ptr=new CancelEvent();
			Events.enqueue(ptr);
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
			Events.enqueue(ptr);
			break;
		default:
			break;
		}
	}
}

//============================== Print on Output File ==============================//

void Company::Print(LinkedQueue<Cargo>& DC)
{
	Out << "CDT CID PT WT TID \n";
	Cargo temp;
	Time T;
	while (DC.dequeue(temp))
	{
		T = temp.getCargoDelivreyTime();
		Out << T.getDay() << ":" << T.getHour() << " ";
		Out << temp.getID() << " ";
		T = temp.getPT();
		Out << T.getDay() << ":" << T.getHour() << " ";
		T = temp.getWaitingTime();
		Out << T.getDay() << ":" << T.getHour() << " ";
		// the id of truck that delivered the cargo
		Out << endl;
	}
	Out << "……………………………………………… \n";
	Out << "……………………………………………… \n";
	//get number of each typ of cargo and print it
	Out << "Cargos: " << Company::getNC_Num() + Company::getSC_Num() + Company::getVIPC_Num();
	Out << "[N: " << Company::getNC_Num();
	Out << ", S: " << Company::getSC_Num();
	Out << ", V: " << Company::getVIPC_Num() << "] \n";
	Out << "Cargo Avg Wait = " << Company::getCargoAvgWait().getDay() << ":" << Company::getCargoAvgWait().getHour() << endl;
	Out << "Auto-promoted Cargos:" << Company::getNC_Num() / Company::getPC_Num() << "% \n";

	//get number of each typ of trucks and print it
	Out << "Trucks: " << Company::getNT_Num() + Company::getST_Num() + Company::getVIPT_Num();
	Out << "[N: " << Company::getNT_Num();
	Out << ", S: " << Company::getST_Num();
	Out << ", V: " << Company::getVIPT_Num() << "] \n";
	Out << "Avg Active time = " << Company::getAvgActiveTime() << endl;
	Out << "Avg utilization = " << Company::getAvgutilization() << "% \n";
}


