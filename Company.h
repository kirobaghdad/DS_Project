#pragma once
#include<fstream>
#include"Cargo.h"
#include"Event.h"
#include"Truck.h"
#include"Preparation.h"
#include"Promotion.h"
#include"CancelEvent.h"
#include"LinkedQueue.h"
#include"PriorityQueue.h"
#include "Time.h"
using std::ifstream;
using std::ofstream;




class Company
{
private:

	ofstream Out;
	ifstream IN;

// Event List
	LinkedQueue<Event*>  Events;
//Cargo List 
	LinkedQueue<Cargo> NC;
	LinkedQueue<Cargo> SC;

	PriorityQueue<Cargo> VC;
//Truck List 
	LinkedQueue<Truck> NTs;
	LinkedQueue<Truck> STs;
	LinkedQueue<Truck> VTs;
// Moving cargo list 	 
	LinkedQueue<Cargo> Moving;

//Delivered Cargo
	LinkedQueue<Cargo> deliveredCargo;

	Time currentTime;
// Cargo num
	 int NC_Num;
	 int SC_Num;
	 int VIPC_Num;
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
	int NT_Checkup_Duration;
	int ST_Checkup_Duration;
	int VIPT_Checkup_Duration;
	int J;
//Others_Variables
	int AutoPromotionLimit;
	int MaxW;
//Num Of Events
	 int NumOfEvents;

	 Time cargoAvgWait;
	 int avgActiveTime;
	 int avgutilization;

public:
	Company();
	
//input and output functions
	void LoadingFunction();
	void Print(LinkedQueue<Cargo>& DC);
//////////////////////////////////////////
	bool offHours();
	const int getNC_Num();
	int getSC_Num();
	int getVIPC_Num();
	int getNumOfEvents();
	Time getCargoAvgWait();
	int getPC_Num();
	int getNT_Num();
	int getST_Num();
	int getVIPT_Num();
	int getAvgActiveTime();
	int getAvgutilization();

	//Simulator
	void Simulatorfunction();



};

