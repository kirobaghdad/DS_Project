#include "Promotion.h"

Promotion::Promotion(char Typ, Time eventTime, int ID, int extra):Event(eventTime,ID,Typ)
{
	extraMoney = extra;
}

void Promotion::Execute()
{
	//find the cargo in linked list
	//check if it is loaded or not
	//if it is not loaded chang the typ of it from normal to vip
	//and mov it from normal list to vip list
}
