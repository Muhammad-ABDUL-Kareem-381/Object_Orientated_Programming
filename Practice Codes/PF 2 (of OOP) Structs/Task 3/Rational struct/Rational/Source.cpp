#include<iostream>
using namespace std;
struct Rational
{
	int numerator;
	int denominator;
};
void inputRational(Rational&);
int getGCD(Rational);
void printRational(Rational);
Rational addRational(Rational, Rational);
Rational difRational(Rational, Rational);
Rational divRational(Rational, Rational);
void reduceRational(Rational*);
int main()
{
	Rational r1,r2;
	inputRational(r1);
	inputRational(r2);
	printRational(divRational(r1,r2));
	return 0;
}
void inputRational(Rational& r)
{
	cout << "Enter numerator:";
	cin >> r.numerator;
	do
	{
		cout << "Enter denominator:";
		cin >> r.denominator;
	}
	while (!r.denominator);
}
void printRational(Rational r)
{
	reduceRational(&r);
	if (r.denominator == 1)
	{
		cout << r.numerator;
	}
	else
	{
		cout << r.numerator << '/' << r.denominator;
	}
}
Rational addRational(Rational r1, Rational r2)
{
	if ((!r1.denominator) || (!r2.denominator))
	{
		exit(0);
	}
	Rational sum;
	sum.numerator = (r1.numerator * r2.denominator) + (r1.denominator * r2.numerator);
	sum.denominator = r1.denominator * r2.denominator;
	reduceRational(&sum);
	return sum;
}
Rational difRational(Rational r1, Rational r2)
{
	if ((!r1.denominator) || (!r2.denominator))
	{
		exit(0);
	}
	Rational dif;
	dif.numerator = (r1.numerator * r2.denominator) - (r1.denominator * r2.numerator);
	dif.denominator = r1.denominator * r2.denominator;
	reduceRational(&dif);
	return dif;
}
Rational divRational(Rational r1, Rational r2)
{
	Rational div;
	div.numerator = r1.numerator * r2.denominator;
	div.denominator = r1.denominator * r2.numerator;
	reduceRational(&div);
	return div;
}
int getGCD(Rational r)
{
	if (!r.denominator)
	{
		return 0;
	}
	int remainder = r.numerator % r.denominator;;
	while (remainder)
	{
		r.numerator = r.denominator;
		r.denominator = remainder;
		remainder = r.numerator % r.denominator;
	}
	return r.denominator;
}
void reduceRational(Rational* r)
{
	if (!(r->denominator))
	{
		return;
	}
	int gcd = getGCD(*r);
	r->numerator = r->numerator / gcd;
	r->denominator = r->denominator / gcd;
}