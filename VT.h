#pragma once
#include"Truck.h"
class VT: public Truck
{
	static int TC;      // Truck Capacity
	static int Speed;  //  Speed

public:
	//============================== constructor ==============================//
	VT() 
	{}
	//============================== Setters ==============================//
	static bool SetTC(int tc)
	{
		if (tc < 0)
			return false;
		TC = tc;
		return true;
	}
    static bool SetSpeed(int sp) 
	{
		if (sp < 0)
			return false;
		Speed = sp;
		return true;
	}
	//============================== Getters ==============================// 
	int GetTC()  const
	{
		return TC;
	}
	int GetSpeed() const
	{
		return Speed;
	}

};