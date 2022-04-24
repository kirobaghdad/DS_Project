#pragma once

#include "Event.h"
#include"Company.h"

class Preparation : public Event
{
	//data related to its operation
	char TYP;
	int deliveryDistance;
	int LU_Time;	//Time (in hours) to load/unload the cargo to/from the truck.
	int cost;

public:
	Preparation(Time T, int lu, int d, int c, int id,char Type);
	virtual void Execute(Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv);

};

