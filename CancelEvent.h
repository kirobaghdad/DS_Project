#pragma once
#include "Event.h"
class CancelEvent :
    public Event
{
private:

public:
    void Execute(Time, int, LinkedQueue<Cargo>& cn, LinkedQueue<Cargo>& cs, LinkedQueue<Cargo>& cv);
};

