#include "Promotion.h"

Promotion::Promotion(Time eventTime, int ID, int extra) :Event(eventTime, ID)
{
	extraMoney = extra;
}

void Promotion::Execute(LinkedQueue<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv)
{
	bool promoted = false;
	Node<Cargo>* ptr = cn.getFrontptr();
	Cargo Item;
	while (ptr && !promoted)     //find the cargo in Cargo list
	{
		Item = ptr->getItem();
		if (Item.getID() == ID)
		{
			if (Item.getIsWaiting())     //check if it is loaded or not
			{
				char typ = 'v';
				Item.setCargoTyp(typ);   //changing its typ from normal to vip
				cn.remove(Item.getID());         //move it from normal list to vip list
				cv.enqueue(Item, Item.getCost() * Item.getdeliveryDistance());
				promoted = true;
			}
		}
		ptr = ptr->getNext();
	}
}
