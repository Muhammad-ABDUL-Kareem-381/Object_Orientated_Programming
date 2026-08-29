#include"Math.h"
bool checkForNullPointer(const char* a)
{
	return (a == nullptr) ? true : false;
}
bool checkForNullCharacter(const char* a)
{
	return (a == "\0") ? true : false;
}
int getLength(const char* a)
{
	if (checkForNullPointer(a) == true || checkForNullCharacter(a) == true)
	{
		return 0;
	}
	int length = 0;
	while (a[length] != '\0')
	{
		length++;
	}
	return length;
}