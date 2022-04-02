#include "UI.h"

UI::UI()
{
	IN.open("Input.text");  //Open Input File
	if (IN.fail())
	{
		cout << "the filedid not open" << endl;
	}
	else {
		cout << "the file open" << endl;
	}
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
}

UI::~UI()
{
	IN.close();
	if (IN.fail())
	{
		cout << "did not close";
	}
	else {
		cout << "success";
	}
}

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
			IN >> loadTime;
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

int UI::getloadTime()
{
	return loadTime;
}

int UI::getcost()
{
	return cost;
}

int UI::getextraMoney()
{
	return extraMoney;
}

