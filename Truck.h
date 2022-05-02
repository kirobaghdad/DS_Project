#pragma once
#include "Truck.h"
#include "Cargo.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"

class Truck
{
	char Type;
	int DI;             //    (In Hours) The time a truck takes to deliver all its cargos and come back to the company
	int NumofJourneys; //     number of journeys done with this truck  
	int J;
	int TC;      // Truck Capacity
	int Speed;  //  Speed
	int waitingTime;
	static int id;
	int ID;

	Time movingTime;

	PriorityQueue<Cargo> assignedCargos;
	bool isAssigned;

public:
	Truck() {
	};
	Truck(char type, int tc, int speed)
	{
		ID = ++id;
		SetDI(0);
		NumofJourneys = 0;
		SetTC(tc);
		SetSpeed(speed);
		waitingTime = 0;
		isAssigned = false;
	}
	//============================== Setters ==============================// 

	
	void setMovingTime(Time t) {
		movingTime = t;
	}

	void setIsAssigned(bool assign) {
		isAssigned = assign;
	}

	int getWaitingTime()const {
		return waitingTime;
	}
	
	bool assignCargo(Cargo& newCargo, float t) {

		return assignedCargos.enqueue(newCargo, t);
	}

	//void increaseWaitingTime() {
	//	waitingTime++;
	//}
	bool SetDI(int di)
	{
		if (di < 0)
			return false;
		DI = di;
		return true;
	}
	void increaseJourneys()
	{
		NumofJourneys++;
	}

	void SetJ(int j)
	{
		J = j;
	}
	bool SetTC(int tc)
	{
		if (tc < 0)
			return false;
		TC = tc;
		return true;
	}
	bool SetSpeed(int sp)
	{
		if (sp < 0)
			return false;
		Speed = sp;
		return true;
	}
	//============================== Getters ==============================// 



	PriorityQueue<Cargo>& getCargosQueue() {
		return assignedCargos;
	}
	int GetDI() const
	{
		return DI;
	}
	int GetID() const
	{
		return ID;
	}
	int GetNumofJourneys()
	{
		return NumofJourneys;
	}
	int GetTC()  const
	{
		return TC;
	}
	int GetSpeed() const
	{
		return Speed;
	}


	friend std::ostream& operator<<(std::ostream& os, const Truck& T) {
		os << T.GetID();
		return os;
	}

	bool LoadingRule(int num)
	{
		if (num >= TC)
			return true;
		return false;
	}












};


