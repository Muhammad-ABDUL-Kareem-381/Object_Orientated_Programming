#include<iostream>
#include<time.h>
using namespace std;
class Die
{
	int sidesCount;
	int value;
public:
	Die(int sides = 6)
	{
		if (sides >= 1)
		{
			sidesCount = sides;   
			srand(time(0));    //use rol() here
			// use srand() in main() only
			value = (rand()%sidesCount) +1 ;
		}
		else
		{
			sidesCount = 6;
			srand(time(0));
			value = (rand() % sidesCount) + 1;
		}
	}
	void roll()
	{
		//srand(time(0)+45);
		value=(rand() % sidesCount) + 1;
	}
	int getSidesCount()
	{
		return sidesCount;
	}
	int getValue()
	{
		return value;
	}
};
int main()
{
	Die test{ 4 };
	cout  << test.getSidesCount() << '\n';
	cout << test.getValue()<<'\n';
	test.roll();
	cout << test.getValue();
}