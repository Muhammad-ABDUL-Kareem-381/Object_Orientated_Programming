#ifndef CARGO_SHIP_H
#define CARGO_SHIP_H
#include "Ship.h"
class CargoShip:public Ship
{
	int tons;    //maximum capacity in tons
public:
	CargoShip(const String& name, const String& model, int tons=0);
	int getTons() const;
	void setTons(int);
	void print() const;
};
#endif