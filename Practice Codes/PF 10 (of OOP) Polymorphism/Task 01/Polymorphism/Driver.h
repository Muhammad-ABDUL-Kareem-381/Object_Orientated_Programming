#ifndef DRIVER_H
#define DRIVER_H
#include "CruiseShip.h"
#include "BattleShip.h"
#include "CargoShip.h"
class Driver
{
	//~Driver();
	static Ship** createArray();
	static void freeMemory(Ship**& p);
public:
	static void driveApp();
};
#endif