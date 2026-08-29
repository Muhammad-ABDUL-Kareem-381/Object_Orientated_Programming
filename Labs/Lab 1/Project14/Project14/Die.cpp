#include<iostream>
#include<ctime>
using namespace std;
class Die
{
	int sidesCount;
	int value;
	bool isSidesValid(int sides)
	{
		return (sides > 0) ? true : false;
	}
	int getRandomValue()
	{
		srand(time(0));
		return (1 + (rand() % sidesCount));
	}
public:
	Die(int sides = 6)
	{
		if (isSidesValid(sides))
		{
			sidesCount = sides;
		}
		else
		{
			sidesCount = 6;
		}
		value = getRandomValue();
	}
	void roll()
	{
		value = getRandomValue();
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
	Die d1, d2;

	cout<<d1.getValue();
	cout << d2.getValue();
	for (int i = 0; i < 100000; i++)
	{
		for (int j = 0; j < 10000; j++)
		{

		}
	}
	Die d3;
	cout << d3.getValue();
}