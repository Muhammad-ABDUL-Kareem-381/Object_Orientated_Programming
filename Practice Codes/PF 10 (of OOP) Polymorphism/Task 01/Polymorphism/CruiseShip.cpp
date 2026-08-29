#include "CruiseShip.h"
CruiseShip::CruiseShip(const String& n, const String& m, const int s):Ship(n,m),seats(s)
{}
int CruiseShip::getSeats() const
{
	return seats;
}
void CruiseShip::setSeat(int seats)
{
	if (seats > 0)
	{
		this->seats = seats;
	}
}
void CruiseShip::print() const
{
	Ship::print();
	cout << '\n' << seats;
}
