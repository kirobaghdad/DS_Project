#pragma once
class Time
{
private:
	int Day;
	int Hour;
public:
	Time();
	Time(int, int);
	void setDay(int D);
	void setHour(int H);
	int getDay() const;
	int getHour() const;
};
