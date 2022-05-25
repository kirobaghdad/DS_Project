#pragma once
#include <iostream>
#include"Truck.h"
#include<iostream>
#include"Time.h"
#include"Cargo.h"
#include"LinkedQueue.h"
#include"Linked_list.h"
#include"PriorityQueue.h"




using namespace std;

class UI
{
	char mode;
public:
	UI();
	~UI();
	void printNow(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck*> Tcn, LinkedQueue<Truck*> Tcs, LinkedQueue<Truck*> Tcv, PriorityQueue<Cargo> totalMoving, LinkedQueue<Cargo> totalDeliveredCargo, PriorityQueue<Truck*> assignedTrucks, LinkedQueue<Truck*> In_Checkup_N_Trucks, LinkedQueue<Truck*> In_Checkup_S_Trucks, LinkedQueue<Truck*> In_Checkup_VIP_Trucks);
	void print(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck*>& Tcn, LinkedQueue<Truck*>& Tcs, LinkedQueue<Truck*>& Tcv, PriorityQueue<Cargo>& totalMoving, LinkedQueue<Cargo>& totalDeliveredCargo, PriorityQueue<Truck*>& assignedTrucks, LinkedQueue<Truck*>& In_Checkup_N_Trucks, LinkedQueue<Truck*>& In_Checkup_S_Trucks, LinkedQueue<Truck*>& In_Checkup_VIP_Trucks);
	void printSilentMode(char x);
};

