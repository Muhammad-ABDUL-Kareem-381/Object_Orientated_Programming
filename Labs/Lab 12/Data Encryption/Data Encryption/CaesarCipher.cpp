#include "CaesarCipher.h"
CaesarCipher::CaesarCipher() : shift(0)
{}
CaesarCipher::CaesarCipher(int n) : shift(n)
{}
void CaesarCipher::setShift(int n)
{
	shift = n;
}
int CaesarCipher::getShift() const
{
	return shift;
}
String CaesarCipher::encrypt(const String& plainText) const /*override*/
{
	String temp{ plainText };
	int i = 0;
	while (i < plainText.getLength() || temp.at(i) == '\0')
	{
		if (temp.at(i) >= 'A' && temp.at(i) <= 'Z')
		{
			if (temp.at(i) + shift <= 'Z')
			{
				temp.at(i) += shift;
			}
			else
			{
				temp.at(i) = temp.at(i) + shift - 'Z' + 'A' - 1;
			}
		}
		else
		{
			if (temp.at(i) >= 'a' && temp.at(i) <= 'z')
			{
				if (temp.at(i) + shift <= 'z')
				{
					temp.at(i) += shift;
				}
				else
				{
					temp.at(i) = temp.at(i) + shift - 'z' + 'a' - 1;
				}
			}
		}
		i++;
	}
	return temp;
}
String CaesarCipher::decrypt(const String& cipheredText) const /*override*/
{
	const int* p = & shift;
	*((int *)p) = -1 * (*p);
	return (encrypt(cipheredText));
	//setShift (temp);
}