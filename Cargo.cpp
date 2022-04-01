#include "Cargo.h"
#include <cctype>

Cargo::Cargo(Time pt, int LU, int DD, int C, int id, char CT) {
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
	waitingTime = 0;
	isWaiting = true;
	isMoving = false;

	
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