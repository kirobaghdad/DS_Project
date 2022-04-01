#include "Event.h"

Event::Event(Time T, int lu, int d, int c)
{
	EventTime = T;
	LU_Time = lu;
	deliveryDistance = d;
	cost = c;
	TYP = typ;
}
