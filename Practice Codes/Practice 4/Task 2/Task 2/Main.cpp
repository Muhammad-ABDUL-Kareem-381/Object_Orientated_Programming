#include<iostream>
using namespace std;
class Time
{
	int hours;
	int minutes;
	int seconds;
	bool isMinutesOrSecondsValid(int temp)
	{
		return (temp >= 0 && temp <= 59) ? true : false;
	}
	bool isHoursValid(int temp)
	{
		return(temp >= 0 && temp <= 23) ? true : false;
	}
	bool isIncrementValid(int temp)
	{
		return (temp >= 0) ? true : false;
	}
public:
	Time()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	Time(int h, int m, int s) : Time()
	{
		setHour(h);
		setMinute(m);
		setSecond(s);
	}
	void setMinute(int m)
	{
		if (isMinutesOrSecondsValid(m))
		{
			minutes = m;
		}
	}
	void setSecond(int s)
	{
		if (isMinutesOrSecondsValid(s))
		{
			seconds = s;
		}
	}
	void setHour(int h)
	{
		if (isHoursValid(h))
		{
			hours = h;
		}
	}
	void setTime(int h, int m, int s)
	{
		setHour(h);
		setMinute(m);
		setSecond(s);
	}
	int getHour()
	{
		return hours;
	}
	int getMinute()
	{
		return minutes;
	}
	int getSecond()
	{
		return seconds;
	}
	void printTwentyFourHourFormat()
	{
		cout << getHour() << ":" << getMinute() << ":" << getSecond() <<"\n";
	}
	void printTwelveHourFormat()
	{
		if (getHour()==0)
		{
			cout << "12" << ":" << getMinute() << ":" << getSecond() << " " << "AM" << "\n";
		}
		else if (getHour()>0&&getHour()<12)
		{
			cout << getHour() << ":" << getMinute() << ":" << getSecond() << " " << "AM" << "\n";
		}
		else if (getHour()==12)
		{
			cout << getHour() << ":" << getMinute() << ":" << getSecond() << " " << "PM" << "\n";
		}
		else
		{
			cout << (getHour()-12) << ":" << getMinute() << ":" << getSecond() << " " << "PM" << "\n";
		}
	}
	void incSec(int i = 1)
	{
		if (isIncrementValid(i))
		{
			incMin((seconds + i) / 60);
			seconds = (seconds + i) % 60;
		}
	}
	void incMin(int i = 1)
	{
		if (isIncrementValid(i))
		{
			incHour((minutes + i) / 60);
			minutes = (minutes + i) % 60;
		}
	}
	void incHour(int i = 1)
	{
		if (isIncrementValid(i))
		{
			hours = (hours + i) % 24;
		}
	}

};
int main()
{
	Time t = { 23,59,59 };
	t.printTwelveHourFormat();
	t.printTwentyFourHourFormat();
	t.incSec(-3600);
	t.printTwelveHourFormat();
	t.printTwentyFourHourFormat();
	return 0;
}