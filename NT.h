#pragma once
#include"Truck.h"


class NT : public Truck
{
	static int TC;      // Truck Capacity
	static int Speed;  //  Speed

public:
	//============================== constructor ==============================//
	NT(int mt) : Truck(mt)
	{}
	//============================== Seters ==============================//
	bool SetTC(int tc)
	{
		if (tc < 0)
			return false;
		TC = tc;
		return true;
	}
	bool SetSpeed(int sp)
	{
		if (sp < 0)
			return false;
		Speed = sp;
		return true;
	}
	//============================== Geters ==============================// 
	int GetTC()  const
	{
		return TC;
	}
	int GetSpeed() const
	{
		return Speed;
	}








};