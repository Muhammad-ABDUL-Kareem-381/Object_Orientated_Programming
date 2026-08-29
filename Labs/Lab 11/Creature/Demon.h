#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"
class Demon : public Creature
{
public:
	Demon();
	Demon(int, int);
	int getDamage() const;
	String getSpecies() const;
};
#endif
