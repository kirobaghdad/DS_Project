#pragma once
#include "Event.h"
#include "Time.h"
class CancelEvent :
    public Event
{
public:
    CancelEvent(Time, int); //Constructor

    virtual void Execute(LinkedQueue<Cargo>&);
};

