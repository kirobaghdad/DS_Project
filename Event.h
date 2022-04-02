#pragma once
#include"Time.h"
#include"Cargo.h"

class Event
{
protected:
	Time EventTime;
	//the related cargo info
	int cost;	 //The cost of delivering the cargo.
	int ID;
public:
	Event(Time,int, int);
	virtual void Execute()=0;
};

