#include "Human.h"
Human::Human(): Creature(10,10)
{
}
Human::Human(int st, int hp): Creature(st,hp)
{}
int Human::getDamage() const
{
	return Creature::getDamage();
}
String Human::getSpecies() const
{
	return "Human";
}