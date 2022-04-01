#pragma once
#include"Time.h"
#include <fstream>
using std::ifstream;

#include <iostream>
using namespace std;

class UI
{
	ifstream IN;
	int numOfTrucks[3];
	int truckSpeed[3];
	int capacity[3];
	int numOfJourney;
	int checkupDuration[3];
	int autoPromotionLimit;
	int maxW;
	int numOfEvents;
	int currentNumOfEvents;
	char eventTyp;
	char cargoTyp;
	Time eventTime;
	int ID;
	int DIST;
	int loadTime;
	int cost;
	int extraMoney;


public:
	UI();
	~UI();
	int getNumOfNT();
	int getNumOfST();
	int getNumOfVT();
	int getNTSpeed();
	int getSTSpeed();
	int getVTSpeed();
	int getNTCapacity();
	int getSTCapacity();
	int getVTCapacity();
	int getautoPromotionLimit();
	int getmaxW();
	int getNumOfEvents();
	void checkForEvent();
	char getEventTyp();
	char getcargoTyp();
	Time geteventTime();
	int getID();
	int getDIST();
	int getloadTime();
	int getcost();
	int getextraMoney();
};

