#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class String
{
	char* data;
	int size;
	bool isValidIndex(const int index) const;
	static void mySwap(char* a, char* b);
	static int giveResultOfComparingGivenStringsIndexValue(const char str1,const char str2);
	bool isStringNegative() const;
	bool isStringPositive() const;
	static int giveNumberLength(long long int a);
	static int giveLengthOfGivenString(const char* temp);
	static bool isNullPtr(const char* pointer);
	static bool isNullCharacter(const char character);
	static void createString(char*& string, const int size);
	static void copyString(char* dest, const char* sour);
	static void copyStringByUsingLength(char* dest, const char* sour, const int sizeOfSource);
public:
	String();
	String(const long long int a);
	String(const char c);
	String(const char* c);
	String(const String&ref);
	String(String&& ref) noexcept;
	~String();
	void input();
	void shrink();
	char& at(const int index);
	const char& at(const int index) const;
	bool isEmpty() const;
	int getLength() const;
	int getSize() const;
	void display() const;
	int find(const String& subStr,const int start = 0) const;
	void insert(const int index,const String& subStr);
	void remove(const int index, const int count = 1);
	int replace(const String& old,const String& newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(const int c);
	int compare(const String& s2) const;
	String left(const int count);
	String right(const int count);
	long long int convertToInteger() const;
	float convertToFloat() const;
	String concatenate(const String& s2) const;
	void concatEqual(const String& s2);
	void concatEqual(const long long int num);
	void setNumber(const long long int a);
	String operator =(const long long int a);
	String operator +(const String& s2) const;
	String operator -(const String& s2) const;
	String operator = (const String& s2);
	char& operator [](const int a);
	void operator +=(const String& s2);
	void operator -=(const String& s2);
	void operator()(const int count, ...);
	bool operator ==(const String& s2) const;
	bool operator >(const String& s2) const;
	bool operator <(const String& s2) const;
	bool operator <=(const String& s2) const;
	bool operator >=(const String& s2) const;
	bool operator !=(const String& s2) const;
	void concatAll(const unsigned int count, ...);
	friend istream& operator >>(istream& s1, String& s2);
	friend ostream& operator <<(ostream& s1, const String& s2);
};
#endif // !STRING_H
