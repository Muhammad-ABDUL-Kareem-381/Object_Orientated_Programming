#ifndef SET_H
#define SET_H
#include<iostream>
using namespace std;
class Set
{
	int* data;
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
	bool searchElement(int element)const;
	int searchElementPosition(int element)const;
	bool isEmpty()const;
	bool isFull()const;
	void displaySet();
	Set calcIntersection(const Set& B, const int newSetCapacity)const;
	int commonElements(const Set& B)const;
	Set calculateUnion(const Set& B, int newSetCapacity)const;
	Set calculateDifference(const Set& B, int newSetCapacity)const;
	bool isSubset(const Set& B)const;
	void reSize(int newSize);
	void displayPowerSet()const;
	void setCapacity(int n);
	void setNoe(int n);
	int getCapacity() const;
	int getNoe() const;
	int countNoe()const;
};
void myMemCpy(void* des, const void* src, int byteCount);
istream& operator >> (istream& is, Set& set);
ostream& operator << (ostream& os, Set& set);
#endif