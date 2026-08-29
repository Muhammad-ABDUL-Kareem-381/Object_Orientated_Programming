#include "Watch.h"
Watch::Watch() :watchDate(), watchTime()
{
}
Watch::Watch(Date d, Time t) : watchDate(d), watchTime(t)
{
}
Watch::Watch(const Watch& ref) : watchDate(ref.watchDate), watchTime(ref.watchTime)
{
}
void Watch::setTime(Time t)
{
	watchTime = t;
}
void Watch::setDate(Date d)
{
	watchDate = d;
}
void Watch::setMinute(int m)
{
	watchTime.setMinutes(m);
}
void Watch::setSecond(int s)
{
	watchTime.setSeconds(s);
}
void Watch::setHour(int h)
{
	watchTime.setHours(h);
}
void Watch::setTime(int h, int m, int s)
{
	watchTime.setTime(h, m, s);
}
Date Watch::getDate() const
{
	return watchDate;
}
Time Watch::getTime() const
{
	return watchTime;
}
int Watch::getHour() const
{
	return watchTime.getHours();
}
int Watch::getMinute() const
{
	return watchTime.getMinutes();
}
int Watch::getSecond() const
{
	return watchTime.getSeconds();
}
void Watch::printTwentyFourHourFormat() const
{
	watchTime.printTwentyFourHourFormat();
}
void Watch::printTwelveHourFormat() const
{
	watchTime.printTwelveHourFormat();
}
void Watch::setDay(int d)
{
	watchDate.setDay(d);
}
void Watch::setMonth(int m)
{
	watchDate.setMonth(m);
}
void Watch::setYear(int y)
{
	watchDate.setYear(y);
}
int Watch::getDay() const
{
	return watchDate.getDay();
}
int Watch::getMonth() const
{
	return watchDate.getMonth();
}
int Watch::getYear() const
{
	return watchDate.getYear();
}
void Watch::incSec(int inc)
{

	if ((inc + getSecond()) < 60)
	{
		setSecond(inc + getSecond());
	}
	else
	{
		int tempSec = getSecond();
		setSecond((inc + tempSec) % 60);
		incMin((inc + tempSec) / 60);
	}
	/*int timeInSec = (getHour() * 60*60) + (getMinute() * 60) + getSecond();
	watchTime.incSec(inc);
	int incrementDay = (timeInSec + inc) / (24 * 60 * 60);
	incDay(incrementDay);*/
}
void Watch::incMin(int inc)
{
	if ((inc + getMinute()) < 60)
	{
		setMinute(inc + getMinute());
	}
	else
	{
		int tempMin = getMinute();
		setMinute((inc + tempMin) % 60);
		incHour((inc + tempMin) / 60);
	}
	/*int timeInSec = (getHour() * 60*60) + (getMinute() * 60) + getSecond();
	watchTime.incMin(inc);
	int incrementDay = (timeInSec + (inc*60) ) / (24 * 60 * 60);
	incDay(incrementDay);*/
}
void Watch::incHour(int inc)
{
	if ((inc + getHour()) < 24)
	{
		setHour(inc + getHour());
	}
	else
	{
		int tempHour = getHour();
		setHour((inc + tempHour) % 24);
		incDay((inc + tempHour) / 24);
	}
	/*int timeInSec = (getHour() * 60*60) + (getMinute() * 60) + getSecond();
	watchTime.incHour(inc);
	int incrementDay = (timeInSec + (inc * 60*60)) / (24 * 60 * 60);
	incDay(incrementDay);*/
}
void Watch::deccSec(int dec)
{
	int decrementedSec = getSecond() - dec;
	if (decrementedSec < 0)
	{
		decrementedSec = decrementedSec * (-1);
		int decrementMin = (decrementedSec / 60) + 1;
		if (decrementedSec == 60)
		{
			decrementMin--;
		}
		decMin(decrementMin);
		if (dec > 60)
		{
			dec = dec / 60;
		}
		dec = dec * (-1);
		setSecond(60 + dec + getSecond());
		if (getSecond() < 0)
		{
			setSecond(getSecond() + 60);
		}
	}
	else
	{
		setSecond(getSecond() - dec);
	}
	//watchTime.decSec(dec);
}
void Watch::decMin(int dec)
{
	int decrementedMin = getMinute() - dec;
	if (decrementedMin >= 0)
	{
		setMinute(getMinute() - dec);
		return;
	}
	decrementedMin = decrementedMin * (-1);
	int decrementHours = (decrementedMin / 60) + 1;
	if (decrementedMin == 60)
	{
		decrementHours--;
	}
	decHour(decrementHours);
	dec = dec * (-1);
	setMinute(60 + dec + getMinute());
	if (getMinute() < 0)
	{
		setMinute(getMinute() + 60);
	}
	//watchTime.decMin(dec);
}
void Watch::decHour(int dec)
{
	int tempHours = getHour();
	if ((tempHours - dec) < 0)
	{
		setHour(0);
		dec = dec - tempHours;
		setHour(24 - (dec % 24));
		decDay((dec / 24) + 1);
	}
	else
	{
		watchTime.decHour(dec);
	}
	decDay((tempHours - dec) / 24);
}
void Watch::incDay(int inc)
{
	watchDate.incDay(inc);
}
void Watch::incMonth(int inc)
{
	watchDate.incMonth(inc);
}
void Watch::incYear(int inc)
{
	watchDate.incYear(inc);
}
void Watch::decDay(int dec)
{
	watchDate.decDay(dec);
}
void Watch::decMonth(int dec)
{
	watchDate.decMonth(dec);
}
void Watch::decYear(int dec)
{
	watchDate.decYear(dec);
}