#include "Company.h"

int  Truck::id = 0;

int Cargo::numberofcargos = 0;
int Company::NC_Num = 0;
int Company::SC_Num = 0;
int Company::VIPC_Num = 0;
int Company::PC_Num = 0;

Company::Company()
{ 
	currentTime.setDay(0);
	currentTime.setHour(0);
	LoadFile();
}

/**
Returns true if it is off - hours
**/
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

void Company::increaseNC_Num()
{
	NC_Num++;
}

void Company::increaseSC_Num()
{
	SC_Num++;
}

void Company::increaseVIPC_Num()
{
	VIPC_Num++;
}

void Company::increasePC_Num()
{
	PC_Num++;
}

//============================== Get from Input File ==============================//
void Company::LoadFile()
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
		case 'X':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			ptr = new CancelEvent(eventTime, ID);
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

void Company::Print()
{
	Out.open("Output.txt");  //Open Output File

	Out << "CDT ID PT WT TID \n";
	Cargo temp;
	Time T;
	while (totalDeliveredCargo.dequeue(temp))
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
	Out << "������������������ \n";
	Out << "������������������ \n";
	//get number of each typ of cargo and print it
	Out << "Cargos: " << NC_Num + SC_Num + VIPC_Num;
	Out << "[N: " << NC_Num;
	Out << ", S: " << SC_Num;
	Out << ", V: " << VIPC_Num << "] \n";
	Out << "Cargo Avg Wait = " << CargoAvgWait.getDay() << ":" << CargoAvgWait.getHour() << endl;
	Out << "Auto-promoted Cargos:" << (100*PC_Num )/NC_Num << "% \n";

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
	while (!Events.isEmpty() || !NC.isEmpty() || !SC.isEmpty() || !VC.isEmpty() /*|| !MovingNC.isEmpty() || !MovingSC.isEmpty() || !MovingVC.isEmpty() */ )
	{
		if (!Events.isEmpty())
		{
			Events.peek(e);
			while (e->GetTime() == currentTime && !Events.isEmpty())
			{
				e->Execute(NC, SC, VC);
				Events.dequeue(e);
				Events.peek(e);
			}
		}
		//Pick one cargo from each cargo type and move it to moving cargo list(s)
		Cargo c;
	/*	if (!NC.isEmpty())
		{
			NC.removeBeg(c);
			MovingNC.enqueue(c);
		}
		if (!SC.isEmpty())
		{
			SC.dequeue(c);
			MovingSC.enqueue(c);
		}
	
		if (!VC.isEmpty())
		{
			VC.dequeue(c);
			MovingVC.enqueue(c);
		}*/
		//////////////////////////////////////////////

		if (i % 5 == 0)
		{

			if (!NC.isEmpty())
			{
				NC.removeBeg(c);
				c.setCargoDelivreyTime(currentTime);
				deliveredCargoNC.enqueue(c);
				totalDeliveredCargo.enqueue(c);
			}
			if (!SC.isEmpty())
			{
				SC.dequeue(c);
				c.setCargoDelivreyTime(currentTime);
				deliveredCargoSC.enqueue(c);
				totalDeliveredCargo.enqueue(c);
			}

			if (!VC.isEmpty())
			{
				VC.dequeue(c);
				c.setCargoDelivreyTime(currentTime);
				deliveredCargoVC.enqueue(c);
				totalDeliveredCargo.enqueue(c);
			}
		}

		userinterface.print(currentTime, NC, SC, VC, NTs, STs, VTs, MovingNC , MovingSC, MovingVC, deliveredCargoNC, deliveredCargoSC, deliveredCargoVC);
		i++;
		currentTime.increase();
	}
	
}


void Company::assigningCargos() {
	Cargo* newCargo = NULL;
	Truck* newTruck = NULL;

	if (!offHours()) {
		if (VTs.GetCount() != 0) {
			VTs.peek(*newTruck);
			if (VC.GetCount() >= VIPT_Capacity || newTruck->getWaitingTime() >= MaxW) {
				VTs.dequeue(*newTruck);

				for (int i = 0; i < VIPT_Capacity; i++) { //Assigning the cargos to the Truck
					VC.dequeue(*newCargo);
					newTruck->assignCargo(*newCargo);
				}
				assignedTrucks.enqueue(*newTruck);

			}
		}

		if (NTs.GetCount() != 0) {
			NTs.peek(*newTruck);
			if (NC.getcurrentsize() >= NT_Capacity || newTruck->getWaitingTime() >= MaxW) {
				NTs.dequeue(*newTruck);

				for (int i = 0; i < NT_Capacity; i++) { //Assigning the cargos to the Truck
					NC.removeBeg(*newCargo);
					newTruck->assignCargo(*newCargo);
				}
				assignedTrucks.enqueue(*newTruck);
			}
		}

		if (STs.GetCount() != 0) {
			STs.peek(*newTruck);
			if (SC.GetCount() >= ST_Capacity || newTruck->getWaitingTime() >= MaxW) {
				STs.dequeue(*newTruck);

				for (int i = 0; i < ST_Capacity; i++) { //Assigning the cargos to the Truck
					SC.dequeue(*newCargo);
					newTruck->assignCargo(*newCargo);
				}
				assignedTrucks.enqueue(*newTruck);
			}
		}
	}


}