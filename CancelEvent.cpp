#include "CancelEvent.h"
#include"Cargo.h"


CancelEvent::CancelEvent(Time T, int ID)
	:
	Event(T, ID)
{

}

void CancelEvent::Execute(Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv) {
	
	/*if (cn.isEmpty())
		return;

	Node<Cargo>* ptr = cn.getHead();
	if (ptr->getItem().getID() == ID)
	{
		cn.setHead((cn.getHead())->getNext());

		if (ptr->getNext() == NULL)
			cn.set(nullptr);
		return;
	}
	ptr = ptr->getNext();
	Node<Cargo>* prev = cn.getHead();
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
	return;*/

	cn.removeID(ID);
}
