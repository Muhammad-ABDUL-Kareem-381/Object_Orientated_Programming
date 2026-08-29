#include<iostream>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
};
int main()
{
	Date d;
	d.day = 34;
	d.month = 2;
	d.year = 2020;
	int* p = (int*)&d;
	p[0] = 14;
	p[1] = 8;
	p[2] = 1947;
	cout << d.day << '-' << d.month << "-" << d.year<<"\n";
	return 0;
}