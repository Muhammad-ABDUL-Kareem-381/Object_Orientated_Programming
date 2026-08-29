#ifndef STRING_H
#define STRING_H
#include<iostream>
#include<cmath>
using namespace std;
class String
{
	char* data;
	int size;
	int getCharArrayLength(const char* s);
	void setSize(const int s);
	int lengthOfIntegralNum(const long long int num);
	void copyStr(const String&);
	friend istream& operator >> (istream& is, String& st);
	friend ostream& operator << (ostream& os, String& st);
public:
	String();
	String(const char c);
	String(const char*);
	String(const String&);
	~String();
	void input();
	int getLength() const;
	int getSize() const;
	void resize(int);
	void shrink();
	char& at(const int index);
	//const char& at(const int index) const;
	bool isEmpty() const;
	int find(const String& subStr, const int start = 0) const;
	void trimLeft();
	void trimRight();
	void trim();
	void insert(const int index, const String& subStr);
	void remove(const int index, const int count = 1);
	int compare(const String& s2) const;
	bool operator > (const String& s2) const;
	bool operator < (const String& s2) const;
	bool operator == (const String& s2) const;
	void makeUpper();
	void makeLower();
	long long int convertToInteger() const;
	float convertToFloat() const;
	void reverse();
	String concatenate(const String& s2) const;
	void concatEqual(const String& s2);
	String left(const int count);
	String right(const int count);
	int replace(const String& old, const String& newSubStr);
	void setNumber(const long long int num);
	void display() const;
};
void myMemCpy(void* dest, const void* src, int byteCount);
void mySwap(char* dest, char* src);
void Swap(int, int);
istream& operator >> (istream& is, String& st)
{
	cin >> st.data;
	return is;
}
ostream& operator << (ostream& os, String& st)
{
	cout << st.data;
	return os;
}
#endif