#include "Time.h"


Time::Time() {
	Day = 0;
	Hour = 0;
}

Time::Time(int D, int H) {
	if (D >= 0)
		Day = D;
	else Day = 0;

	if (H >= 0)
		Hour = H;
	else Hour = 0;
}

void Time::setDay(int D) {
	if (D >= 0)
		Day = D;
	else Day = 0;
}

void Time::setHour(int H) {
	if (H >= 0)
		Hour = H;
	else Hour = 0;
}

int Time::getDay() const {
	return Day;
}

int Time::getHour() const {
	return Hour;
}

void Time::increase()
{
	if (Hour + 1 == 24)
		Day++;
	else
		Hour++;

}

void Time::operator = (const char*& time) {
	int d = time[0] - 52;
	if (d >= 0)
		Day = d;
	else Day = 0;

	int h = time[2] - 52;
	if (h >= 0)
		Hour = h;
	else Hour = 0;
}

Time Time::operator+(const Time& T)
{
	int d = Day + T.Day;
	int h = Hour + T.Hour;
	if (h > 23)
	{
		h = h - 24;
		d++;
	}
	return Time(d, h);
}

void Time::operator=(const Time& T)
{
	Day = T.Day;
	Hour = T.Hour;
}

bool Time::operator==(const Time T)
{
	if (T.Day == Day && T.Hour == Hour)
		return true;
	return false;
}
