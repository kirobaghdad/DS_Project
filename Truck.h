#pragma once

class Truck   // absruct class 
{    
	int Maintenancetime;  //  in hours 
	int DI;             //    in hours  The time a truck takes to deliver all its cargos. and com back to the company
	int NumofJourneys; //     number of Journeys done with this truck  

public :

	Truck(int mt)
	{
        SetMaintenancetime(mt);
		SetDI(0);
		NumofJourneys = 0;
	}
	//============================== Seters ==============================// 
	
	bool  SetMaintenancetime(int mt)
	{
		if (mt < 0)
			return false;
		Maintenancetime = mt;
		return true;
	}
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
	
	//============================== Geters ==============================// 
	
	int GetMaintenancetime()
	{
		return Maintenancetime;
	}
	int GetDI() 
	{
		return DI;
	}
	int GetNumofJourneys()
	{
		return NumofJourneys;
	}



};