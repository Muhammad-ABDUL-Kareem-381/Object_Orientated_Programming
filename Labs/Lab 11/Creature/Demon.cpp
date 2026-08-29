#include "Demon.h"
Demon::Demon() : Creature(0,0)
{}
Demon::Demon(int st, int hp) : Creature(st, hp)
{}
int Demon::getDamage() const
{
	return 1.5 * Creature::getDamage();
}
String Demon::getSpecies() const
{
	return "Demon";
}