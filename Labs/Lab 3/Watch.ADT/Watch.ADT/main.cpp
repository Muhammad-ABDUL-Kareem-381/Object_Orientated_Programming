#include"Watch.h"
int main()
{
	Watch w{ Date{31,12,2005 } , Time {23,59,0} };
	w.incSec(365*24*60*60+60);
	w.getDate().printFormat1();
	cout << '\n';
	w.getTime().printTwentyFourHourFormat();
	cout << '\n';
}