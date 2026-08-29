#include "VigenereCipher.h"
VigenereCipher::VigenereCipher() : shift(0)
{}
VigenereCipher::VigenereCipher(int n): shift(n)
{}
void VigenereCipher::setShift(int n)
{
	shift = n;
}
int VigenereCipher::getShift() const
{
	return shift;
}
void VigenereCipher::setKey(String& k)
{
	//key = k;
	//key.copyStr(k);
}
String VigenereCipher::getKey() const
{
	return key;
}
String VigenereCipher::encrypt(const String& plainText) const /*override*/
{
	//int i = 0, y=0;
	//int* p = & ((int)shift);
	String tempSt{ plainText };
	//while (i<tempSt.getLength() && tempSt.at(i) != '\0')
	//{
	//	if (tempSt.at(i) >= 'A' && tempSt.at(i) <= 'Z')
	//	{
	//		*((int*)p) = ((String)key).at(y) - 'A';
	//		//this->shift = ((String)key).at(i) - 'A';
	//		if (tempSt.at(i) + shift <= 'Z')
	//		{
	//			tempSt.at(i) = tempSt.at(i) + shift;
	//		}
	//		else
	//		{
	//			tempSt.at(i) = tempSt.at(i) + shift - 'Z' + 'A' - 1;
	//		}
	//	}
	//	else
	//	{
	//		if (tempSt.at(i) >= 'a' && tempSt.at(i) <= 'z')
	//		{
	//			//*((int*)p) = ((String)key).at(y) - 'a' ;
	//			if (tempSt.at(i) + shift <= 'z')
	//			{
	//				tempSt.at(i) = tempSt.at(i) + shift;
	//			}
	//			else
	//			{
	//				tempSt.at(i) = tempSt.at(i) + shift - 'z' + 'a' - 1;
	//			}
	//		}
	//	}
	//	i++;
	//	y++;
	//	if (y == key.getLength() - 1)
	//	{
	//		y = 0;
	//	}
	//}
	return tempSt;
}
String VigenereCipher::decrypt(const String& cipheredText) const
{
	cout << "123";
	return "Ali";
}