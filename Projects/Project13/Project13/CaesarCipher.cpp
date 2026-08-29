#include"CaesarCipher.h"
bool CaesarCipher::isLowerCaseAlphabet(const char& ref) const
{
	return (ref >= 'a' && ref <= 'z')  ? true : false;
}
bool CaesarCipher::isUpperCaseAlphabet(const char& ref) const
{
	return (ref >= 'A' && ref <= 'Z') ? true : false;
}
CaesarCipher::CaesarCipher(int i)
{
	if (i>=0)
	{
		shift = i;
	}
	else
	{
		shift = 0;
	}
	
}
void CaesarCipher::setShift(unsigned int num)
{
	shift = num;
}
unsigned int CaesarCipher::getShift()
{
	return shift;
}
String CaesarCipher::encrypt(const String& plainText) const
{
	String temp{ plainText };
	for (int i = 0; i < temp.getLength(); i++)
	{
		if (isLowerCaseAlphabet(temp[i]))
		{
			temp[i] = temp[i] + (shift % 26);
			if (temp[i] > 'z')
			{
				temp[i] = temp[i] - 26;
			}
		}
		if (isUpperCaseAlphabet(temp[i]))
		{
			temp[i] = temp[i] + (shift % 26);
			if (temp[i] > 'Z')
			{
				temp[i] = temp[i] - 26;
			}
		}
	}
	return temp;
}
String CaesarCipher::decrypt(const String& cipheredText) const
{
	String temp{ cipheredText };
	for (int i = 0; i < temp.getLength(); i++)
	{
		if (isLowerCaseAlphabet(temp[i]))
		{
			temp[i] = temp[i] - (shift % 26);
			if (temp[i] < 'a')
			{
				temp[i] = temp[i] + 26;
			}
		}
		if (isUpperCaseAlphabet(temp[i]))
		{
			temp[i] = temp[i] - (shift % 26);
			if (temp[i] < 'A')
			{
				temp[i] = temp[i] + 26;
			}
		}
	}
	return temp;
}