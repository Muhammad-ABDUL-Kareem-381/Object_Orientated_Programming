#ifndef CREATURE_H
#define CREATURE_H
#include"String.h"
#include<iostream>
using namespace std;
class Creature
{
	int strength;
	int hitpoints;
public:
	Creature();
	Creature(int newStrength, int newHit);
	int getDamage() const;
	int getStrength() const;
	int getHitpoints() const;
	void setStrength(const int newStrength);
	void setHitpoints(const int newHit);
};
#endif 