#include<iostream>
#include"String.h"
using namespace std;
class CMath
{

public:
	static float calcPower(int base, int exponent);
	static int calcGCD(int num1, int num2);
	static String toString(long long int num);
	static long long int toInteger(String temp);
};
int main()
{
	cout<<CMath::toInteger("-67786");
	//cout<<pow(56, 9);
	return 0;
}
float CMath::calcPower(int base, int exponent)
{
    if (exponent < 0)
    {
        float result = 1;
        for (int i = -1; i >= exponent; i--)
        {
            result = result / base;
        }
        return result;
    }
    float result = 1;
    for (int i = 1; i <= exponent; i++)
    {
        result = result * base;
    }
    return result;
}
int CMath::calcGCD(int num1, int num2)
{
	int GCD = 1;
	if (num1 > num2)
	{
		for (int i = 1; i <= num1; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
			{
				GCD = i;
			}
		}
	}
	else
	{
		for (int i = 1; i <= num2; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
			{
				GCD = i;
			}
		}
	}
	return GCD;
}
String CMath::toString(long long int num)
{
	String s1;
	s1.setNumber(num);
	return s1;
}
long long int CMath::toInteger(String temp)
{
	return temp.convertToInteger();
}