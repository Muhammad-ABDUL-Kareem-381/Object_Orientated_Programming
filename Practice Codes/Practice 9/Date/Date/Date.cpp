#include<iostream>
#include"String.h"
using namespace std;
class Date
{
	int day;
	int month;
	int year;
	static const int daysInMonth[13];
	bool isLeapYear() const;
	int getDaysInMonth(int m,int y) const;
	bool isValidYear(int y) const;
	bool isValidMonth(int m) const;
	bool isValidDay(int d) const;
	bool isValidDate(int d, int m, int y) const;
	const char* getMonthInFormat1() const;
	const char* getMonthInFormat2() const;
	bool isIncrementValid(int temp) const;
public:
	Date();
	Date(int d, int m, int y);
	void setDate(int d, int m, int y);
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	int getYear() const;
	int getMonth() const;
	int getDay() const; 
	String getDateInFormat1() const;
	String getDateInFormat2() const;
	String getDateInFormat3() const;
	void printFormat1() const;
	void printFormat2() const;
	void printFormat3() const;
	void incYear(int  inc = 1);
	void incMonth(int  inc = 1);
	void incDay(int inc = 1);
};
const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };




int main()
{
	Date d2{ 29,2,2004 };
	d2.printFormat2();
	cout << "\n";
	d2.incDay(366);
	d2.printFormat2();
	/*Date d1{10,7,3000};
	d1.incDay(61);
	d1.getDateInFormat2().display();*/
	return 0;
}





bool Date::isLeapYear() const
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Date::getDaysInMonth(int m,int y) const
{
	Date temp;
	temp.setYear(y);
	if (temp.isLeapYear() && m == 2)
	{
		return 29;
	}
	else
	{
		return daysInMonth[m];
	}
}
bool Date::isValidYear(int y) const
{
	return(y >= 1500 && y <= 3000);
}
bool Date::isValidMonth(int m) const
{
	return (m >= 1 && m <= 12);
}
bool Date::isValidDay(int d) const
{
	return (d >= 1 && d <= getDaysInMonth(month,year));
}
bool Date::isValidDate(int d, int m, int y) const
{
	return (isValidYear(y) && isValidMonth(m) && d >= 1 && d <= getDaysInMonth(m, y));
}
Date::Date() : day(1), month(1), year(1500)
{

}
Date::Date(int d, int m, int y) : Date()
{
	setDate(d, m, y);
}
void Date::setDate(int d, int m, int y)
{
	if (isValidDate(d,m,y))
	{
		setYear(y);
		setMonth(m);
		setDay(d);
	}
	else
	{
		return;
	}
}
void Date::setYear(int y)
{
	if (isValidYear(y))
	{
		year = y;
	}
	else
	{
		return;
	}
}
void Date::setMonth(int m)
{
	if (isValidMonth(m))
	{
		month = m;
	}
	else
	{
		return;
	}
}
void Date::setDay(int d)
{
	if (isValidDay(d))
	{
		day = d;
	}
	else
	{
		return;
	}
}
int Date::getYear() const
{
	return year;
}
int Date::getMonth() const
{
	return month;
}
int Date::getDay() const
{
	return day;
}
const char* Date::getMonthInFormat1() const
{
	const char* monthName[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	return monthName[month - 1];
}
const char* Date::getMonthInFormat2() const
{
	const char* monthName[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return monthName[month - 1];
}
String Date::getDateInFormat1() const
{
	String y, m, d;
	m.setNumber(month);
	m.concatEqual("/");
	d.setNumber(day);
	d.concatEqual("/");
	m.concatEqual(d);
	y.setNumber(year);
	m.concatEqual(y);
	return m;
}
String Date::getDateInFormat2() const
{
	String m{getMonthInFormat1()},d,y;
	m.concatEqual(" ");
	d.setNumber(day);
	d.concatEqual(", ");
	m.concatEqual(d);
	y.setNumber(year);
	m.concatEqual(y);
	return m;

}
String Date::getDateInFormat3() const
{
	String m{ getMonthInFormat2() }, d, y;
	m.concatEqual("-");
	d.setNumber(day);
	d.concatEqual("-");
	d.concatEqual(m);
	y.setNumber(year);
	d.concatEqual(y);
	return d;
}
void Date::printFormat1() const
{
	cout << month << '/' << day << '/' << year;
}
void Date::printFormat2() const
{
	cout << getMonthInFormat1() << " " << day << ", " << year;
}
void Date::printFormat3() const
{
	cout << day << "-" << getMonthInFormat2() << "-" << year;
}
bool Date::isIncrementValid(int temp) const
{
	return (temp >= 0) ? true : false;
}
void Date::incYear(int  inc )
{
	if (isIncrementValid(inc))
	{
		if ( isValidYear(year+inc) )
		{
			year = year + inc;
		}
		else
		{
			year = 1500 + ((year + inc) % 3001);
		}
		if (!isValidDay(day))
		{
			day = getDaysInMonth(month,year);
		}
	}
	else
	{
		return;
	}
	
}
void Date::incMonth(int  inc)
{
	if (isIncrementValid(inc))
	{
		if (isValidMonth(month + inc))
		{
			month = month + inc;
		}
		else
		{
			incYear((month + inc) / 12);
			month = (month + inc) % 12;
		}
		if (!isValidDay(day))
		{
			day = getDaysInMonth(month, year);
		}
	}
	else
	{
		return;
	}
}
void Date::incDay(int inc)
{
	if (isIncrementValid(inc))
	{
		if (isValidDay(day+inc))
		{
			day = day + inc;
		}
		else
		{
			int temp = day + inc;
			do
			{
				temp = temp - getDaysInMonth(month, year);
				incMonth();
			} 
			while (!isValidDay(temp));
			day = temp;
		}
	}
	else
	{
		return;
	}
}