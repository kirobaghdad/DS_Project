#pragma once
#include "Truck.h"
#include "Cargo.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"



class Truck
{
	char Type;
	int AT;             //    (In Hours) The time a truck takes to deliver all its cargos and come back to the company
	int NumofJourneys; //     number of journeys done with this truck  
	static int J;
	int checkUpDuration;
	int TC;      // Truck Capacity
	int Speed;  //  Speed
	int waitingTime;
	static int id;
	int ID;
	int TDC;      //total delivered cargos
	Time movingTime;
	Time returnTime;
	Time endCheckUpTime;
	PriorityQueue<Cargo> assignedCargos;
	bool isAssigned;

public:
	Truck() {
	};
	Truck(char type, int tc, int speed, int checkUpDuration)
	{
		this->checkUpDuration = checkUpDuration;
		ID = ++id;
		AT = 0;
		TDC = 0;
		NumofJourneys = 0;
		SetTC(tc);
		SetSpeed(speed);
		waitingTime = 0;
		isAssigned = false;
		Type = type;
	}


	void increaseTDC()
	{
		TDC++;
	}
	int getTDC()
	{
		return TDC;
	}
	void setEndCheckUpTime(Time t) {
		endCheckUpTime = t;
	}
	void setMovingTime(Time t) {
		movingTime = t;
	}
	Time getMovingTime() {
		return movingTime;
	}

	void setreturnTime(Time t) 
	{
		returnTime = t;
	}

	Time getreturnTime() {
		return movingTime;
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

	bool goToCheckUp() {
		if (NumofJourneys % J == 0 && NumofJourneys != 0)
			return true;
		else return false;
	}

	bool SetAT(int at)
	{
		AT += at;
		return true;
	}
	void increaseJourneys()
	{
		NumofJourneys++;
	}
	static void SetJ(int j)
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

	int getCheckUpDuration()
	{
		return checkUpDuration;
	}



	PriorityQueue<Cargo>& getCargosQueue() {
		return assignedCargos;
	}
	int GetAT() const
	{
		return AT;
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

	bool isCheckedUp(Time currentTime) {
		return (currentTime >= endCheckUpTime);
	}

	char getType()
	{
		return Type;
	}
};


