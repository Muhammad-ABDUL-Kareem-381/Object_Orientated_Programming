#ifndef CRUISE_SHIP_H
#define CRUISE_SHIP_H
#include "Ship.h"
class CruiseShip : public Ship
{
	int seats;
public:
	CruiseShip(const String & n, const String & m, const int s);
	int getSeats() const;
	void setSeat(int);
	void print() const;
};

#endif 
