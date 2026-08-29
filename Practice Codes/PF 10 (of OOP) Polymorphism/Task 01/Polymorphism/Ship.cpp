#include "Ship.h"
Ship::Ship(const String& name, const String& model):name(name),model(model)
{}
String Ship::getName() const
{
	return name;
}
void Ship::setName(const String& name)
{
	if (name)
	{
		this->name = name;
	}
}
String Ship::getModel() const
{
	return model;
}
void Ship::setModel(const String& model)
{
	if (model)
	{
		this->model = model;
	}
}
void Ship::print() const
{
	cout << name << '\n' << model;
}