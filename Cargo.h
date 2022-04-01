#pragma once
#include "Time.h"


class Cargo
{
private:
	Time PT;	//The Time (day:hour) when the cargo is ready to be assigned to a truck.
	int LU_Time;	//Time (in hours) to load/unload the cargo to/from the truck.
	int deliveryDistance;	//The distance (in kilometers) from the company to the delivery location of the cargo.
	int cost;	 //The cost of delivering the cargo.
public:
	Cargo(Time, int, int, int); //Non_Default Constructor for the Cargo Class

	  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 /////////////////////////////////////////// Getter Functions ///////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int getCost() const; //cost Getter
	int getdeliveryDistance() const; //deliveryDistance Getter
	int getLU_Time() const; // 
	Time getPT() const;
};
