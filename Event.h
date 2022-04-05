#pragma once
#include"Time.h"
#include"Cargo.h"
#include"LinkedQueue.h"
class Event
{
protected:
	Time EventTime;
	int ID;
public:
	Event(Time, int);
	virtual void Execute(LinkedQueue<Cargo>&cn, LinkedQueue<Cargo>& cs, LinkedQueue<Cargo>& cv)=0;
};

