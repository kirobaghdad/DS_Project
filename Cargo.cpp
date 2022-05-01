#include "Cargo.h"
#include <cctype>

Cargo::Cargo(Time pt, int LU, int DD, int C, int id, char CT){

	numberofcargos++;

	preparationTime = pt;

	if (LU > 0)
		LU_Time = LU;
	else
		LU_Time = 1;

	if (id > 0)
		ID = id;
	else
		ID = 1;

	if (DD > 0)
		deliveryDistance = DD;
	else deliveryDistance = 1;

	if (CT != 'N' && CT != 'S' && CT != 'V')
		cargoType = 'N';
	else
		cargoType = CT;

	if (C > 0)
		cost = C;
	else cost = 1;

	isDelivered = false;
	isWaiting = true;
	isMoving = false;

	
}

Cargo::Cargo()
{
}

int Cargo::getCost()const {
	return cost;
}

int Cargo::getdeliveryDistance()const {
	return deliveryDistance;
}

int Cargo::getLU_Time()const {
	return LU_Time;
}

char Cargo::getCargoType() const {
	return cargoType;
}

Time Cargo::getPT() const {
	return preparationTime;
}

int Cargo::getID() const
{
	return ID;
}

bool Cargo::getIsWaiting() const
{
	return isWaiting;
}

void Cargo::setCargoTyp(char typ)
{
	cargoType = typ;
}

Time Cargo::getCargoDelivreyTime() const
{
	return cargoDelivreyTime;
}

Time Cargo::getWaitingTime() const
{
	return waitingTime;
}

void Cargo::increaseWaitingTime() {
	waitingTime.increase();
}

bool Cargo::operator==(int x)
{
	if (this->ID == x)
		return true;
	return false;
}

void Cargo::setCargoDelivreyTime(Time T)
{
	cargoDelivreyTime = T;
}

void Cargo::setCost(int c)
{
	cost = c;
}
int Cargo::GetNumber()
{
	return numberofcargos;
}

std::ostream& operator<<(std::ostream& os, const Cargo& c)
{
	os << c.getID();
	return os;
}
