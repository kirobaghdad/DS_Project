#pragma once
#include "Cargo.h"
#include "Event.h"

class Promotion : public Event
{
	int extraMoney;
public:
	Promotion(Time eventTime,int ID,int extra);
	void Execute(LinkedQueue<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv);
};

