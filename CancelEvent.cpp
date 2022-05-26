#include "CancelEvent.h"
#include"Cargo.h"


CancelEvent::CancelEvent(Time T, int ID)
	:
	Event(T, ID)
{

}

void CancelEvent::Execute(Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv) {
	Cargo temp;
	cn.removeID(ID,temp);
}
