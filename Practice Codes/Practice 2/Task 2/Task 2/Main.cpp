#include <iostream>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
};
void printDateFormat1(Date d);
void inputDate(Date& d);
Date getPreviousDate(Date d);
bool isLeap(int year);
int getDaysCountInGivenMonth(int month, int year);
int main()
{
    Date d1,d2;
    inputDate(d1);
    printDateFormat1(d1);
    d2 = getPreviousDate(d1);
    printDateFormat1(d2);
    //cout << d2.day << "-" << d2.month << "-" << d2.year << "\n";
    return 0;
}
bool isLeap(int year)
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
int getDaysCountInGivenMonth(int month, int year)
{
    int day;
    bool result = isLeap(year);
    if (result == true && month == 2)
    {
        day = 29;
    }
    else if (result != true && month == 2)
    {
        day = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        day = 30;
    }
    else
    {
        day = 31;
    }
    return day;
}
void inputDate(Date& d)
{
    do
    {
        cout << "Enter year = ";
        cin >> d.year;
    } 
    while (d.year < 1);
    do
    {
        cout << "Enter month = ";
        cin >> d.month;
    } 
    while (d.month < 1 || d.month>12);
    int days = getDaysCountInGivenMonth(d.month, d.year);
    do
    {
        cout << "Enter day = ";
        cin >> d.day;
    } 
    while (d.day<1 || d.day>days);
}
void printDateFormat1(Date d)
{
    const char* monthName[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
    cout << d.day << "-" << monthName[d.month - 1] << "-" << d.year << "\n";
}
Date getPreviousDate(Date d)
{
    if (d.day>1)
    {
        d.day = d.day - 1;
        return d;
    }
    else if (d.month>1)
    {
        d.month = d.month - 1;
        d.day = getDaysCountInGivenMonth(d.month, d.year);
        return d;
    }
    else
    {
        d.year = d.year - 1;
        d.month = 12;
        d.day = 31;
        return d;
    }
}