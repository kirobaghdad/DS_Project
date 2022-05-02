#include "Promotion.h"

Promotion::Promotion(Time eventTime, int ID, int extra) :Event(eventTime, ID)
{
	extraMoney = extra;
}

void Promotion::Execute(Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv)
{
	bool promoted = false;
	Node<Cargo>* ptr = cn.getHead();
	Cargo Item;
	while (ptr && !promoted)     //find the cargo in Cargo list
	{
		Item = ptr->getItem();
		if (Item.getID() == ID)
		{
			if (Item.getIsWaiting())     //check if it is loaded or not
			{
				char typ = 'V';
				Item.setCargoTyp(typ);   //changing its typ from normal to vip
				cn.removeID(Item.getID());         //move it from normal list to vip list
				Item.setCost(Item.getCost() + extraMoney);
				cv.enqueue(Item, Item.getCost() * Item.getDeliveryDistance());
				promoted = true;
				Company::increasePC_Num();
			}
		}
		ptr = ptr->getNext();
	}
}
