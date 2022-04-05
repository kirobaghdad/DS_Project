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
	const int NC_Num;
	const int SC_Num;
	const int VIPC_Num;
	//Auto-promoted Cargos num
	int PC_Num;
	// Trucks num 
	int NT_Num;
	int ST_Num;
	int VIPT_Num;
	// Truck Speed 
	int NT_Speed;
	int ST_Speed;
	int VIPT_Speed;
	// Capacity
	int NT_Capacity;
	int ST_Capacity;
	int VIPT_Capacity;
	//Duration
	const int NT_Checkup_Duration;
	const int ST_Checkup_Duration;
	const int VIPT_Checkup_Duration;


public:
	Company(int, int, int, int, int, int, int, int, int, int, int, int);
	bool offHours();

};

