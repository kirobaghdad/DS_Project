#include "UI.h"


UI::UI()
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

void UI::loadEvents(LinkedQueue <Event*>& E)
{
	Event* ptr = nullptr;
	int day, hours;
	for (int i = 0; i < numOfEvents; i++)
	{
		char eventTyp;
		char cargoTyp;
		Time eventTime;
		int ID;
		int DIST;
		int LU_Time;
		int cost;
		int extraMoney;
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
			ptr = new Preparation(eventTime,LU_Time,DIST,cost,ID,cargoTyp);
			E.enqueue(ptr);
			break;
		case 'X':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			//ptr=new CancelEvent();
			E.enqueue(ptr);
			break;
		case 'P':
			IN >> day;
			IN.ignore();
			IN >> hours;
			eventTime.setDay(day);
			eventTime.setHour(hours);
			IN >> ID;
			IN >> extraMoney;
			ptr = new Promotion(eventTime, ID, extraMoney);
			E.enqueue(ptr);
			break;
		default:
			break;
		}
	}
}

          //============================== Print on Output File ==============================//

void UI::Print(LinkedQueue<Cargo>& DC)
{
	Out << "CDT CID PT WT TID \n";
	Cargo temp;
	Time T;
	while (DC.dequeue(temp))
	{
		//T=temp.getcargoDelivreyTime();
		Out << T.getDay() << ":" << T.getHour() << " ";
		Out << temp.getID()<<" ";
		T = temp.getPT();
		Out << T.getDay() << ":" << T.getHour() << " ";
		//T=temp.getWT();
		Out << T.getDay() << ":" << T.getHour() << " ";
		// the id of truck that delivered the cargo
	}
	Out << "……………………………………………… \n";
	Out << "……………………………………………… \n";
	//get number of each typ of cargo from cagos list and print it
	




	//get number of each typ of trucks from trucks list then print it
}

