#ifndef SHIP_H
#define SHIP_H
#include "D:\Academics\OOP 2.0\Labs\Lab 4\String.ADT\String3.ADT\String.h"
class Ship
{
	String name;
	String model;
public:
	Ship(const String& name, const String& model);
	String getName() const;
	void setName(const String& name);
	String getModel() const;
	void setModel(const String& model);
	virtual void print() const;
};
#endif