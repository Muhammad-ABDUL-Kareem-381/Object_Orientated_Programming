#include"Creature.h"
Creature::Creature() : strength(10),hitpoints(10)
{

}
Creature::Creature( int newStrength, int newHit) : Creature()
{
	strength = newStrength;
	hitpoints = newHit;
}
int Creature::getDamage() const
{
	int damage;
	damage = (rand() % strength) + 1;
	return damage;
}
int Creature::getStrength() const
{
	return strength;
}
int Creature::getHitpoints() const
{
	return hitpoints;
}
void Creature::setStrength(const int newStrength)
{
	strength = newStrength;
}
void Creature::setHitpoints(const int newHit)
{
	hitpoints = newHit;
}