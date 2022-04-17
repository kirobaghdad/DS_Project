#include "Company.h"


Company::Company()
{ 
	PC_Num = 1;
	currentTime.setDay(0);
	currentTime.setHour(0);
	Loading();
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
	return CargoAvgWait;
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
	return AvgActiveTime;
}

int Company::getAvgutilization()
{
	return Avgutilization;
}

//============================== Get from Input File ==============================//
void Company::Loading()
{
	IN.open("Input.txt");  //Open Input File

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
		Truck* R = new Truck('N', NT_Capacity, NT_Speed);
		NTs.enqueue(*R);
	}
	for (int i = 0; i < ST_Num; i++)
	{
		Truck* R = new Truck('S', ST_Capacity, ST_Speed);
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
	for (int i = 0; i < NumOfEvents; i++)
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
		/*case 'X':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			ptr = new CancelEvent(eventTime, ID);
			Events.enqueue(ptr);
			break;*/
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

void Company::Print()
{
	Out.open("Output.txt");  //Open Output File

	Out << "CDT CID PT WT TID \n";
	Cargo temp;
	Time T;
	while (deliveredCargo.dequeue(temp))
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
	Out << "Cargos: " << NC_Num + SC_Num + VIPC_Num;
	Out << "[N: " << NC_Num;
	Out << ", S: " << SC_Num;
	Out << ", V: " << VIPC_Num << "] \n";
	Out << "Cargo Avg Wait = " << CargoAvgWait.getDay() << ":" << CargoAvgWait.getHour() << endl;
	Out << "Auto-promoted Cargos:" << NC_Num / PC_Num << "% \n";

	//get number of each typ of trucks and print it
	Out << "Trucks: " << NT_Num + ST_Num + VIPT_Num;
	Out << "[N: " << NT_Num;
	Out << ", S: " << ST_Num;
	Out << ", V: " << VIPT_Num << "] \n";
	Out << "Avg Active time = " << AvgActiveTime << endl;
	Out << "Avg utilization = " << Avgutilization << "% \n";
}

//==================================Simulator===================================//
void Company::Simulator()
{

	int i = 1;
	Event* e = NULL;
	while (!Events.isEmpty() || !NC.isEmpty() || !SC.isEmpty() || !VC.isEmpty() || !Moving.isEmpty())
	{
		if (!Events.isEmpty())
		{
			Events.peek(e);
			if (e->GetTime() == currentTime)
			{
				e->Execute(NC, SC, VC);
				Events.dequeue(e);
			}
		}
		//Pick one cargo from each cargo type and move it to moving cargo list(s)
		Cargo c;
		if (!NC.isEmpty())
		{
			NC.removeBeg(c);
			Moving.enqueue(c);
		}
		if (!SC.isEmpty())
		{
			SC.dequeue(c);
			Moving.enqueue(c);
		}
	
		if (!VC.isEmpty())
		{
			VC.dequeue(c);
			Moving.enqueue(c);
		}

		
		//////////////////////////////////////////////

		if (i % 5 == 0)
		{

			if (!Moving.isEmpty())
			{
				Moving.dequeue(c);
				deliveredCargo.enqueue(c);
			}
			if (!Moving.isEmpty())
			{
				Moving.dequeue(c);
				deliveredCargo.enqueue(c);
			}

			if (!Moving.isEmpty())
			{
				Moving.dequeue(c);
				deliveredCargo.enqueue(c);
			}
		}

		i++;
		currentTime.increase();
	}
	
}


