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
	void printNow(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck>& Tcn, LinkedQueue<Truck>& Tcs, LinkedQueue<Truck>& Tcv, LinkedQueue<Cargo>& Mcn, LinkedQueue<Cargo>& Mcs, LinkedQueue<Cargo>& Mcv, LinkedQueue<Cargo>& Dcn, LinkedQueue<Cargo>& Dcs, LinkedQueue<Cargo>& Dcv);

	void print(Time t, Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv, LinkedQueue<Truck>& Tcn, LinkedQueue<Truck>& Tcs, LinkedQueue<Truck>& Tcv, LinkedQueue<Cargo>& Mcn, LinkedQueue<Cargo>& Mcs, LinkedQueue<Cargo>& Mcv, LinkedQueue<Cargo>& Dcn, LinkedQueue<Cargo>& Dcs, LinkedQueue<Cargo>& Dcv);
	
};

