#pragma once
#include"Time.h"
#include <fstream>
using std::ifstream;

#include <iostream>
using namespace std;

class UI
{
	ifstream IN;
	int numOfTrucks[3];  //no. of trucks of each type (N, S, V)
	int truckSpeed[3];   //truck speeds of each type (km/h)
	int capacity[3];     //Capacity of each truck type (N, S, V)
	int numOfJourney;    //no. of journeys before checkup
	int checkupDuration[3];    //checkup durations for each type (N, S, V)
	int autoPromotionLimit;    //the number of hours after which a normal cargo is automatically promoted to a VIP cargo
	int maxW;
	int numOfEvents;     
	int currentNumOfEvents;
	char eventTyp;
	char cargoTyp;
	Time eventTime;
	int ID;      //is a unique sequence number that identifies each cargo
	int DIST;    //is the cargo distance
	int loadTime;
	int cost;
	int extraMoney;   //Extra money for promotion


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
	bool checkForEvent();
	char getEventTyp();
	char getcargoTyp();
	Time geteventTime();
	int getID();
	int getDIST();
	int getloadTime();
	int getcost();
	int getextraMoney();
};

