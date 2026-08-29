#include "MyString.h"
int getStringLength(const char* str)
{
	int i = 0;
	while (str[i])  // '\0' is 0 in ASCII
	{
		i++;
	}
	return i;
}
void concatenate(char* destination, char* source)
{
	int destLen = getStringLength(destination);

}
void copyString(char* destination, const char* source)
{
	int i = 0;
	while (source[i])
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}
int converttoInteger(const char* str)
{
	int integer = 0;
	int strLen = getStringLength(str);
	for (int i = 0; i < strLen; i++)
	{
		integer = integer * 10 + (str[i] + '0');
	}
	return integer;
}
float convertToFloat(const char* str)
{
	float num = 0.0;
	int strLen = getStringLength(str);
	for (int i = 0; i < strLen; i++)
	{
		if (str[i] != '.')
		{
			num = num * 10 + (str[i] + '0');
		}

	}
}
void makeUpper( char* str)
{
	int strLen = getStringLength(str);
	for (int i = 0; i < strLen; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - ('a' - 'A');
		}
	}
}
void makeLower(char* str)
{
	int strLen = getStringLength(str);
	for (int i = 0; i < strLen; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + ('a' - 'A');
		}
	}
}
void reverse(char* str)
{
	int strLen = getStringLength(str);
	for (int i = 0; i < (strLen / 2); i++)
	{
		swapCharacters(str[i], str[strLen - i - 1]);
	}
}
void swapCharacters(char &a, char& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
int compare( char* a,  char* b, bool caseSensitive)
{
	int strLenA = getStringLength(a);
	int strLenB = getStringLength(b);
	if (strLenA > strLenB)
	{
		return 1;
	}
	else if (strLenA < strLenB)
	{
		return -1;
	}
	else
	{
		bool equalStatus=true;
		int i = 0;
		if (!caseSensitive)
		{
			makeLower(a);
			makeLower(b);
		}
		while ((i < strLenA) && equalStatus)
		{
			equalStatus = (a[i] == b[i]) ? true : false;
			i++;
		}
		if (a[i] > b[i])
		{
			return 1;
		}
		return -1;
	}	
}
int findSubStr(const char* destination, const char* key, int start)
{
	int i = 0;
	int destLen = getStringLength(destination);
	int keyLen = getStringLength(key);
	bool equalStatus = false;
	while (!equalStatus)
	{
		if (destination[start] == key[i])
		{
			equalStatus = true;
			i++;
		}
		start++;
	}
	if (equalStatus)
	{
		while (equalStatus && key[i])
		{
			if (destination[start] == key[i])
			{
				equalStatus = true;
			}
			i++;
			start++;
		}
	}
	return (start - keyLen);
}