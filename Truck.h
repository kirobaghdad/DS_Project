#pragma once

class Truck
{
	char Type;
	int DI;             //    in hours  The time a truck takes to deliver all its cargos and come back to the company
	int NumofJourneys; //     number of journeys done with this truck  
	int J;
	int TC;      // Truck Capacity
	int Speed;  //  Speed
	int waitingTime;
	static int id;
	int ID;

public:
	Truck() {};
	Truck(char type, int tc, int speed)
	{
		ID = ++id;
		SetDI(0);
		NumofJourneys = 0;
		SetTC(tc);
		SetSpeed(speed);
		waitingTime = 0;

	}
	//============================== Setters ==============================// 

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
};


