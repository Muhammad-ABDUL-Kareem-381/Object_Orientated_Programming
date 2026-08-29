#include<iostream>
using namespace std;
class RomanNumeral
{
	char romanNumber[100];
	int decimalNumber;
	int getLengthOfGivenString(const char* ref)
	{
		int num = 0;
		while (ref[num]!='\0')
		{
			num++;
		}
		return num;
	}
	int getDecimalNumberOfRomanNumber(const char ref)
	{
		if (ref == 'M')
		{
			return 1000;
		}
		else if (ref == 'D')
		{
			return 500;
		}
		else if (ref == 'C')
		{
			return 100;
		}
		else if (ref == 'L')
		{
			return 50;
		}
		else if (ref == 'X')
		{
			return 10;
		}
		else if (ref == 'V')
		{
			return 5;
		}
		else if (ref == 'I')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	bool isFirstNumeralLower(char ref1, char ref2)
	{
		if (ref1 == 'D' || ref1 == 'M')
		{
			if (ref2 == 'C')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (ref1 == 'L' || ref1 == 'C')
		{
			if (ref2 == 'X')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (ref1 == 'X' || ref1 == 'V')
		{
			if (ref2 == 'I')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	void convertRomanNumberToDecimal()
	{
		int tempNum = 0,length = 0;
		char tempChar1 = '\0', tempchar2 = '\0';
		length = getLengthOfGivenString(romanNumber);
		for (int i = (length - 1); i >=0; i--)
		{
			tempchar2 = romanNumber[i];
			if (isFirstNumeralLower(tempChar1,tempchar2))
			{
				tempNum = tempNum - getDecimalNumberOfRomanNumber(tempchar2);
			}
			else
			{
				tempNum = tempNum + getDecimalNumberOfRomanNumber(tempchar2);
			}
			tempChar1 = tempchar2;
		}
		decimalNumber = tempNum;
	}
	const char* getRomanNumeral(int& temp)
	{
		if (temp >= 1000)
		{
			temp = temp - 1000;
			return "M";
		}
		else if (temp >= 900)
		{
			temp = temp - 900;
			return "CM";
		}
		else if (temp >= 500)
		{
			temp = temp - 500;
			return "D";
		}
		else if (temp >= 400)
		{
			temp = temp - 400;
			return "Cd";
		}
		else if (temp >= 100)
		{
			temp = temp - 100;
			return "C";
		}
		else if (temp >= 90)
		{
			temp = temp - 90;
			return "XC";
		}
		else if (temp >= 50)
		{
			temp = temp - 50;
			return "L";
		}
		else if (temp >= 40)
		{
			temp = temp - 40;
			return "XL";
		}
		else if (temp >= 10)
		{
			temp = temp - 10;
			return "X";
		}
		else if (temp >= 9)
		{
			temp = temp - 9;
			return "IX";
		}
		else if (temp >= 5)
		{
			temp = temp - 5;
			return "V";
		}
		else if (temp >= 4)
		{
			temp = temp - 4;
			return "IV";
		}
		else
		{
			temp = temp - 1;
			return "I";
		}
	}
	void convertDecimalNumberToRoman()
	{
		int tempNum = decimalNumber,index = 0,count = 0;
		while (tempNum>0)
		{
			const char* ref =getRomanNumeral(tempNum);
			while (ref[index]!='\0')
			{
				romanNumber[count] = ref[index];
				index++;
				count++;
			}
			romanNumber[count] = '\0';
			index = 0;
		}
	}
public:
	RomanNumeral()
	{
		decimalNumber = 0;
		strcpy_s(romanNumber, "\0");
	}
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
		decimalNumber = num;
		convertDecimalNumberToRoman();
	}
	void setRomanNumber(const char* rn)
	{
		strcpy_s(romanNumber, rn);
		convertRomanNumberToDecimal();
	}
};
int main()
{
	RomanNumeral r;
	//r.setRomanNumber("CMCMCMCM");
	r.setDecimalNumber(200);
	cout << r.getDecimalNumber() <<"\n";
	cout << r.getRomanNumber();
	
}