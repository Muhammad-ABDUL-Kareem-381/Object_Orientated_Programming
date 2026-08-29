#include<iostream>
using namespace std;
class Date
{
	int day;
	int month;
	int year;
	void setFactoryVersion()
	{
		day = 1;
		month = 1;
		year = 2001;
	}
public:
	Date()
	{
		setFactoryVersion();
	}
	Date(int d, int m, int y) : Date()
	{
		if((y>0)&&(m>=1 && m<=12) &&(d>=1 && d<=getDaysInMonth(m)))
		{
			day = d;
			month = m;
			year = y;
		}
	}
	void setDate(int d, int m, int y)
	{
		if ((y > 0) && (m >= 1 && m <= 12) && (d >= 1 && d <= getDaysInMonth(m)))
		{
			day = d;
			month = m;
			year = y;
		}
	}
	int getDay()const
	{
		return day;
	}
	int getMonth()const
	{
		return month;
	}
	int getYear() const
	{
		return year;
	}
	void setday(int d)
	{
		if (d > 0 && getDaysInMonth(month))
		{
			day = d;
		}
		//No suitable logic i could find.
	}
	void setMonth(int m)
	{
		if (m >= 1 && m <= 12)
		{
			month = m;
		}
	}
	void setYear(int y)
	{
		if (y > 0)
		{
			year = y;
		}
	}
	void printDateFormat()
	{
		if (!validateDate())
		{
			return;
		}
		char months[12][4] = { {"Jan" }, {"Feb"} , {"Mar"}, {"Apr"},{"May"},{"Jun"},{"Jul"},{"Aug"},{"Sep"},{"Oct"},{"Nov"},{"Dec"} };
		int tempYear = year % 100;
		if (!tempYear)
		{
			tempYear = year;
		}
		cout << day << '-' << months[month - 1] << '-' << tempYear;
	}
	bool isLeapYear()
	{
		if (!(year % 4))
		{
			if (!(year % 100))
			{
				if (!(year % 400))
				{
					return true;
				}
				return false;
			}
			return true;
		}
		return false;
	}
	int getDaysInMonth(int month)
	{
		if (month == 2)
		{
			if (isLeapYear())
			{
				return 29;
			}
			return 28;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return 30;
		}
		return 31;
	}
	Date getPreviousDate()
	{
		Date date;
		if (!validateDate())
		{
			exit(0);
		}
		date.day = day - 1;
		if (!(date.day))
		{
			date.month = month - 1;
			if (!(date.month))
			{
				date.month = 12;
				date.year = date.year - 1;
			}
			date.day = getDaysInMonth();
		}
		return date;
	}
	void inputDate()
	{
		do
		{
			cout << "Enter day:";
			cin >> day;
			cout << "Enter month:";
			cin >> month;
			cout << "Enter year:";
			cin >> year;
		} 
		while (!validateDate());
	}
	bool validateDate()
	{
		if ((year <= 0) || ((month <= 0) || (month > 12)))
		{
			return false;
		}
		if ((day > getDaysInMonth()) || (day <= 0))
		{
			return false;
		}
		return true;
	}
	Date getNextDate()
	{
		Date nextDate;
		nextDate.day = day + 1;
		if (nextDate.day > getDaysInMonth())
		{
			nextDate.day = 1;
			nextDate.month = month + 1;
			if (nextDate.month > 12)
			{
				nextDate.month = 1;
				nextDate.year = year + 1;
			}
		}
		return nextDate;
	}
};
int main()
{
	Date date;
	date.inputDate();
	date.printDateFormat();
	cout << '\n';
	(date.getNextDate()).printDateFormat();
	return 0;
}
