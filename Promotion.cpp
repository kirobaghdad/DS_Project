#include "Promotion.h"

Promotion::Promotion(Time eventTime,int c,int ID, int extra):Event( eventTime ,c , ID)
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
