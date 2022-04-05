#include "Promotion.h"

Promotion::Promotion(Time eventTime,int ID, int extra):Event( eventTime , ID)
{
	extraMoney = extra;
}

void Promotion::Execute(LinkedQueue<Cargo>& cn, LinkedQueue<Cargo>& cs, LinkedQueue<Cargo>& cv)
{
	Node<Cargo>* ptr = cn.getFrontptr();
	Cargo* temp = nullptr;
	/*while (ptr)
	{
		temp = ptr->getItem();
		if (temp->getID() == ID)
		{
			if (temp->getIsWaiting())
			{
				//temp->setTyp(V);
				//delete the node from nc and put it in vc
			}
		}
	}*/

	//find the cargo in linked list
	//check if it is loaded or not
	//if not change its typ from normal to vip
	//and mov it from normal list to vip list
}
