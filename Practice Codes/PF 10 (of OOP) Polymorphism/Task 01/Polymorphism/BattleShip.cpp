#include"BattleShip.h"
BattleShip::BattleShip(const String& name, const String& model,int missiles): Ship(name,model), missiles(missiles)
{}
int BattleShip::getMissiles() const
{
	return missiles;
}
void BattleShip::setMissiles(int missiles)
{
	if (missiles > 0)
	{
		this->missiles = missiles;
	}
}
void BattleShip::print() const
{
	cout << getName()<<'\n'<<missiles;
}