#pragma once
#include"Time.h"
#include"Cargo.h"

class Event
{

	Time EventTime;
	//the related cargo info
	int LU_Time;	//Time (in hours) to load/unload the cargo to/from the truck.
	int deliveryDistance;	//The distance (in kilometers) from the company to the delivery location of the cargo.
	int cost;	 //The cost of delivering the cargo.
	char TYP;
public:

	Event(Time,int, int, int);
	virtual void Execute()=0;


};

