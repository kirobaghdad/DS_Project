#include "Event.h"

Event::Event(Time T, int lu, int d, int c, int id)
{
	EventTime = T;
	LU_Time = lu;
	deliveryDistance = d;
	cost = c;	
	ID = id;
}
