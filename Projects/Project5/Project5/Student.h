#ifndef STUDENT_H
#define STUDENT_H
#include"Course.h"
class Student
{
	String name;
	String ID;
	Course** courseList;
	int courseCount;
public:
	Student(const String & name, int ID);
	~Student();
	String getName() const;
	String getID() const;
	void enrollCourse(Course& course);
	void unEnrollCourse(const String& courseID);
	void displayCourses() const;
};
#endif // !STUDENT_H
