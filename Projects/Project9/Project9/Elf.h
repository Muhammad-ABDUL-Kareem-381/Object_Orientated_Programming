#ifndef ELF_H
#define ELF_H
#include"Creature.h"
class Elf : public Creature
{
public:
	Elf();
	Elf(int newStrength, int newHit);
	int getDamage() const;
	int getStrength() const;
	int getHitpoints() const;
	void setStrength(const int newStrength);
	void setHitpoints(const int newHit);
};
#endif // !ELF_H
