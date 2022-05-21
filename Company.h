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
#include "Linked_list.h"
#include"UI.h"
using std::ifstream;
using std::ofstream;




class Company
{
private:

	ofstream Out;
	ifstream IN;

	//
	UI userinterface;
	// Event List
	LinkedQueue<Event*>  Events;
	// Waiting  Cargo List 
	Linked_list<Cargo>   NC;
	LinkedQueue<Cargo>   SC;
	PriorityQueue<Cargo> VC;

	//Truck List 
	LinkedQueue<Truck> NTs;
	LinkedQueue<Truck> STs;
	LinkedQueue<Truck> VTs;


	// Moving Cargos List 	 
	LinkedQueue<Cargo> MovingNC;
	LinkedQueue<Cargo> MovingSC;
	LinkedQueue<Cargo> MovingVC;

	//Delivered Cargos List
	LinkedQueue<Cargo> deliveredCargoNC;
	LinkedQueue<Cargo> deliveredCargoSC;
	LinkedQueue<Cargo> deliveredCargoVC;
	LinkedQueue<Cargo> totalDeliveredCargo;

	LinkedQueue<Truck> assignedTrucks;

	LinkedQueue<Truck> In_Checkup_N_Trucks;

	LinkedQueue<Truck> In_Checkup_S_Trucks;

	LinkedQueue<Truck> In_Checkup_VIP_Trucks;

	static Time currentTime;
	// Cargo num
	static int NC_Num;
	static int SC_Num;
	static int VIPC_Num;
	//Auto-promoted Cargos num
	static int PC_Num;
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

	Time CargoAvgWait;
	int AvgActiveTime;
	int AvgUtilization;

public:
	Company();

	//input and output functions
	void LoadFile();
	void Print();
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
	int getAvgUtilization();
	static void increaseNC_Num();
	static void increaseSC_Num();
	static void increaseVIPC_Num();
	static void increasePC_Num();
	//Auto Promotion
	void checkAutoPromotion();
	//Simulator
	void Simulator();
	void assigningCargos();
	void CheckUp();

	bool assigningVipCargos (PriorityQueue<Cargo> &VC, LinkedQueue<Truck> &Tr );
	bool assigningSpecialCargos(LinkedQueue<Cargo>&SC, LinkedQueue<Truck>& Tr);
	bool assigningNormalCargos(Linked_list<Cargo>&NC, LinkedQueue<Truck>& Tr);

	void AssignmentOrder();
	void movingToDelivered();

	static Time getCurrentTime();

};

