#include "Elf.h"
Elf::Elf(): Creature(0,0)
{}
Elf::Elf(int st, int hp) : Creature(st, hp)
{}
int Elf::getDamage() const
{
	return 2 * Creature::getDamage();
}
String Elf::getSpecies() const
{
	return "Elf";
}