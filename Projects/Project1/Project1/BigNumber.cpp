#include"BigNumber.h"
void BigNumber::copyArray(char* dest, const char* sour, int size) const
{
	if (checkForNullPointer(dest)==true)
	{
		return;
	}
	if (checkForNullPointer(sour)==true||checkForNullCharacter(sour)==true)
	{
		dest[0] = '\0';
		return;
	}
	int i = 0;
	while (i<size-1)
	{
		dest[i] = sour[i];
		i++;
	}
	dest[i] = '\0';
}
void BigNumber::createArray(char*& a, int size) const
{
	a = new char[size];
}




BigNumber::BigNumber()
{
	number = nullptr;
	numberLength = 0;
}
BigNumber::BigNumber(const char* a) : BigNumber()
{
	if (checkForNullPointer(a)==true||checkForNullCharacter(a)==true)
	{
		return;
	}
	numberLength = getLength(a);
	createArray(number, numberLength+1);
	copyArray(number, a, numberLength+1);
}
BigNumber::BigNumber(const BigNumber& ref) : BigNumber()
{
	if (checkForNullPointer(ref.number) == true || checkForNullCharacter(ref.number) == true)
	{
		return;
	}
	numberLength = ref.numberLength;
	createArray(number, numberLength + 1);
	copyArray(number, ref.number, ref.numberLength + 1);
}
BigNumber::~BigNumber()
{
	if (checkForNullPointer(number) == true || checkForNullCharacter(number) == true)
	{
		return;
	}
	delete[]number;
	number = nullptr;
	numberLength = 0;
}
void BigNumber::print() const
{
	if (checkForNullPointer(number) == true || checkForNullCharacter(number) == true)
	{
		cout << 0;
		return;
	}
	cout << number;
}
Comparison BigNumber::compare(const BigNumber & other) const
{
	if ((checkForNullPointer(other.number) == true || checkForNullCharacter(other.number) == true) && (checkForNullPointer(number) == true || checkForNullCharacter(number) == true))
	{
		return EQUAL;
	}
	if ((checkForNullPointer(other.number) == true || checkForNullCharacter(other.number) == true) && (checkForNullPointer(number) == false || checkForNullCharacter(number) == false))
	{
		return LARGE;
	}
	if ((checkForNullPointer(other.number) == false || checkForNullCharacter(other.number) == false) && (checkForNullPointer(number) == true || checkForNullCharacter(number) == true))
	{
		return SMALL;
	}
	unsigned long long int a1 = 0, b1 = 0, c1 = 0;
	for (int i = 0; number[i] != '\0'; i++)
	{
		a1 = a1 * 10;
		a1 = a1 + (number[i] - '0');
	}
	for (int i = 0; other.number[i] != '\0'; i++)
	{
		b1 = b1 * 10;
		b1 = b1 + (other.number[i] - '0');
	}
	if (a1 == b1)
	{
		return EQUAL;
	}
	if (a1 > b1)
	{
		return LARGE;
	}
	if (a1 < b1)
	{
		return SMALL;
	}
}
BigNumber BigNumber::add(const BigNumber& other) const
{
	if ((checkForNullPointer(other.number) == true || checkForNullCharacter(other.number) == true) && (checkForNullPointer(number) == true || checkForNullCharacter(number) == true))
	{
		return*this;
	}
	if ((checkForNullPointer(other.number) == true || checkForNullCharacter(other.number) == true) && (checkForNullPointer(number) == false || checkForNullCharacter(number) == false))
	{
		return*this;
	}
	if ((checkForNullPointer(other.number) == false || checkForNullCharacter(other.number) == false) && (checkForNullPointer(number) == true || checkForNullCharacter(number) == true))
	{
		return other;
	}
	BigNumber add;
	int num1 = 0, num2 = 0, sum = 0, carry = 0, maxLength=0, length1 = numberLength, length2 = other.numberLength;
	maxLength = (numberLength > other.numberLength) ? numberLength : other.numberLength;
	createArray(add.number, maxLength + 1);
	add.numberLength = maxLength;
	add.number[add.numberLength] = '\0';
	for (int i = add.numberLength; i > 0; i--)
	{
		if (length1>=1&&number[length1-1]>='0'&&number[length1-1]<='9')
		{
			num1 = (number[length1 - 1] - '0');
		}
		else
		{
			num1 = 0;
		}
		if (length2>=1 && other.number[length2-1] >= '0' && other.number[length2-1] <= '9')
		{
			num2 = (other.number[length2 - 1] - '0');
		}
		else
		{
			num2 = 0;
		}
		sum = num1 + num2 + carry;
		add.number[i - 1] = ((sum % 10) + '0');
		if ((sum) >= 10)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		length1--;
		length2--;
	}
	if (carry==1)
	{
		BigNumber y;
		y.numberLength = add.numberLength + 1;
		createArray(y.number, y.numberLength + 1);
		y.number[0] = ('0' + carry);
		copyArray(&y.number[1], add.number,add.numberLength+1);
		add.~BigNumber();
		return y;
	}
	else
	{
		return add;
	}
}
void BigNumber::setNumber(const char* num)
{
	if (checkForNullPointer(num) == true )
	{
		this->~BigNumber();
		return;
	}
	if (checkForNullCharacter(num) == true)
	{
		number[0] = '\0';
		numberLength = 1;
		return;
	}
	int length=getLength(num);
	this->~BigNumber();
	numberLength = length;
	createArray(number, length+1);
	copyArray(number, num,numberLength+1);
}
BigNumber BigNumber::multiply(const BigNumber& other) const
{
	if ((checkForNullPointer(other.number) == true || checkForNullCharacter(other.number) == true) && (checkForNullPointer(number) == true || checkForNullCharacter(number) == true))
	{
		return*this;
	}
	if ((checkForNullPointer(other.number) == true || checkForNullCharacter(other.number) == true) && (checkForNullPointer(number) == false || checkForNullCharacter(number) == false))
	{
		return*this;
	}
	if ((checkForNullPointer(other.number) == false || checkForNullCharacter(other.number) == false) && (checkForNullPointer(number) == true || checkForNullCharacter(number) == true))
	{
		return*this;
	}
	BigNumber add{ "1" }, multiply{ "0" }, check{ "1" };
	while (check.compare(other)!=LARGE)
	{
		multiply.add(*this);
		check.add(add);
	}
	return multiply;

	
}
