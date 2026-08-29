#include<iostream>
using namespace std;
void copyCharArray(const char* src, char* tar);
class RomanNumeral
{
	char romanNumber[100];
	int decimalNumber;
	void convertRomanNumberToDecimal()
	{
		int num = 0;
		int i = 0;
		while (romanNumber[i] != '\0')
		{
			if (getValueOfRomanDigit(romanNumber[i]) >= getValueOfRomanDigit (romanNumber[i + 1]))
			{
				num = num + getValueOfRomanDigit(romanNumber[i]);
			}
			else
			{
				num = num - getValueOfRomanDigit(romanNumber[i]);
			}
			i++;
		}
		decimalNumber = num;
	}
	void convertDecimalNumberToRoman()
	{
		char romanNo[100];
		int dec = decimalNumber;
		int i = 0;
		while (dec)
		{
			romanNo[i] = getAMaximumRomanDigit(dec);
			if ()
			{

			}
			dec = dec - getValueOfRomanDigit(romanNo[i]);
			i++;
		}
		romanNo[i] = '\0';
		copyCharArray(romanNo, romanNumber);
	}
	const char * getAMaximumRomanDigit(int dec)
	{
		int maxValueOfRomanDigits[7] = { 1,5,10,50,100,500,1000 };
		const char* maxRomanDigits[7] = { "I","V","X","L","C","D","M" };
		int minValueOfRomanDigits[6] = { 4,9,40,90,400,900 };
		const char* minRomanDigits[6] = { "IV","IX","XL","XC","CD","CM", };
		int i = 0;
		const char* rd;
		while (i < 7)
		{
			if (maxValueOfRomanDigits[i] > dec )
			{
				rd = maxRomanDigits[i-1];
			}
			i++;
		}
		return rd;
	}
	int getValueOfRomanDigit(char rd)
	{
		char romanDigits[7] = { 'I','V','X','L','C','D','M' };
		int valueOfRomanDigits[7] = { 1,5,10,50,100,500,1000 };
		int i = 0;
		while (i < 7)
		{
			if (romanDigits[i] == rd)
			{
				return valueOfRomanDigits[i];
			}
			i++;
		}
		if (rd == '\0')
		{
			return 0;
		}
	}
	bool isValidRomanNumber(const char* rn)
	{
		bool validStatus = true;
		bool minAtLeft = false;
		int i = 0;
		int min = ((rn[0] > rn[1])&&(rn[1]!='\0')) ? rn[1] : rn[0];
		if (min == rn[1])
		{
			minAtLeft = true;
		}
		while ((validStatus) && (rn[i] != '\0'))
		{
			if (getValueOfRomanDigit(romanNumber[i]) < getValueOfRomanDigit(romanNumber[i + 1]))
			{
				min = getValueOfRomanDigit(romanNumber[i ]);
				minAtLeft = true;
			}
			if (((rn[i] == 'I') || (rn[i] == 'V') || (rn[i] == 'X') || (rn[i] == 'L') || (rn[i] == 'C') || (rn[i] == 'D') || (rn[i] == 'M')))
			{
				if ((getValueOfRomanDigit(rn[i]) <= (getValueOfRomanDigit(min) * 10)))
				{
					validStatus = true;
				}
				else
				{
					validStatus = false;
				}
			}
			else
			{
				validStatus = false;
			}
			i++;
		}
		return validStatus;
	}
public:
	int getDecimalNumber()
	{
		return decimalNumber;
	}
	const char* getRomanNumber()
	{
		return romanNumber;
	}
	void setDecimalNumber(int num)
	{
		if (num >= 0)
		{
			decimalNumber = num;
		}
		convertDecimalNumberToRoman();
	}
	void setRomanNumber(const char* rn)
	{
		if (isValidRomanNumber(rn))
		{
			copyCharArray(rn, romanNumber);
		}
		convertRomanNumberToDecimal();
	}
};
int main()
{
	RomanNumeral test;
	test.setDecimalNumber(0);
	cout<< test.getDecimalNumber()<<'\n';
	cout << test.getRomanNumber();
}
void copyCharArray(const char* src, char* tar)
{
	int i = 0;
	while (src[i] != '\0')
	{
		tar[i] = src[i];
		i++;
	}
	tar[i] = '\0';
}