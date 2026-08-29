#ifndef TASK_H
#define TASK_H
#include "D:\Academics\OOP 2.0\Prcatise Files\PF 9 (of OOP) myCMath & Date\Task 2\Date.ADT\Date3.ADT\Date.h"
#include "D:\Academics\OOP 2.0\Prcatise Files\PF 4 (of OOP) Classes\Task 2\Time ADT\Time ADT\Time.h"
//String.h is already included in Date.h
class Task
{
	Date taskDate;
	Time taskTime;
	String taskMsg;
public:
	Task();
	Task(const Date&, const Time&, const String&);
	void updateDate(const Date&);   //setter
	void updateTime(const Time&);   //setter
	void updateMessage(const String&);   //setter
	Date getDate() const;
	Time getTime() const;
	String getMessage() const;
	/*	no need of destructor as no heap allocation 
	in this class.heap allocation is in String and
	it's responsibility of String class to handle this in destructor.*/
	/*
	No need of copy ctor ,the same reason for it 
	that is for not making destructor ie. no heap allocation occurred
	here . it is occurred inString class so it's responsibility of String class
	to handle, not responsibility of Task class.
	*/
};
#endif