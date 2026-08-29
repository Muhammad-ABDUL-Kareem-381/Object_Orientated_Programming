#ifndef SET_H
#define SET_H
#include<iostream>
#include"Array.h"
using namespace std;
class Set
{
	Array data;
	int noOfElements;
	bool isFull() const;
	bool isEmpty() const;
	const int searchElementPosition(const int element) const;
	float calculatePower(const int base, const int exponent) const;

public:
	Set(int cap = 0);
	void insert(int element);
	void remove(int element);
	void print() const;
	bool isMember(int val) const;
	int getCardinality() const;
	int isSubSet(Set s2) const;
	void reSize(int newCapacity);
	Set calcUnion(const Set& s2) const;
	Set calcIntersection(const Set& s2) const;
	Set calcDifference(const Set& s2) const;
	void displayPowerSet() const;
};







#endif // !SET_H
