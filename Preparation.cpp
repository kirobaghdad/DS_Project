#include<iostream>
#include "Preparation.h"
#include "Cargo.h"

using namespace std;

Preparation::Preparation(Time T, int lu, int d, int c, int id, char Type) :Event(T, id)
{
	TYP = Type;
	LU_Time = lu;
	deliveryDistance = d;
	if (c > 0)
		cost = c;
	else cost = 1;
}

void Preparation::Execute(Linked_list<Cargo>& cn, LinkedQueue<Cargo>& cs, PriorityQueue<Cargo>& cv)
{
	//should create a new cargo and add it to the appropriate list
	Cargo* ptr = NULL;
	switch (TYP)
	{
	case 'N':
		ptr = new Cargo(EventTime, LU_Time, deliveryDistance, cost, ID, 'N');
		cn.add(*ptr);
		break;
	case 'S':
		ptr = new Cargo(EventTime, LU_Time, deliveryDistance, cost, ID, 'S');
		cs.enqueue(*ptr);
		break;
	case 'V':
		ptr = new Cargo(EventTime, LU_Time, deliveryDistance, cost, ID, 'V');
		cv.enqueue(*ptr, deliveryDistance * cost);
		break;

	default:
		cout << "Invalid Type Of Cargo" << endl;
		break;
	}
}
