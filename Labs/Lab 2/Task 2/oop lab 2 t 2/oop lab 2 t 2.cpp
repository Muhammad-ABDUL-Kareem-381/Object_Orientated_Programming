#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
using namespace std;
struct Date {
	int day; 
	int month;
	int year;
};
struct Time
{
	int hours;
	int minutes;
	int seconds;
};
struct Token
{
	int tokenNumber;
	Date tokenDate;
	Time tokenTime;
};
struct ServiceCounter
{
	int counterNumber;
	Token list[100];
	int tokensCount;
};
int tokenNum = 0;
void printDate(Date d);
Token generateToken();
void printTime(Time t);
void printToken(Token tok);
void initializeServiceCounter(ServiceCounter&);
int main()
{
	Token x=generateToken();
	printToken(x);
	Token y = generateToken();
	printToken(y);
	ServiceCounter srvCnt;
	initializeServiceCounter(srvCnt);
	return 0;
}
void printDate(Date d)
{
	cout << d.day << ":" << d.month << ':' << d.year;
}
void printTime(Time t)
{
	if ((t.hours <= 12) && (t.hours != 0))
	{
		cout << t.hours << ':' << t.minutes << ':' << t.seconds << " AM";
	}
	else
	{
		if (t.hours == 0)
		{
			cout <<"12:" << t.minutes << ':' << t.seconds << " AM";
		}
		else
		{
			cout << (t.hours - 12) << ':' << t.minutes << ':' << t.seconds << " PM";
		}
	}
}
Token generateToken()
{
	// for system date
	Date currentDate;
	time_t t = time(0);
	tm curTime = *localtime(&t);
	currentDate.day = curTime.tm_mday;
	currentDate.month = curTime.tm_mon + 1;
	currentDate.year = curTime.tm_year + 1900;
	// for system time
	Time currentTime;
	currentTime.hours = curTime.tm_hour;
	currentTime.minutes = curTime.tm_min;
	currentTime.seconds = curTime.tm_sec;
	// for token number
	Token tok;
	tok.tokenNumber = 0;
	tok.tokenDate = currentDate;
	tok.tokenTime = currentTime;
	tokenNum++;
	tok.tokenNumber = tokenNum;
	return tok;
}
void printToken(Token tok)
{
	cout << "Token # : " << tok.tokenNumber << '\n';
	cout << "Date: ";
	printDate(tok.tokenDate);
	cout << "\n";
	cout << "Time: ";
	printTime(tok.tokenTime);
	cout << "\n";
}
void initializeServiceCounter(ServiceCounter & srvCnt)
{
	
}