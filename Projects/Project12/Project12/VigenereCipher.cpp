#include"VigenereCipher.h"
bool VigenereCipher::isLowerCaseAlphabet(const char& ref) const
{
	return (ref >= 'a' && ref <= 'z') ? true : false;
}
bool VigenereCipher::isUpperCaseAlphabet(const char& ref) const
{
	return (ref >= 'A' && ref <= 'Z') ? true : false;
}
VigenereCipher::VigenereCipher(const String& temp) : key()
{
	key = temp;
}
void VigenereCipher::setKey(const String& temp)
{
	key = temp;
}
String VigenereCipher::getKey()const
{
	return key;
}
String VigenereCipher::encrypt(const String& plainText)const
{
	String temp{ plainText };
	static int keyIndex = 0;
	for (int i = 0; i < plainText.getLength(); i++)
	{
		if (keyIndex==key.getLength())
		{
			keyIndex = 0;
		}
		if (isLowerCaseAlphabet(temp[i]))
		{
			int shift = key[keyIndex] - 'A';
			shift = temp[i] + shift;
			if (shift > 'z')
			{
				shift -= 26;
			}
			temp[i] = shift;
			keyIndex++;
		}
		if (isUpperCaseAlphabet(temp[i]))
		{
			int shift = key[keyIndex] - 'A';
			shift= temp[i] + (shift % 26);
			if (shift > 'Z')
			{
				shift -= 26;
			}
			temp[i] = shift;
			keyIndex++;
		}
	}
	return temp;
}
String VigenereCipher::decrypt(const String& cipheredText)const
{
	String temp{ cipheredText };
	int keyIndex = 0;
	for (int i = 0; i < cipheredText.getLength(); i++)
	{
		if (keyIndex == key.getLength())
		{
			keyIndex = 0;
		}
		if (isLowerCaseAlphabet(temp[i]))
		{
			int shift = key[keyIndex] - 'A';
			shift= temp[i] - shift;
			if (shift < 'a')
			{
				shift += 26;
			}
			temp[i] = shift;
			keyIndex++;
		}
		if (isUpperCaseAlphabet(temp[i]))
		{
			int shift = key[keyIndex] - 'A';
			shift = temp[i] - shift;
			if (shift < 'A')
			{
				shift += 26;
			}
			temp[i] = shift;
			keyIndex++;
		}
	}
	return temp;
}