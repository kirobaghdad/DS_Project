#pragma once
#include "Cargo.h"
#include "Event.h"
#include "Company.h"

class Promotion : public Event
{
	int extraMoney;
public:
	Promotion(Time eventTime,int ID,int extra);
	void Execute(Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv);
};

