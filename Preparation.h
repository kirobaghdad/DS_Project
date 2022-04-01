#pragma once

#include "Event.h"


class Preparation : public Event
{
	//data related to its operation
	char TYP;


public:
	Preparation(Time T, int lu, int d, int c, char Type);
	virtual void Execute();




};

