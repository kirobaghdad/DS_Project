#pragma once
#include"NT.h"
#include"ST.h"
#include"VT.h"
#include"Cargo.h"
#include"Event.h"
#include"LinkedQueue.h"
#include "Time.h"

class Company
{
private:

// Event List
	LinkedQueue<Event*>  Events;
//Cargo List 
	LinkedQueue<Cargo> NC;
	LinkedQueue<Cargo> SC;
	LinkedQueue<Cargo> VC;
//Truck List 
	LinkedQueue<NT> NTs;
	LinkedQueue<ST> STs;
	LinkedQueue<VT> VTs;
//Delivered Cargo
	LinkedQueue<Cargo> deliveredCargo;

	Time currentTime;
	// Cargo num
	static int NC_Num;
	static int SC_Num;
	static int VIPC_Num;
	//Auto-promoted Cargos num
	static int PC_Num;
	// Trucks num 
	static int NT_Num;
	static int ST_Num;
	static int VIPT_Num;
	// Truck Speed 
	const int NT_Speed;
	const int ST_Speed;
	const int VIPT_Speed;
	// Capacity
	const int NT_Capacity;
	const int ST_Capacity;
	const int VIPT_Capacity;
	//Duration
	const int NT_Checkup_Duration;
	const int ST_Checkup_Duration;
	const int VIPT_Checkup_Duration;
	//Others_Variables
	const int AutoPromotionLimit;
	const int MaxW;
	//Num Of Events
	static int NumOfEvents;

	static Time cargoAvgWait;
	static int avgActiveTime;
	static int avgutilization;

public:
	Company();
	bool offHours();
	static const int getNC_Num();
	static int getSC_Num();
	static int getVIPC_Num();
	static int getNumOfEvents();
	static Time getCargoAvgWait();
	static int getPC_Num();
	static int getNT_Num();
	static int getST_Num();
	static int getVIPT_Num();
	static int getAvgActiveTime();
	static int getAvgutilization();
};

