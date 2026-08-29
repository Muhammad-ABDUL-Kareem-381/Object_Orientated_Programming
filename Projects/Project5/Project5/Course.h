#ifndef COURSE_H
#define COURSE_H
#include"String.h"
class Course
{
	String name;
	String ID;
public:
	Course();
	Course(const String& name, int ID);
	String getName() const;
	String getID() const;
	void display() const;

};
#endif // !COURSE_H
