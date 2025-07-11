#include "String.h"
String::String()
{
	//cout << "String() " << endl;
	data = nullptr;
	size = 0;
}
String::String(const char c) :String()
{
	data = new char[2];
	size = 2;
	data[0] = c;
	data[1] = '\0';
	//cout << "String(const char c) " << endl;
}
String::String(const char * s) :String()
{
	size = getCharArrayLength(s) + 1;
	data = new char[size];
	myMemCpy(data,s,getLength());
	data[size - 1] = '\0';
	//cout << "String(const char * s) " << endl;
}
String::String(const String & s) :String()
{
	int length = s.getLength();
	size = length +1;
	data = new char[size];
	myMemCpy(data, s.data, length);
	data[length] = '\0';
	//cout << "String(const char & s) " << endl;
}
String::~String()
{
	delete[] data;
	size = 0;
	data = nullptr;
	//cout << "~String() " << endl;
}
void String::copyStr(const String& s)
{
	int length = s.getLength();
	size = length + 1;
	data = new char[size];
	myMemCpy(data, s.data, length);
	data[length] = '\0';
}
int String::getLength() const
{
	int i = 0;
	while (data[i] != '\0')
	{
		i++;
	}
	//cout << "getLength() " << endl;
	return i;
}
int String::getSize() const
{
	return size;
}
int String::getCharArrayLength(const char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	//cout << "getCharArrayLength(const char * s) " << endl;
	return i;
}
void String::input()
{
	setSize(5);
	data = new char[size];
	char temp;
	int i = 0;
	cin.get(temp);
	if (temp != '\n')
	{
		data[0] = temp;
		i++;
	}
	while (temp != '\n')
	{
		cin.get(temp);
		if (temp != '\n')
		{
			data[i] = temp;
			i++;
			if (i == size)
			{
				resize(size + 5);
			}
		}
	}
	if (i < size)  // This condition statement is for placing null character at end of string array.
	{
		data[i] = '\0';
	}
	else
	{
		resize(size + 1);
		data[i] = '\0';
	}
	shrink();
	//cout << "input() " << endl;
}
void String::resize(int newSize)
{
	char * tempData = new char[newSize];
	//myMemCpy(tempData, data, newSize);
	int i = 0;
	while ((i < newSize) && (data[i] != '\0'))
	{
		tempData[i] = data[i];
		i++;
	}
	*(tempData + i) = '\0';   // This statement is equal to tempData[i] = '\0';
	setSize(newSize);
	delete[] data;
	data = tempData;
	//cout << "resize(int newSize) " << endl;
}
void String::shrink()
{
	if ((size - getLength()) > 1)
	{
		resize(getLength() + 1);  //1 is added in length to provide an index for placing null character.
	}
	//cout << "shrink() " << endl;
}
void String::display() const
{
	//cout<<data;
	int i = 0;
	while ((i < size) && (data[i] != '\0'))
	{
		cout << (char)(data[i]);
		i++;
	}
	//cout << "display() " << endl;
}
char& String::at(const int index)
{
	//cout << "at(const int index) " << endl;
	return data[index];
}
//const char& String::at(const int index) const
//{
//	cout << "at(const int index) const " << endl;
//	return data[index];
//}
bool String::isEmpty() const
{
	if (!data)     //It means if data is nullptr then retrun true (i.e. yea it is empty).
	{
		//cout << "isEmpty() " << endl;
		return true;
	}
	else if (data[0] == '\0')
	{
		//cout << "isEmpty() " << endl;
		return true;
	}
	else
	{
		//cout << "isEmpty() " << endl;
		return false;
	}
}
int String::find(const String& subStr, const int start) const
{
	int j = start, i;
	int requiredIndex = -1;
	int len = getLength();
	int subStrLength = subStr.getLength();
	while (j < len)
	{
		i = start;
		if (data[j] == subStr.data[0])
		{
			requiredIndex = j;
			int subStrIndex = 1;
			j++;
			while ((subStrIndex < subStrLength) && (j < len && data[j] == subStr.data[subStrIndex]))
			{
				j++;
				subStrIndex++;
			}
			if (subStrIndex != subStrLength)
			{
				requiredIndex = -1;
				while (i < len && subStrIndex < subStrLength && data[i] == subStr.data[subStrIndex])
				{
					i++;
					subStrIndex++;
				}
			}
			else
			{
				return requiredIndex;
			}
		}
		j++;
	}
	//cout << "find(const String& subStr, const int start) " << endl;
	return requiredIndex;
}
void String::trimLeft()
{
	int i = 0;
	int len = getLength();
	while ((i < len) && ((data[i] == ' ') || (data[i] == '\n') || (data[i] == '\t')))
	{
		i++;
	}
	myMemCpy(data, &(data[i]), len-i+1);
	shrink();
	//cout << "trimLeft() " << endl;
}
void String::trimRight()
{
	int i = getLength() - 1;
	while (i >= 0 && (data[i] == ' ' || data[i] == '\n' || data[i] == '\t'))
	{
		i--;
	}
	data[i + 1] = '\0';
	shrink();
	//cout << "trimRight() " << endl;
}
void String::trim()
{
	trimRight();
	trimLeft();
	//cout << "trim() " << endl;
}
void String::insert(const int index, const String& subStr)
{
	int len = getLength();
	int subStrlen = subStr.getLength();
	if (!((len + subStrlen + 1) <= size))
	{
		resize(len + subStrlen + 1);
	}
	myMemCpy(&(data[index+subStrlen]),&(data[index]), len-index);
	myMemCpy(&(data[index]), &(subStr.data[0]), subStrlen);
	data[len + subStrlen] = '\0';
	//cout << "insert(const int index, const String& subStr) " << endl;
}
void myMemCpy(void* dest, const void* src, int byteCount)
{
	int i;
	char* d = (char*)dest;
	const char* s = (const char*)src;
	if ((unsigned long long int)(&(d[byteCount - 1]) - (unsigned long long int)(s)))
	{
		for (i = 0 ; i < byteCount; i++)
		{
			d[i] = s[i];
		}
	}
	//cout << "myMemCpy(void* dest, const void* src, int byteCount) " << endl;
}
void String::remove(const int index, const int count )
{
	if (!((index < getLength())&&(index>=0)))
		return;
	myMemCpy(&(data[index]), &(data[index + count]), getLength()-count-index);  //here 3rd argument is not suitable.
	data[getLength() - count] = '\0';
	shrink();
	//cout << "remove(const int index, const int count ) " << endl;
}
int String::compare(const String& s2) const
{
	int len1 = getLength();
	int len2 = s2.getLength();
	int smallerLength = len1 > len2 ? len2 : len1;
	bool equalSt = true;
	int i = 0;
	while ((i < smallerLength) && (equalSt))
	{
		if (data[i] != s2.data[i])
		{
			equalSt = false;
		}
		i++;
	}
	//int largerLength= len1 < len2 ? len2 : len1;
	if (equalSt)
	{
		if (len1 == len2)
		{
			return 0;
		}
		else
		{
			if (len1 < len2)
				return -1;
			else
				return 1;
		}
	}
	else
	{
		i--;
		if ((char)(data[i]) > (char)(s2.data[2]))
			return 1;
		else
			return - 1;
	}
	//cout << "String::compare(const String& s2) " << endl;
}
bool String::operator > (const String& s2) const
{
	return compare(s2) == 1 ? true : false;
}
bool String::operator < (const String& s2) const
{
	return compare(s2) == -1 ? true : false;
}
bool String::operator == (const String& s2) const
{
	return compare(s2) == 0 ? true : false;
}
void String::makeUpper()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - ('a' - 'A');
		}
	}
	//cout << "makeUpper() " << endl;
}
void String::makeLower()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + ('a' - 'A');
		}
	}
	//cout << "makeLower() " << endl;
}
void String::reverse()
{
	int len = getLength();
	for (int i = 0; i < len/ 2; i++)
	{
		mySwap(&(data[i]), &(data[len - i-1]));
	}
	//cout << "reverse() " << endl;
}
void mySwap(char* a, char* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	//cout << "mySwap(char* a, char* b) " << endl;
}
void Swap(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	//cout << "Swap(int a, int b) " << endl;
}
String String::left(const int count)
{
	String st{ *this };
	st.resize(count+1);
	st.data[count] = '\0';
	//cout << "left(const int count)" << endl;
	return st;
}
String String::right(const int count)
{
	String st{ *this };
	st.resize(count + 1);
	myMemCpy(st.data, &(data[getLength() - count]), count);
	st.data[count] = '\0';
	//cout << "right(const int count) "<<endl;
	return st;
}
int String::replace(const String& old, const String& newSubStr)
{
	int occurences = 0;
	int start = 0;
	int destIndex;
	while (start < getLength())
	{
		if (find(old) != -1)
		{
			destIndex = find(old, start);
			myMemCpy(&(data[destIndex]), newSubStr.data, newSubStr.getLength());
			occurences++;
			start += newSubStr.getLength();
		}
		else
		{
			start++;
		}
	}
	//cout << "replace(const String& old, const String& newSubStr) " << endl;
	return occurences;
}
String String::concatenate(const String & s2) const
{
	int length = getLength() + s2.getLength();
	String resultingSt{*this};
	resultingSt.resize(length + 1);
	myMemCpy(&(resultingSt.data)[getLength()], s2.data, s2.getLength());
	resultingSt.data[length] = '\0';
	//cout << "concatenate(const String & s2) const " << endl;
	return resultingSt;
}
void String::concatEqual(const String& s2)
{
	int len = getLength();
	int len2 = s2.getLength();
	if ((size - len) <len2)
	{
		resize(len + len2+1);
	}
	myMemCpy(&(data[len]), &(s2.data[0]), len2);
	data[size - 1] = '\0';
	//cout << "concatEqual(const String& s2) " << endl;
}
long long int String::convertToInteger() const
{
	long long int num=0;
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			num =  num*10 + (int)(data[i] - '0');
		}
	}
	//cout << "\nconvertToInteger() ";
	//cout << "convertToInteger() const " << endl;
	return num;
}
float String::convertToFloat() const
{
	float num1 = 0;
	int i = 0;
	while ( i < getLength() && data[i] != '.')
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			num1 = num1 * 10 + (int)(data[i] - '0');
		}
		i++;
	}
	int noOfFractionalPartIntigers = getLength() - i-1;
	float num2 = 0.0;
	while (i < getLength())
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			num2 = num2 * 10 + (int)(data[i] - '0');
		}
		i++;
	}
	//cout << "convertToFloat() const " << endl;
	return ((num1 ) + (float)(num2 * pow(0.1, noOfFractionalPartIntigers)));
}
void String::setSize(const int s)
{
	size = s;
	//cout << "setSize(const int s) " << endl;
}
int String::lengthOfIntegralNum(const long long int num)
{
	if (num == 0)
		return 1;
	long long int number = num;
	int i = 0;
	while (number)
	{
		number = number / 10;
		i++;
	}
	//cout << "lengthOfIntegralNum(const long long int num) " << endl;
	return i;
}
void String::setNumber(const long long int num)
{
	bool negativeNumStatus = false;
	if (num < 0)
	{
		negativeNumStatus = true;
	}
	if (negativeNumStatus)
	{
		setSize(lengthOfIntegralNum(num) + 2);  //one extra index to place '-
	}
	else
	{
		setSize(lengthOfIntegralNum(num) + 1);
	}

	data = new char[size];
	int number = num;
	if (negativeNumStatus)
	{
		number *= -1;    //to make number +ve to get +ve answer of modulus
	}
	int digit = number % 10;
	number = number / 10;
	int i = 0;
	do
	{
		*(data +i) = (char)digit + '0';
		i++;
		digit = number % 10;
		number = number / 10;
	}
	while (number);
	*(data + i) = (char)digit + '0';
	i++;
	if (((size - i) ==2) && (negativeNumStatus) )
	{
		data[size-2] = '-' ; //data[size - 2] =data[i]
	}
	data[size - 1] = '\0';
	reverse();
	//cout << "setNumber(const long long int num) " << endl;
}