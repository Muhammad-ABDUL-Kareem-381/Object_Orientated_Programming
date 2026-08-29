#ifndef HUMAN_H
#define HUMAN_H
#include"Creature.h"
class Human : public Creature
{
public:
	Human();
	Human(int newStrength, int newHit);
	int getDamage() const;
	int getStrength() const;
	int getHitpoints() const;
	void setStrength(const int newStrength);
	void setHitpoints(const int newHit);
};
#endif // !HUMAN_H
