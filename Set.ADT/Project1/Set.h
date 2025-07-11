#ifndef SET_H
#define SET_H
#include<iostream>
using namespace std;
class Set
{
	int * data;
	int capacity;
	int noe;
public:
	friend istream& operator >> (istream& is, Set& set);
	friend ostream& operator << (ostream& os, Set& set);
	Set();
	~Set();
	void createSet();
	void inputSet(int noe);
	bool addElement(int element);
	bool removeElement(int element);
	bool searchElement(int element);
	int searchElementPosition(int element);
	bool isEmpty();
	bool isFull();
	void displaySet();
	Set calcIntersection(Set B, const int newSetCapacity);
	int commonElements(Set B);
	Set calculateUnion(Set B, int newSetCapacity);
	Set calculateDifference(Set B , int newSetCapacity);
	bool isSubset(Set B);
	void reSize(int newSize);
	//void displayPowerSet();
	void setCapacity(int n);
	void setNoe(int n);
	int getCapacity() const;
	int getNoe() const;
	int countNoe();
};
void myMemCpy(void * des, const void * src, int byteCount);
istream& operator >> (istream & is, Set & set);
ostream& operator << (ostream& os, Set& set);
#endif