#include "Company.h"

int Truck::id = 0;

int Cargo::numberofcargos = 0;

int Company::NC_Num = 0;
int Company::SC_Num = 0;
int Company::VIPC_Num = 0;
int Company::PC_Num = 0;

Time Company::currentTime(0, 0);

Company::Company()
{
	currentTime.setDay(1);
	currentTime.setHour(0);
	LoadFile();
}

/**
Returns true if it is off-hours
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

int Company::getAvgUtilization()
{
	return AvgUtilization;
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


	IN >> NT_Checkup_Duration;
	IN >> ST_Checkup_Duration;
	IN >> VIPT_Checkup_Duration;
	IN >> J;
	Truck::SetJ(J);

	//===========================================//
	//create Trucks //////////////////
	for (int i = 0; i < NT_Num; i++)
	{
		Truck* R = new Truck('N', NT_Capacity, NT_Speed, NT_Checkup_Duration);
		NTs.enqueue(R);
	}
	for (int i = 0; i < ST_Num; i++)
	{
		Truck* R = new Truck('S', ST_Capacity, ST_Speed, ST_Checkup_Duration);
		STs.enqueue(R);
	}
	for (int i = 0; i < VIPT_Num; i++)
	{
		Truck* R = new Truck('V', VIPT_Capacity, VIPT_Speed, VIPT_Checkup_Duration);
		VTs.enqueue(R);
	}
	//===========================================//
	//Duration

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
	Cargo tempC;
	Time T;
	Time totalWait;
	int Cnum = totalDeliveredCargo.GetCount();
	while (totalDeliveredCargo.dequeue(tempC))
	{
		T = tempC.getCargoDelivreyTime();
		Out << T.getDay() << ":" << T.getHour() << " ";
		Out << tempC.getID() << " ";
		T = tempC.getPT();
		Out << T.getDay() << ":" << T.getHour() << " ";
		T = tempC.getWaitingTime();
		Out << T.getDay() << ":" << T.getHour() << " ";
		Out << tempC.getTruckId();
		Out << endl;
		totalWait = totalWait + tempC.getWaitingTime();
	}
	CargoAvgWait = totalWait / Cnum;
	Out << "……………………………………………… \n";
	Out << "……………………………………………… \n";
	//get number of each typ of cargo and print it
	Out << "Cargos: " << NC_Num + SC_Num + VIPC_Num;
	Out << "[N: " << NC_Num;
	Out << ", S: " << SC_Num;
	Out << ", V: " << VIPC_Num << "] \n";
	Out << "Cargo Avg Wait = " << CargoAvgWait.getDay() << ":" << CargoAvgWait.getHour() << endl;
	Out << "Auto-promoted Cargos:" << (100*PC_Num )/NC_Num << "% \n";

	Truck* tempT;
	int totalActiveTime = 0;
	while (NTs.dequeue(tempT))
	{
		totalActiveTime += tempT->GetAT();
	}
	while (STs.dequeue(tempT))
	{
		totalActiveTime += tempT->GetAT();
	}
	while (VTs.dequeue(tempT))
	{
		totalActiveTime += tempT->GetAT();
	}
	AvgActiveTime = totalActiveTime / currentTime.getTimeInHours();

	//get number of each typ of trucks and print it
	Out << "Trucks: " << NT_Num + ST_Num + VIPT_Num;
	Out << "[N: " << NT_Num;
	Out << ", S: " << ST_Num;
	Out << ", V: " << VIPT_Num << "] \n";
	Out << "Avg Active time = " << AvgActiveTime << endl;
	Out << "Avg utilization = " << AvgUtilization << "% \n";

	///////////////////////////////////////////////////
	userinterface.printSilentMode('e');
}

void Company::checkAutoPromotion()
{
	Cargo c;
	if (NC.peek(c))
	{
		while (!NC.isEmpty() && c.getWaitingTime().getTimeInHours() + 1 > AutoPromotionLimit)
		{
			Promotion p (currentTime, c.getID(), 0);
			p.Execute(NC, SC, VC);
			NC.peek(c);
		}
	}
}

//==================================Simulator===================================//
void Company::Simulator()
{
	userinterface.printSilentMode('s');
	while (!Events.isEmpty() || !NC.isEmpty() || !SC.isEmpty() || !VC.isEmpty() || !totalMoving.isEmpty()) //On each hour
	{
		Event* e = NULL;                      // a. Execute the events that should be executed at that hour
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
		CheckUp();
		checkAutoPromotion();
		AssignmentOrder();
		movingToDelivered();

		userinterface.print(currentTime, NC, SC, VC, NTs, STs, VTs, totalMoving, totalDeliveredCargo, assignedTrucks, In_Checkup_N_Trucks, In_Checkup_S_Trucks, In_Checkup_VIP_Trucks);
		currentTime.increase();
	}
}


void Company::movingToDelivered() {
	Truck* tempTruck = NULL;
	Cargo tempCargo;
	int x = assignedTrucks.GetCount();
	bool finish = true;
	int i = 0;
	while (finish && i < x)
	{
		assignedTrucks.dequeue(tempTruck);
		(tempTruck)->getCargosQueue().peek(tempCargo);
		if (tempCargo.getCargoDelivreyTime().getTimeInHours() > currentTime.getTimeInHours())
		{
			finish = false;
		}
		while (finish && !((tempTruck)->getCargosQueue().isEmpty()) && (tempCargo).getCargoDelivreyTime().getTimeInHours() <= currentTime.getTimeInHours())
		{
			totalMoving.dequeue(tempCargo);
			(tempTruck)->getCargosQueue().dequeue(tempCargo);
			totalDeliveredCargo.enqueue(tempCargo);
			(tempTruck)->getCargosQueue().peek(tempCargo);
		}

		if (tempTruck->getCargosQueue().GetCount() != 0)
		{
			tempTruck->getCargosQueue().peek(tempCargo);
			assignedTrucks.enqueue(tempTruck, 1.0 / tempCargo.getCargoDelivreyTime().getTimeInHours());
		}
		else
		{
			switch (tempTruck->getType())
			{
			case'N':
				NTs.enqueue(tempTruck);
				break;
			case'S':
				STs.enqueue(tempTruck);
				break;
			case'V':
				VTs.enqueue(tempTruck);
				break;
			}
		}
		i++;
	}
}


void Company::AssignmentOrder()
{
	int Trucks_Count = 0;
	bool VIP_Cargo = 0;
	bool N_Cargo = 0;
	bool S_Cargo = 0;
	Cargo newCargo;
	//=================================== First, assign VIP cargos ======================================//
	if (!VC.isEmpty())
	{
		int i = 0;
		int size = VC.GetCount();
		while (i < size)
		{

			VC.dequeue(newCargo);
			newCargo.setWaitingTime(currentTime);
			VC.enqueue(newCargo, newCargo.getDeliveryDistance() + newCargo.getCost());
			i++;
		}
		if (!VTs.isEmpty() && !VIP_Cargo)
		{
			VIP_Cargo = assigningVipCargos(VC, VTs);
			Trucks_Count += VIP_Cargo;
		}

		if (!NTs.isEmpty() && !VIP_Cargo && VTs.isEmpty())
		{
			VIP_Cargo = assigningVipCargos(VC, NTs);
			Trucks_Count += VIP_Cargo;
		}
		if (!STs.isEmpty() && !VIP_Cargo && VTs.isEmpty() && NTs.isEmpty())
		{
			VIP_Cargo = assigningVipCargos(VC, STs);
			Trucks_Count += VIP_Cargo;
		}
		
	}


	//=================================== Second, assign special cargos ======================================//
	if (!SC.isEmpty())
	{
		int i = 0;
		int size = SC.GetCount();
		while (i < size)
		{
			SC.dequeue(newCargo);
			newCargo.setWaitingTime(currentTime);
			SC.enqueue(newCargo);
			i++;
		}
		if (!STs.isEmpty() && !S_Cargo)
		{
			S_Cargo = assigningSpecialCargos(SC, STs);
			Trucks_Count += S_Cargo;
		}
		
		
	}
	//================================== Third, assign normal cargos =======================================//

	if (!NC.isEmpty()) //NC
	{
		int i = 0;
		int size = NC.getcurrentsize();
		while (i < size)
		{
			NC.removeBeg(newCargo);
			newCargo.setWaitingTime(currentTime);
			NC.add(newCargo);
			i++;
		}
		if (!NTs.isEmpty() && !N_Cargo)
		{
			N_Cargo = assigningNormalCargos(NC, NTs);
			Trucks_Count += N_Cargo;
		}

		if (!VTs.isEmpty() && !N_Cargo && NTs.isEmpty())
		{
			N_Cargo = assigningNormalCargos(NC, VTs);
			Trucks_Count += N_Cargo;
		}
		
	}
	//=========================================================================//
}


void Company::CheckUp() {
	Truck* T;

	//Moving from CheckUp lists to waiting lists
	if (!In_Checkup_N_Trucks.isEmpty()) {
		In_Checkup_N_Trucks.peek(T);
		while (T->isCheckedUp(currentTime)) {
			In_Checkup_N_Trucks.dequeue(T);
			NTs.enqueue(T);
			NTs.peek(T);
		}
	}

	if (!In_Checkup_S_Trucks.isEmpty()) {
		In_Checkup_S_Trucks.peek(T);
		while (T->isCheckedUp(currentTime)) {
			In_Checkup_S_Trucks.dequeue(T);
			STs.enqueue(T);
			STs.peek(T);
		}
	}

	if (!In_Checkup_VIP_Trucks.isEmpty()) {
		In_Checkup_VIP_Trucks.peek(T);
		while (T->isCheckedUp(currentTime)) {
			In_Checkup_VIP_Trucks.dequeue(T);
			VTs.enqueue(T);
			VTs.peek(T);
		}
	}

	//Moving from waiting list to checkup lists

	if (!NTs.isEmpty()) {
		NTs.peek(T);
		while (T->goToCheckUp()) {
			NTs.dequeue(T);
			In_Checkup_N_Trucks.enqueue(T);
			T->setEndCheckUpTime(currentTime + (Time)T->getCheckUpDuration());
			NTs.peek(T);
		}
	}

	if (!STs.isEmpty())
	{
		STs.peek(T);
		while (T->goToCheckUp()) {
			STs.dequeue(T);
			In_Checkup_S_Trucks.enqueue(T);
			T->setEndCheckUpTime(currentTime + (Time)T->getCheckUpDuration());
			STs.peek(T);
		}
	}

	if (!VTs.isEmpty())
	{
		VTs.peek(T);
		while (T->goToCheckUp()) {
			VTs.dequeue(T);
			In_Checkup_VIP_Trucks.enqueue(T);
			T->setEndCheckUpTime(currentTime + (Time)T->getCheckUpDuration());
			VTs.peek(T);
		}
	}

}
bool Company::assigningVipCargos(PriorityQueue<Cargo>& VC, LinkedQueue<Truck*>& Tr)
{
	//Cargo* newCargo = NULL;
	Cargo newCargo;
	Truck* newTruck;
	Time CDT;
	bool done = false;
	Tr.peek(newTruck);
	newTruck->GetTC();
	if (!offHours())
	{
		if (VC.GetCount() >= newTruck->GetTC() && !VC.isEmpty())
		{
			Tr.dequeue(newTruck);
			for (int i = 0; i < newTruck->GetTC(); i++) //Assigning the cargos to the Truck
			{
				//newCargo = new Cargo;
				VC.dequeue(newCargo);
				CDT = currentTime + (Time)(((newCargo).getDeliveryDistance() / (newTruck->GetSpeed() + 0.0)) + (newCargo).getLU_Time());
				newCargo.setIsMoving(true);
				newCargo.setCargoDelivreyTime(CDT);
				newCargo.setTruckId(newTruck->GetID());
				newTruck->assignCargo((newCargo), (1.0 / CDT.getTimeInHours()));
				totalMoving.enqueue(newCargo, 1.0 / CDT.getTimeInHours());
			}
			newTruck->getCargosQueue().peek(newCargo);
			assignedTrucks.enqueue(newTruck, 1.0 / newCargo.getCargoDelivreyTime().getTimeInHours());
			newTruck->setMovingTime(currentTime);
			newTruck->increaseJourneys();
			done = true;
		}
		else
		{    //maxW
			VC.peek(newCargo);
			if (!VC.isEmpty() && newCargo.getWaitingTime().getTimeInHours() >= MaxW)
			{
				Tr.dequeue(newTruck);
				while (!VC.isEmpty() && newCargo.getWaitingTime().getTimeInHours() >= MaxW)
				{
					//newCargo = new Cargo;
					VC.dequeue(newCargo);

					CDT = currentTime + (Time)(((newCargo).getDeliveryDistance() / (newTruck->GetSpeed() + 0.0)) + (newCargo).getLU_Time());
					newCargo.setIsMoving(true);
					newCargo.setCargoDelivreyTime(CDT);
					newCargo.setTruckId(newTruck->GetID());
					newTruck->assignCargo((newCargo), (1.0 / CDT.getTimeInHours()));
					totalMoving.enqueue( newCargo, 1.0 / CDT.getTimeInHours());
					VC.peek(newCargo);

				}
				newTruck->getCargosQueue().peek(newCargo);
				assignedTrucks.enqueue(newTruck, 1.0 / newCargo.getCargoDelivreyTime().getTimeInHours());
				newTruck->setMovingTime(currentTime);
				newTruck->increaseJourneys();
				done = true;
			}
		}
	}
	return done;
}

bool Company::assigningSpecialCargos(LinkedQueue<Cargo>& SC, LinkedQueue<Truck*>& Tr)
{
	//Cargo* newCargo=NULL;
	Cargo newCargo ;
	Truck* newTruck;
	Time CDT;
	bool done=false;
	Tr.peek(newTruck);

	if (!offHours())
	{
		if (SC.GetCount() >= newTruck->GetTC() && !SC.isEmpty())
		{
			Tr.dequeue(newTruck);
			for (int i = 0; i < newTruck->GetTC(); i++) //Assigning the cargos to the Truck
			{
				SC.dequeue(newCargo);
				CDT = currentTime + (Time)(( newCargo).getDeliveryDistance() / (newTruck->GetSpeed() + 0.0) + newCargo.getLU_Time());
				newCargo.setIsMoving(true);
				newCargo.setCargoDelivreyTime(CDT);
				newCargo.setTruckId(newTruck->GetID());
				newTruck->assignCargo((newCargo), (1.0 / CDT.getTimeInHours()));
				totalMoving.enqueue(newCargo, 1.0 / CDT.getTimeInHours());
			}
			newTruck->getCargosQueue().peek(newCargo);
			assignedTrucks.enqueue(newTruck, 1.0 / newCargo.getCargoDelivreyTime().getTimeInHours());
			newTruck->setMovingTime(currentTime);
			newTruck->increaseJourneys();
			done = true;
		}
		else 
		{    //maxW
			SC.peek(newCargo);
			if (!SC.isEmpty() && newCargo.getWaitingTime().getTimeInHours() >= MaxW)
			{
				Tr.dequeue(newTruck);
				while (!SC.isEmpty() && newCargo.getWaitingTime().getTimeInHours() >= MaxW)
				{
					SC.dequeue(newCargo);
					CDT = currentTime + (Time)(((newCargo).getDeliveryDistance() / (newTruck->GetSpeed() + 0.0)) + (newCargo).getLU_Time());
					newCargo.setIsMoving(true);
					newCargo.setCargoDelivreyTime(CDT);
					newCargo.setTruckId(newTruck->GetID());
					newTruck->assignCargo((newCargo), (1.0 / CDT.getTimeInHours()));
					totalMoving.enqueue(newCargo, 1.0 / CDT.getTimeInHours());
					SC.peek(newCargo);
					
				}
				newTruck->getCargosQueue().peek(newCargo);
				assignedTrucks.enqueue(newTruck, 1.0 / newCargo.getCargoDelivreyTime().getTimeInHours());
				newTruck->setMovingTime(currentTime);
				newTruck->increaseJourneys();
				done = true;
			}
		}

	}
	return done;
}


bool Company::assigningNormalCargos(Linked_list<Cargo>& NC, LinkedQueue<Truck*>& Tr)
{
	//Cargo* newCargo = NULL;
	Cargo newCargo;
	Truck* newTruck;
	Time CDT;
	bool done = false;

	Tr.peek(newTruck);
	if (!offHours())
	{
		if (NC.getcurrentsize() >= newTruck->GetTC() && !NC.isEmpty())
		{
			Tr.dequeue(newTruck);
			for (int i = 0; i < newTruck->GetTC(); i++) //Assigning the cargos to the Truck
			{
			//	newCargo = new Cargo;
				NC.removeBeg(newCargo);
				CDT = currentTime + (Time)((( newCargo).getDeliveryDistance() / (newTruck->GetSpeed() + 0.0)) + (newCargo).getLU_Time());
				
				newCargo.setIsMoving(true);
				newCargo.setCargoDelivreyTime(CDT);
				newCargo.setTruckId(newTruck->GetID());
				newTruck->assignCargo((newCargo), (1.0 / CDT.getTimeInHours()));
				totalMoving.enqueue(newCargo, 1.0 / CDT.getTimeInHours());
			}
			newTruck->getCargosQueue().peek(newCargo);
			assignedTrucks.enqueue(newTruck, 1.0 / newCargo.getCargoDelivreyTime().getTimeInHours());
			newTruck->setMovingTime(currentTime);
			newTruck->increaseJourneys();
			done = true;
		}
		else
		{    //maxW
			NC.peek(newCargo);
			if (!NC.isEmpty() && newCargo.getWaitingTime().getTimeInHours() >= MaxW)
			{
				Tr.dequeue(newTruck);
				while (!NC.isEmpty() && newCargo.getWaitingTime().getTimeInHours() >= MaxW)
				{
					NC.removeBeg(newCargo);
					CDT = currentTime + (Time)(((newCargo).getDeliveryDistance() / (newTruck->GetSpeed() + 0.0)) + (newCargo).getLU_Time());
					newCargo.setIsMoving(true);
					newCargo.setCargoDelivreyTime(CDT);
					newCargo.setTruckId(newTruck->GetID());
					newTruck->assignCargo((newCargo), (1.0 / CDT.getTimeInHours()));
					totalMoving.enqueue(newCargo, 1.0 / CDT.getTimeInHours());

				}
				newTruck->getCargosQueue().peek(newCargo);
				assignedTrucks.enqueue(newTruck, 1.0 / newCargo.getCargoDelivreyTime().getTimeInHours());
				newTruck->setMovingTime(currentTime);
				newTruck->increaseJourneys();
				done = true;
			}
		}
	}
	return done;
}


Time Company::getCurrentTime() {
	return currentTime;
}












/*void Company::assigningCargos()
{
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


}*/

















//int i = 1;
//Event* e = NULL;
//while (!Events.isEmpty() || !NC.isEmpty() || !SC.isEmpty() || !VC.isEmpty() /*|| !MovingNC.isEmpty() || !MovingSC.isEmpty() || !MovingVC.isEmpty() */ )
//{
//	if (!Events.isEmpty())
//	{
//		Events.peek(e);
//		while (e->GetTime() == currentTime && !Events.isEmpty())
//		{
//			e->Execute(NC, SC, VC);
//			Events.dequeue(e);
//			Events.peek(e);
//		}
//	}
//	//Pick one cargo from each cargo type and move it to moving cargo list(s)
//	Cargo c;
///*	if (!NC.isEmpty())
//	{
//		NC.removeBeg(c);
//		MovingNC.enqueue(c);
//	}
//	if (!SC.isEmpty())
//	{
//		SC.dequeue(c);
//		MovingSC.enqueue(c);
//	}
//
//	if (!VC.isEmpty())
//	{
//		VC.dequeue(c);
//		MovingVC.enqueue(c);
//	}*/
//	//////////////////////////////////////////////

//	if (i % 5 == 0)
//	{

//		if (!NC.isEmpty())
//		{
//			NC.removeBeg(c);
//			c.setCargoDelivreyTime(currentTime);
//			deliveredCargoNC.enqueue(c);
//			totalDeliveredCargo.enqueue(c);
//		}
//		if (!SC.isEmpty())
//		{
//			SC.dequeue(c);
//			c.setCargoDelivreyTime(currentTime);
//			deliveredCargoSC.enqueue(c);
//			totalDeliveredCargo.enqueue(c);
//		}

//		if (!VC.isEmpty())
//		{
//			VC.dequeue(c);
//			c.setCargoDelivreyTime(currentTime);
//			deliveredCargoVC.enqueue(c);
//			totalDeliveredCargo.enqueue(c);
//		}
//	}

//	userinterface.print(currentTime, NC, SC, VC, NTs, STs, VTs, MovingNC , MovingSC, MovingVC, deliveredCargoNC, deliveredCargoSC, deliveredCargoVC);
//	i++;
//	currentTime.increase();
//}
//