#ifndef BATTLE_SHIP_H
#define BATTLE_SHIP_H
#include"Ship.h"
class BattleShip:public Ship
{
	int missiles;
public:
	BattleShip(const String& name, const String& model,int = 0);
	int getMissiles() const;
	void setMissiles(int);
	void print() const;
};
#endif