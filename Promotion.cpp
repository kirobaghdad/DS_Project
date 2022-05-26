#include "Promotion.h"

Promotion::Promotion(Time eventTime, int ID, int extra) :Event(eventTime, ID)
{
	extraMoney = extra;
}

void Promotion::Execute(Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv)
{
	Cargo Item;
	cn.removeID(Item.getID(), Item);								 //move it from normal list to vip list
	Item.setCargoTyp('V');											 //changing its typ from normal to vip
	Item.setCost(Item.getCost() + extraMoney);
	cv.enqueue(Item, Item.getCost() + Item.getDeliveryDistance());
}
