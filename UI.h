#pragma once
#include <fstream>
#include "Company.h"
#include"Time.h"
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
private:
	static ofstream Out;
	static ifstream IN;
 	 
public:
	UI();
	~UI();
	               //============================== Getters ==============================// 
	static int getNC_Num();
	static int getSC_Num();
	static int getVIPC_Num();

	static int getNT_Num();
	static int getST_Num();
	static int getVIPT_Num();

	static int getNT_Speed();
	static int getST_Speed();
	static int getVIPT_Speed();

	static int getNT_Capacity();
	static int getST_Capacity();
	static int getVIPT_Capacity();

	static int getNumOfJourney();

	static int getNT_Checkup_Duration();
	static int getST_Checkup_Duration();
	static int getVIPT_Checkup_Duration();

	static int getAutoPromotionLimit();
	static int getMaxW();
	static int getNumOfEvents();
	void loadEvents(LinkedQueue<Event*>& E);         //Check if there more events left and read there information if found

	            //============================== Print on Output File ==============================//
	void Print(LinkedQueue<Cargo>& deliveredCargo);
};

