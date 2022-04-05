#include "UI.h"


UI::UI(LinkedQueue<Event*> & E)
{
	IN.open("Input.txt");  //Open Input File
	Out.open("Output.txt");  //Open Output File
	         //============================== Reading Inputs ==============================//
	IN >> numOfTrucks[0];
	IN >> numOfTrucks[1];
	IN >> numOfTrucks[2];
	IN >> truckSpeed[0];
	IN >> truckSpeed[1];
	IN >> truckSpeed[2];
	IN >> capacity[0];
	IN >> capacity[1];
	IN >> capacity[2];
	IN >> numOfJourney;
	IN >> checkupDuration[0];
	IN >> checkupDuration[1];
	IN >> checkupDuration[2];
	IN >> autoPromotionLimit;
	IN >> maxW;
	IN >> numOfEvents;
	currentNumOfEvents = 0;
	
	Event* ptr = NULL;
	Time t;
	int lu,c,id,d,h,day;
	char typ;

	for (int i = 0; i < numOfEvents; i++)
	{
		IN >> x;
		switch (x)
		{
		case 'R':
			IN >> typ;	IN >> day; IN >> h;	IN >> id; IN >> d; IN >> lu; IN >> c;
			t.setDay(day); t.setHour(h);
			ptr = new Preparation(t, lu, d, c, id, typ);
			E.enqueue(ptr);
		case 'X':


		case'P':


		default:
			break;
		}





	}
}

UI::~UI()
{
	IN.close();
}

                //============================== Getters ==============================// 

int UI::getNumOfNT()
{
	return numOfTrucks[0];
}

int UI::getNumOfST()
{
	return numOfTrucks[1];
}

int UI::getNumOfVT()
{
	return numOfTrucks[2];
}

int UI::getNTSpeed()
{
	return truckSpeed[0];
}

int UI::getSTSpeed()
{
	return truckSpeed[1];
}

int UI::getVTSpeed()
{
	return truckSpeed[2];
}

int UI::getNTCapacity()
{
	return capacity[0];
}

int UI::getSTCapacity()
{
	return capacity[1];
}

int UI::getVTCapacity()
{
	return capacity[2];
}

int UI::getNumOfJourney()
{
	return numOfJourney;
}

int UI::getNTCheckupDuration()
{
	return checkupDuration[0];
}

int UI::getSTCheckupDuration()
{
	return checkupDuration[1];
}

int UI::getVTCheckupDuration()
{
	return checkupDuration[2];
}

int UI::getAutoPromotionLimit()
{
	return autoPromotionLimit;
}

int UI::getMaxW()
{
	return maxW;
}

int UI::getNumOfEvents()
{
	return numOfEvents;
}

bool UI::checkForEvent()
{
	if (currentNumOfEvents<=numOfEvents)
	{
		int day, hours;
		IN >> eventTyp;
		switch (eventTyp)
		{
		case 'R':
			IN >> cargoTyp;
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			IN >> DIST;
			IN >> LU_Time;
			IN >> cost;
			break;
		case 'X':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			break;
		case 'P':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			IN >> extraMoney;
			break;
		default:
			break;
		}
		return true;
	}
	else
	{
		return false;
	}
}

char UI::getEventTyp()
{
	return eventTyp;
}

char UI::getcargoTyp()
{
	return cargoTyp;
}

Time UI::geteventTime()
{
	return eventTime;
}

int UI::getID()
{
	return ID;
}

int UI::getDIST()
{
	return DIST;
}

int UI::getLU_Time()
{
	return LU_Time;
}

int UI::getcost()
{
	return cost;
}

int UI::getextraMoney()
{
	return extraMoney;
}

          //============================== Print on Output File ==============================//

void UI::Print()
{
	Out << "CDT CID PT WT TID \n";

	//get the number of delivered cargo from cargo list
	//write info for each cargo  in ascending order by CDT 
	
	Out << ".............................. \n";
	Out << ".............................. \n";

	//get number of each typ of cargo from cagos list and print it
	//get number of each typ of trucks from trucks list then print it
}

