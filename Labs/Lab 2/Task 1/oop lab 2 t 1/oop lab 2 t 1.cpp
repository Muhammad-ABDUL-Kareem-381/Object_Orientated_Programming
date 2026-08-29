#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>

using namespace std;
struct Time
{
	int hours;
	int minutes;
	int seconds;
};
Time getTimeDifference(Time givenTime);
int main()
{
	Time t = { 18, 47, 50 };
	Time diffTime = getTimeDifference(t);
	cout << diffTime.hours << " : " << diffTime.minutes << " : " << diffTime.seconds;
	return 0;
}
Time getTimeDifference(Time givenTime)
{
	Time currentTime;
	time_t t = time(0);
	tm curTime = *localtime(&t);
	currentTime.hours = curTime.tm_hour;
	currentTime.minutes = curTime.tm_min;
	currentTime.seconds = curTime.tm_sec;
	Time resultTime, t1, t2;

	if (givenTime.hours > currentTime.hours )
	{
		t1= givenTime;
		t2= currentTime ;
	}
	else 
	{
		if (givenTime.hours < currentTime.hours)
		{
			t2= givenTime;
			t1= currentTime ;
		}
		else
		{
			if (givenTime.minutes > currentTime.minutes)
			{
				t1= givenTime;
				t2= currentTime ;
			}
			else
			{
				if (givenTime.minutes < currentTime.minutes)
				{
					t2= givenTime;
					t1= currentTime ;
				}
				else
				{
					if (givenTime.seconds > currentTime.seconds)
					{
						t1= givenTime;
						t2= currentTime ;
					}
					else
					{
						t2= givenTime;
						t1= currentTime ;
					}
				}
			}
		}
	}
	if (t1.seconds < t2.seconds)
	{
		t1.seconds = t1.seconds + 60;
		t1.minutes--;
	}
	if ((t1.minutes < t2.minutes) || (t1.minutes <= 0))
	{
		if (t1.minutes <= 0)
		{
			t1.minutes = t1.minutes + 60;
			t1.hours--;
		}
		else
		{
			t1.minutes = t1.minutes + 60;
			t1.hours--;
		}
	}
	resultTime.seconds = t1.seconds - t2.seconds;
	resultTime.minutes = t1.minutes - t2.minutes;
	resultTime.hours = t1.hours - t2.hours;
	return resultTime;
}