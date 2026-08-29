#include"Creature.h"
Creature::Creature() //: strength(10), 
{}
Creature::Creature( int newStrength, int newHit) : strength(newStrength), hitpoints(newHit)
{
}
int Creature::getDamage() const
{
	int damage = (rand() % strength) + 1;
	//((const String)getSpecies()).display;
	cout << " attacks for "<< damage<<" points!" << '\n';
	return damage;
}
void Creature::setStrength(const int st)
{
	strength = st;
}
void Creature::setHitpoints(const int hp)
{
	hitpoints = hp;
}
int Creature::getHitpoints() const
{
	return hitpoints;
}
int Creature::getStrength() const
{
	return strength;
}