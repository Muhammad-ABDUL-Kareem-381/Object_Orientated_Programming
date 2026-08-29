#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include"Demon.h"
class  Cyberdemon : public Demon
{
public:
	Cyberdemon();
	Cyberdemon(int st, int hp);
	int getDamage() const;
	String getSpecies() const;
};
#endif