#pragma once
#include "Time.h"

/*
*	Cargo Class
*	This is the Cargo Class. Each Cargo has its unique ID, cost, Load/Unload time, delivery distance, type, and preparation time.
*/

class Cargo
{
private:
	Time preparationTime;	//The Time (day:hour) when the cargo is ready to be assigned to a truck.
	int LU_Time;	//Time (in hours) to load/unload the cargo to/from the truck.
	int deliveryDistance;	//The distance (in kilometers) from the company to the delivery location of the cargo.
	int cost;	 //The cost of delivering the cargo.
	int ID; //The cargo ID
	char cargoType; //The type of the cargo (Normal, Special, or VIP).
	bool isDelivered; 
	int waitingTime; // Waiting Time (WT): The time from the preparation of a cargo until its truck starts to move to deliver it (in minutes).
	bool isWaiting; 
	bool isMoving;
	Time cargoDelivreyTime;

public:
	Cargo(Time, int, int, int, int, char); //Non_Default Constructor for the Cargo Class

	  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 /////////////////////////////////////////// Getter Functions ///////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	char getCargoType() const; // CargoType Getter
	int getCost() const; //cost Getter
	int getdeliveryDistance() const; //deliveryDistance Getter
	int getLU_Time() const; // 
	Time getPT() const;

};
