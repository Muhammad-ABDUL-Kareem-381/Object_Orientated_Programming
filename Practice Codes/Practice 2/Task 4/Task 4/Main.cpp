#include<iostream>
#include<iomanip>
using namespace std;
struct MonthDays
{
	char month[10];
	int days;
};
int main()
{
	const char* month[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int daysOfMonths[12] = { 31,28,31,30,31,30,31,30,30,31,30,31 };
	MonthDays year[12] = { "January",31,"February",28,"March",31,"April",30,"May",31,"June",30,"July",31,"August",30,"September",30,"October",31,"November",30,"December",31 };
	for (int  i = 0; i < 12; i++)
	{
		cout <<"\n" << setw(15) << left << setfill('-') << month[i] << setw(5) << setfill('-') << daysOfMonths[i] << "\n";
	}
	for (int i = 0; i < 12; i++)
	{
		cout <<"\n" << setw(15) << left << setfill('-') << year[i].month << setw(5) << setfill('-') << year[i].days <<"\n";
	}
	return 0;
}