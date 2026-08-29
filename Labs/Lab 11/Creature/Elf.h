#ifndef ELF_H
#define ELF_H
#include "Creature.h"
class Elf : public Creature
{
	Elf();
	Elf(int, int);
	int getDamage() const;
	String getSpecies() const;
};
#endif