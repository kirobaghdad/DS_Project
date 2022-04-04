#pragma once
#include"Time.h"
#include"Cargo.h"

class Event
{
protected:
	Time EventTime;
	int ID;
public:
	Event(Time, int);
	virtual void Execute()=0;
};

