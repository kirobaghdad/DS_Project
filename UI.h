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

	static int readNT_Num();
	static int readST_Num();
	static int readVIPT_Num();

	static int readNT_Speed();
	static int readST_Speed();
	static int readVIPT_Speed();

	static int readNT_Capacity();
	static int readST_Capacity();
	static int readVIPT_Capacity();

	static int readNumOfJourney();

	static int readNT_Checkup_Duration();
	static int readST_Checkup_Duration();
	static int readVIPT_Checkup_Duration();

	static int readAutoPromotionLimit();
	static int readMaxW();
	static int readNumOfEvents();
	void loadEvents(LinkedQueue<Event*>& E);         //Check if there more events left and read there information if found

	            //============================== Print on Output File ==============================//
	void Print(LinkedQueue<Cargo>& deliveredCargo);
};

