#pragma once
#include "Event.h"
class CancelEvent :
    public Event
{
private:

public:
    void Execute(Time, int);
};

