#include"Cyberdemon.h"
Cyberdemon::Cyberdemon(): Demon(0,0)
{}
Cyberdemon::Cyberdemon(int st, int hp) : Demon (st, hp)
{}
int Cyberdemon::getDamage() const
{
	return Demon::getDamage();
}
String Cyberdemon::getSpecies() const
{
	return "Cyberdemon";
}