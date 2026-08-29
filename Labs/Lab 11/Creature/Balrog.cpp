#include"Balrog.h"
Balrog::Balrog() : Demon(0,0)
{

}
Balrog::Balrog(int st,int hp) : Demon(st, hp)
{}
int Balrog::getDamage() const
{
	return Demon::getDamage();
}
String Balrog::getSpecies() const
{
	return "Balrog";
}