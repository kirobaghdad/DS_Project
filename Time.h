#pragma once
class Time
{
private:
	int Day;
	int Hour;
public:
	Time();
	Time(int, int);

	void operator = (const char*&);
	Time operator + (const Time& T);
	void operator=(const Time& T);
	bool operator==(const Time& T);
	Time operator - (const Time& T);

	void setDay(int D);
	void setHour(int H);
	int getDay() const;
	int getHour() const;
	void increase();

	bool isValid();

};
