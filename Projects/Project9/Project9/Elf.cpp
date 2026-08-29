#include"Elf.h"
Elf::Elf() : Creature()
{

}
Elf::Elf(int newStrength, int newHit) : Creature(newStrength, newHit)
{

}
int Elf::getDamage() const
{
	int dem = Creature::getDamage();
	int rand1 = (rand() % 100);
	if (rand1<10)
	{
		dem = dem * 2;
	}
	cout << "Human " << "attacks for " << dem << " points!" << "\n";
	return dem;
}
int Elf::getStrength() const
{
	return Creature::getStrength();
}
int Elf::getHitpoints() const
{
	return Creature::getHitpoints();
}
void Elf::setStrength(const int newStrength)
{
	Creature::setStrength(newStrength);
}
void Elf::setHitpoints(const int newHit)
{
	Creature::setHitpoints(newHit);
}