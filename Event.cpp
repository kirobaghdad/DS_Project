#include "Event.h"

Event::Event(Time T, int id)
{
	EventTime = T;
	ID = id;
}

Time Event::GetTime()
{
	return EventTime;
}
