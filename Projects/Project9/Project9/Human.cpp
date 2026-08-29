#include"Human.h"
Human::Human() : Creature()
{

}
Human::Human(int newStrength, int newHit) : Creature(newStrength,newHit)
{
	
}
int Human::getDamage() const
{
	int dem = Creature::getDamage();
	cout << "Human " << "attacks for " << dem << " points!" << "\n";
	return dem;
}
int Human::getStrength() const
{
	return Creature::getStrength();
}
int Human::getHitpoints() const
{
	return Creature::getHitpoints();
}
void Human::setStrength(const int newStrength)
{
	Creature::setStrength(newStrength);
}
void Human::setHitpoints(const int newHit)
{
	Creature::setHitpoints(newHit);
}