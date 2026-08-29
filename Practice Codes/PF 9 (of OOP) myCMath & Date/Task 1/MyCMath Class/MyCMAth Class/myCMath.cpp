#include"myCMath.h"
float MyCMath::calcPower(int base, int exponent)
{
	if (exponent < 0)
	{
		exit(0);
	}
	float res = 1;
	for (int i = 0; i < exponent; i++)
	{
		res = res * base;
	}
	return res;
}
int MyCMath::calcGCD(int num1, int num2)
{
	int dividend, divisor;
	if (num1 < num2)
	{
		divisor = num1;
		dividend = num2;
	}
	else
	{
		divisor = num2;
		dividend = num1;
	}
	int remainder =  dividend % divisor;
	while (remainder)
	{
		dividend = divisor;
		divisor = remainder;
		remainder = dividend % divisor;
	}
	return divisor;
}
