#include"StringFunctions.h"
int giveLengthOfGivenString(const char* c)
{
	if (isNullPtr(c) == true || isNullCharacter(c[0]) == true)
	{
		return 0;
	}
	int count = 0;
	while (c[count] != '\0')
	{
		count++;
	}
	return count;
}
bool isNullPtr(const char* pointer)
{
	return (pointer == nullptr) ? true : false;
}
bool isNullCharacter(const char character)
{
	return (character == '\0') ? true : false;
}
void createString(char*& string, int size)
{
	string = new char[size];
}
void copyString(char* dest, const char* sour)
{
	if (isNullPtr(dest) == true)
	{
		return;
	}
	if (isNullPtr(sour) == true || isNullCharacter(sour[0]) == true)
	{
		dest[0] = '\0';
		return;
	}
	int count = 0;
	while (sour[count] != '\0')
	{
		dest[count] = sour[count];
		count++;
	}
	dest[count] = '\0';
}
void copyStringByUsingLength(char* dest, const char* sour, int size)
{
	if (size <= 0)
	{
		dest = nullptr;
		return;
	}
	if (isNullPtr(dest) == true)
	{
		return;
	}
	if (isNullPtr(sour) == true || isNullCharacter(sour[0]) == true)
	{
		dest[0] = '\0';
		return;
	}
	int count = 0;
	while (count < size - 1)
	{
		dest[count] = sour[count];
		count++;
	}
	dest[count] = '\0';
}