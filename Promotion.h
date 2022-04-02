#pragma once
#include "Cargo.h"
#include "Event.h"

class Promotion : public Event
{
	int extraMoney;
public:
	Promotion(char Typ,Time eventTime,int ID,int extra);
	void Execute();
};

