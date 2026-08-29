#include<iostream>
using namespace std;
struct Rational
{
	int numerator;
	int denominator;
};
void inputRational(Rational& a);
void printRational(Rational a);
Rational addRational(Rational a, Rational b);
Rational diffRational(Rational a, Rational b);
Rational divRational(Rational a, Rational b);
void reduce(Rational* a);
int getGCD(int num1,int num2);
int main()
{
	Rational a, b, d;
	inputRational(a);
	inputRational(b);
	printRational(a);
	printRational(b);
	//d = addRational(a, b);
	//d = diffRational(a, b);
	d = divRational(a, b);
	printRational(d);
	return 0;
}
void inputRational(Rational& a)
{
	cout << "Enter the numerator = ";
	cin >> a.numerator;
	do
	{
		cout << "Enter the denominator = ";
		cin >> a.denominator;
	} 
	while (a.denominator == 0);
}
void printRational(Rational a)
{
	reduce(&a);
	cout << "The numerator is : ";
	cout << a.numerator << "\n";
	cout << "The denominator is : ";
	cout << a.denominator << "\n";
}
int getGCD(int num1, int num2)
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
void reduce(Rational* a)
{
	int GCD = getGCD(a->numerator, a->denominator);
	a->numerator = a->numerator / GCD;
	a->denominator = a->denominator / GCD;
}
Rational addRational(Rational a, Rational b)
{
	Rational c;
	c.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
	c.denominator = a.denominator * b.denominator;
	return c;
}
Rational diffRational(Rational a, Rational b)
{
	Rational c;
	c.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
	c.denominator = a.denominator * b.denominator;
	return c;
}
Rational divRational(Rational a, Rational b)
{
	Rational c;
	c.numerator = (a.numerator * b.denominator);
	c.denominator = (a.denominator * b.numerator);
	return c;
}