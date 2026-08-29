#ifndef OFFERED_COURSES_H
#define OFFERED_COURSES_H
#include"Course.h"
class OfferedCourses
{
	Course courses[10];
	int noOfCourses;

public:
	OfferedCourses();
	void displayOfferedCourses() const;
	void addCourse(const Course& course);
	const Course& getCourse(int index) const;

};
#endif // !OFFERED_COURSES_H
