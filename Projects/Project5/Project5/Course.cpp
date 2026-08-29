#include"Course.h"
Course::Course() : name{"\0"},ID{"\0"}
{
	cout << "\n Course cpp file default constructor \n";
}
Course::Course(const String& name, int ID) : Course()
{

	this->ID.setNumber(ID);
}
String Course::getName() const
{
	return name;
}
String Course::getID() const
{
	return ID;
}
void Course::display() const
{
	cout << "Name:";
	name.display();
	cout << "ID:";
	ID.display();
}