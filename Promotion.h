#pragma once
#include "Cargo.h"
#include "Event.h"

class Promotion : public Event
{
	int extraMoney;
public:
	Promotion(Time eventTime,int c,int ID,int extra);
	void Execute();
};

