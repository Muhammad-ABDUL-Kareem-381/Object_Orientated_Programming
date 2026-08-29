#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;
class Array
{
	int capacity;
	int* data;
	const bool isValidIndex(const int index) const;
	static void createArray(int*& temp, const int capacity);
	static bool isValidCapacity(const int capacity);
	static bool isEmpty(const int* data);
	static void copyArrayByUsingLength(int* dest, const int* sour, const int cap);
public:
	Array(int cap = 0);
	Array(const Array & ref );
	~Array();
	int& getSet(const int index);
	const int& getSet(const int index) const;
	int& operator[](const int index );
	const int& operator[](const int index )const;
	const int getCapacity() const;
	void reSize(const int newSize );
	void printArray() const;
	Array& operator=(const Array& ref);
	Array operator++(int num )const;
	Array& operator++();

};
#endif //ARRAY_H