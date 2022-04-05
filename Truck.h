#pragma once

class Truck   // abstract class 
{
	int DI;             //    in hours  The time a truck takes to deliver all its cargos and come back to the company
	int NumofJourneys; //     number of journeys done with this truck  
	static int J;
public:

	Truck()
	{
		SetDI(0);
		NumofJourneys = 0;
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
	//============================== Getters ==============================// 
	
	int GetDI() 
	{
		return DI;
	}
	int GetNumofJourneys()
	{
		return NumofJourneys;
	}




};