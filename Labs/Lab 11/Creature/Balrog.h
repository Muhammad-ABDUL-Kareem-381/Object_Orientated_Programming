#ifndef BALROG_H
#define BALROG_H
#include"Demon.h"
class  Balrog: public Demon
{
public:
	Balrog();
	Balrog(int, int);
	int getDamage() const;
	String getSpecies() const;
};
#endif