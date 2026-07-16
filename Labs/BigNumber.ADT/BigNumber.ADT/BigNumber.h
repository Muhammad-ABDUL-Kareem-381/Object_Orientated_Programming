#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H
#include<iostream>
using namespace std;
enum Comparison { EQUAL, SMALL, LARGE };
class BigNumber
{
	char* number;
	int numberLength;
	friend istream & operator >> (istream& is,  BigNumber& bn);
	friend ostream & operator << (ostream& os, const BigNumber& bn);
	void setNumberSize(const int size);
	void removeZerosAtLeft();
	void shrink();
	void makeBigNumberZero();
	void reLength(int newLength);
	void print()const;
	void inputBigNumber();
	Comparison compare(const BigNumber bn2)const;
public:
	BigNumber();
	BigNumber(const char*);
	BigNumber(const BigNumber&);
	BigNumber(BigNumber&&);
	~BigNumber();
	BigNumber& operator = (const BigNumber &);
	BigNumber& operator=(long long int);
	BigNumber operator + (const BigNumber&)const;
	BigNumber operator - (const BigNumber& other)const;
	BigNumber operator *(const BigNumber& other) const;
	BigNumber operator /(const BigNumber& other) const;
	BigNumber operator %(const BigNumber& other) const;
	void operator += (const BigNumber& other);
	void operator -= (const BigNumber& other);
	void operator *= (const BigNumber& other);
	void operator /= (const BigNumber& other);
	BigNumber& operator ++ ();
	BigNumber operator ++ (int);
	bool operator == (const BigNumber& other)const;
	bool operator >  (const BigNumber& other)const;
	bool operator < (const BigNumber& other)const;
	bool operator >=  (const BigNumber& other)const;
	bool operator <=  (const BigNumber& other)const;
	bool operator != (const BigNumber& other)const;
	bool operator !()const;
	bool operator()()const;
	void setNumberLength(const int l);
	int getNumberLength()const;
	void resize(int newLength);
	void operator = (const char* num);
	static void myMemCpy(void* dest, const void* src, int byteCount);
	static int getLength(const char* num);
};
istream& operator >> (istream& is, BigNumber& bn);
ostream& operator << (ostream& os, const BigNumber& bn);
#endif