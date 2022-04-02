#include<iostream>
#include "Preparation.h"
#include "Cargo.h"
using namespace std;
Preparation::Preparation(Time T, int lu, int d, int c,int id,char Type):Event(T,id,c)
{
	TYP = Type;
	LU_Time = lu;
	deliveryDistance = d;
}

void Preparation::Execute()
{
	//should create a new cargo and add it to the appropriate list
	Cargo* prt = NULL;
	switch (TYP)
	{
	case 'N':
		 prt = new Cargo(EventTime, LU_Time, deliveryDistance, cost,ID,'N');
		//add it to the appropriate list
		break;
	case 'S':
		 prt = new Cargo(EventTime, LU_Time, deliveryDistance, cost, ID, 'S');
		//add it to the appropriate list
		break;
	case 'V':
		 prt = new Cargo(EventTime, LU_Time, deliveryDistance, cost, ID, 'V');
		//add it to the appropriate list
		break;

	default:
		cout << "Invalid Type Of Cargo" << endl;
		break;
	}
}
