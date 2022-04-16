#include "CancelEvent.h"
#include"Cargo.h"



CancelEvent::CancelEvent(Time T, int ID)
	:
	Event(T, ID)
{

}

void CancelEvent::Execute(LinkedQueue<Cargo>& cn) {
	if (cn.isEmpty())
		return;

	Node<Cargo>* ptr = cn.getFrontptr();
	if (ptr->getItem().getID() == ID)
	{
		cn.setFrontPtr(cn.getFrontptr()->getNext());

		if (ptr == cn.getBackPtr())
			cn.setBackPtr(nullptr);
		return;
	}
	ptr = ptr->getNext();
	Node<Cargo>* prev = cn.getFrontptr();
	while (ptr)
	{
		if (ptr->getItem().getID() == ID)
		{
			prev->setNext(ptr->getNext());
			delete ptr;
			return;
		}
		ptr = ptr->getNext();
		prev = prev->getNext();
	}
	return;
}
