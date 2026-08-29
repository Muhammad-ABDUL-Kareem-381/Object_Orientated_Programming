#ifndef DEMON_H
#define DEMON_H
#include<iostream>
#include"Creature.h"
class Demon : public Creature
{
public:
	Demon();
	Demon(int newStrength, int newHit);
	int getDamage() const;
	int getStrength() const;
	int getHitpoints() const;
	void setStrength(const int newStrength);
	void setHitpoints(const int newHit);
};
#endif // !DEMON_H
