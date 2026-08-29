#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H
#include"Math.h"
enum Comparison {EQUAL, SMALL, LARGE};
class BigNumber
{
	char* number;
	int numberLength;
	BigNumber();
	void createArray(char*& a, int size) const;
	void copyArray(char* dest, const char* sour, int size) const;
public:
	BigNumber(const char* a);
	BigNumber(const BigNumber& ref);
	~BigNumber();
	void setNumber(const char* num);
	BigNumber add(const BigNumber & other ) const;
	BigNumber subtract(const BigNumber& other) const;
	BigNumber multiply(const BigNumber& other) const;
	void print() const;
	Comparison compare(const BigNumber& a) const;
};


#endif // !BIG_NUMBER_H
