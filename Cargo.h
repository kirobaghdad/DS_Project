#pragma once
#include "Time.h"
#include<iostream>
/*
*	Cargo Class
*	This is the Cargo Class. Each Cargo has its unique ID, cost, Load/Unload time, delivery distance, type, and preparation time.
*/





class Cargo
{
private:

	static int numberofcargos;

	Time preparationTime;	//The Time (day:hour) when the cargo is ready to be assigned to a truck.
	int LU_Time;	//Time (in hours) to load/unload the cargo to/from the truck.
	int deliveryDistance;	//The distance (in kilometers) from the company to the delivery location of the cargo.
	int cost;	 //The cost of delivering the cargo.
	int ID; //The cargo ID
	char cargoType; //The type of the cargo (Normal, Special, or VIP).
	bool isDelivered; 
	Time waitingTime; // Waiting Time (WT): The time from the preparation of a cargo until its truck starts to move to deliver it.
	bool isWaiting; 
	bool isMoving;
	Time cargoDelivreyTime;
	int Priority;
public:
	Cargo(Time, int, int, int, int, char); //Non_Default Constructor for the Cargo Class
	Cargo(); // default Constructor we need it in DS 
	  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 /////////////////////////////////////////// Getter Functions ///////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	char getCargoType() const; // CargoType Getter
	int getCost() const; //cost Getter
	int getdeliveryDistance() const; //deliveryDistance Getter
	int getLU_Time() const; // 
	Time getPT() const;
	int getID() const;
	bool getIsWaiting()const;
	void setCargoTyp(char typ);
	Time getCargoDelivreyTime()const;
	Time getWaitingTime()const;
	bool operator==(int x);
	void setCargoDelivreyTime(Time T);
	static int GetNumber();

	friend std::ostream& operator<<(std::ostream& os, const Cargo& c);
};


 
