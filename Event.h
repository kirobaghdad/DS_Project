#pragma once
#include"Time.h"
#include"Cargo.h"
#include"LinkedQueue.h"
#include"PriorityQueue.h"
class Event
{
protected:
	Time EventTime;
	int ID;
public:
	Event(Time, int);
	virtual void Execute(LinkedQueue<Cargo>&cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv)=0;
	Time GetTime();

};

