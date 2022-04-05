#pragma once
#include"Time.h"
#include <fstream>
#include "LinkedQueue.h"
#include"Event.h"
#include"Preparation.h"
#include"Promotion.h"
#include"CancelEvent.h"
#include "Time.h"

using std::ifstream;
using std::ofstream;

class UI
{
	ofstream Out;
	ifstream IN;
	int numOfTrucks[3];  //no. of trucks of each type (N, S, V)
	int truckSpeed[3];   //truck speeds of each type (km/h)
	int capacity[3];     //Capacity of each truck type (N, S, V)
	int numOfJourney;    //no. of journeys before checkup
	int checkupDuration[3];    //checkup durations for each type (N, S, V)
	int autoPromotionLimit;    //the number of hours after which a normal cargo is automatically promoted to a VIP cargo
	int maxW;
	int numOfEvents;     
	 

public:
	UI();
	~UI();
	               //============================== Getters ==============================// 
	int getNumOfNT();
	int getNumOfST();
	int getNumOfVT();
	int getNTSpeed();
	int getSTSpeed();
	int getVTSpeed();
	int getNTCapacity();
	int getSTCapacity();
	int getVTCapacity();
	int getNumOfJourney();
	int getNTCheckupDuration();
	int getSTCheckupDuration();
	int getVTCheckupDuration();
	int getAutoPromotionLimit();
	int getMaxW();
	int getNumOfEvents();
	void loadEvents(LinkedQueue<Event*>& E);         //Check if there more events left and read there information if found

	            //============================== Print on Output File ==============================//
	void Print(LinkedQueue<Cargo>& deliveredCargo);
};

