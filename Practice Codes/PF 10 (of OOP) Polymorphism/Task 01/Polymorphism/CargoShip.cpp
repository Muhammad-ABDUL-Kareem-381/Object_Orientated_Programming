#include "CargoShip.h"
CargoShip::CargoShip(const String& name, const String& model, int tons):Ship(name,model), tons(tons)
{}
int CargoShip::getTons() const
{
	return tons;
}
void CargoShip::setTons(int tons)
{
	if (tons > 0)
	{
		this->tons = tons;
	}
}
void CargoShip::print() const
{
	cout << getName()<<'\n'<<tons;
}