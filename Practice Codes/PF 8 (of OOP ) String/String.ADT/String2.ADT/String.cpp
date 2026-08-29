#include "String.h"
String::String()
{
	data = nullptr;
	size = 0;
	cout << "String()\n";
}
String::String(const char c) :String()
{
	cout << "String(const char)\n";
	if (!c)
	{
		size = 1;
		data = new char{ '\0' };   // same as data=new char [1] {'\0'};
		return;
	}
	size = 2;
	data = new char[size] {c, '\0'};
	//data[0] = c;
	//data[1] = '\0';
}
String::String(const char* ch) : String()
{
	cout << "String(const char * )\n";
	if (ch)
	{
		size = getStrLen(ch) + 1;
		data = new char[size];
		copyCharArray(ch, data);
	}
}
String::String(const String& ref) :String()
{
	cout << "String(const String& ) \n";
	if (!ref.data || ref.size == 0)
	{
		return;
	}
	size = ref.size;
	data = new char[size];
	copyCharArray(ref.data, data);
}
String::String(String&& ref): String()
{
	cout << "String(String&& )  move ctor \n";
	if (this == &ref)   //to save from s1 = (move)s1; ie. movement of resources in itself as below used destructor will make dangle data (a data member ) of ref obj which is also calling obj coz both obj are same.
	{
		return;
	}
	if (!ref.data)
	{
		return;
	}
	this->~String();
	size = ref.size;
	data = ref.data;   // now data member data of both Strings now  point the same char array.
	ref.size = 0;
	ref.data = nullptr;   // Now break the connection of char array with data member data 0of old String by making it nullptr.
	// in this way now that array is pointed by data ( a data member) of only new String. Connection with old String is break down .
	// And so resource i.e. heap memory array is moved / shifted from one String to other.
}
int String::getLength() const
{
	return (getStrLen(data));
}
bool String::isValidIndex(const int index) const
{
	cout << "len: " << getLength();
	if (data && (index >= 0) && (index < getLength()))
	{
		return true;
	}
	return false;
}
bool String::isStringASignedNumber() const
{
	return (data[0] == '-' || data[0] == '+');
}
bool String::isStringANegativeNumber() const
{
	if (!isStringAFloatNumber())   // yani pehly dekh lein k String aik number b  ya nhi h?
	{
		exit(0);
	}
	return (data[0] == '-');
}
bool String::isStringAFloatNumber() const
{
	if (!data)
	{
		return false;
	}
	bool floatStatus = true;
	int length = getLength();
	int i = 0;
	bool decimalPointStatus = false;
	if (isStringASignedNumber())
	{
		i++;
	}
	while (i < length && floatStatus)
	{
		if (data[i] == '.' && !decimalPointStatus)
		{
			decimalPointStatus = true;
		}
		else if (data[i] >= '0' && data[i] <= '9')
		{
			i++;    // this increment in i is necessary here coz due to continue statement control will not go to i++; which after else statement. instead it will go for a new loop/cycle.
			continue;
		}
		else
		{
			floatStatus = false;
		}
		i++;
	}
	return floatStatus;
}
bool String::isStringAnIntegralNumber() const
{
	if (!data)
	{
		return false;
	}
	int i = 0;
	if (!((data[i] >= '0' && data[i] <= '9') || (data[i] == '+' || data[i] == '-')))   //to check 1st character. it may be sign ie + or -.
	{
		return false;
	}
	i++;
	while (data[i])
	{
		if (!(data[i] >= '0' && data[i] <= '9'))
		{
			return false;
		}
		i++;
	}
	return true;
}
int String::getStrLen(const char* ch)
{
	int i = 0;
	while (ch[i])
	{
		i++;
	}
	return i;
}
void String::copyCharArray(const char* src, char* dest)
{
	int i = 0;
	if (!src)
	{
		dest[0] = '\0';
		return;
	}
	while (src[i])
	{
		//cout << i << '\t';
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
void String::swapCharacters(char& a, char& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void String::myMemMove(void* src, void* dest, int byteCount)
{
	const char* s = (const char*)src;
	char* d = (char*)dest;
	for (int i = byteCount - 1; i >= 0; i--)
	{
		d[i] = s[i];
	}
}
void String::input()
{
	if (!data || size <= 0)
	{
		reSize(10);
	}
	char temp;
	int i = 0;
	while (cin.get(temp) && temp != '\n')
	{
		if (i == (size - 1))
		{
			reSize(size + 10);
		}
		data[i] = temp;
		i++;
	}
	data[i] = '\0';
	shrink();
}
void String::display() const
{
	if (data)
	{
		cout << data;
	}
}
char& String::operator [](const int index)
{
	/*if (!data)
	{
		exit(0);
	}*/
	if (index >= 0 && index < size)
	{
		return data[index];
	}
	exit(0);
	//the function with return type const is to use as a setter 
	//so i should be allowed to place a char within size anywhere ie within length or out the length both.
	// like String s1{"Ali"}; 
	// s1.reSize(5);
	//s1.at(3)='z';
	//s1.at(4)='\0';
	// so in this case index of at(3) and at(4) ie 3 & 4 is outside length
	// so bound checking will be with size , not with length otherwise at() will not work.
	// bound checking with length will be in const char & at(int) const where i just want to access the char 
}
const char& String::operator [](const int index) const
{
	if (!isValidIndex(index))
	{
		exit(0);
	}
	return data[index];
}
bool String::operator !() const
{
	if ((!data) || (!getLength()))
	{
		return true;
	}
	return false;
}
int String::getSize() const
{
	return size;
}
void String::reSize(int newSize)
{
	if (!(newSize > 0))
	{
		this->~String();
		return;
	}
	char* temp = new char[newSize];
	copyCharArray(data, temp);
	//delete[] data;
	this->~String();
	size = newSize;
	data = temp;
}
int String::findNoOfOccurences(String subStr, const int start ) const   //it will tell the no. of occuerneces of substr in String
{
	int count = 0, startingIndex = start;
	int strLen = getLength();
	int subStrLen = subStr.getLength();
	bool equalStatus = false;
	for (; startingIndex < strLen; )
	{
		int j = 0;
		do
		{
			if (data[startingIndex] == subStr.data[j])
			{
				equalStatus = true;
				j++;
			}
			else
			{
				equalStatus = false;
			}
			startingIndex++;
		} while ((j < subStrLen) && (equalStatus));
		if ((j == subStrLen) && (equalStatus))
		{
			count++;
		}
	}
	return count;
}
int String::findIndex(String* subStr) const  //find index of subStr's 1st character in 1st its occurrence String.
{
	int index = -1;
	int strLen = getLength();
	int subStrLen = subStr->getLength();
	bool equalStatus = false;
	for (int i = 0; i < strLen; )
	{
		int j = 0;
		do
		{
			if (data[i] == subStr->data[j])
			{
				equalStatus = true;
				j++;
			}
			else
			{
				equalStatus = false;
			}
			i++;
		} while ((j < subStrLen) && (equalStatus));
		if ((j == subStrLen) && (equalStatus))
		{
			return (i - j);
		}
	}
	return -1;
}
void String::remove(const int index, const int count )
{
	int strLen = getLength();
	if ((index + count) > strLen)
	{
		return;
	}
	int i = index;
	while ((i < (index + count)) && (data[i + count]))
	{
		data[i] = data[i + count];
		i++;
	}
	while (i < (strLen - count))
	{
		data[i] = data[i + count];
		i++;
	}
	data[i] = '\0';
	shrink();
}
void String::insert(const int index, const String& subStr)
{
	if ((!subStr.data) || (index >= getSize()))
	{
		return;
	}
	int subStrLen = subStr.getLength();
	int strLen = getLength();
	if (getSize() < (strLen + subStrLen + 1))
	{
		reSize(strLen + subStrLen + 1);
	}
	myMemMove(&(data[index]), &(data[index + subStrLen]), strLen - index);
	myMemMove(subStr.data, &(data[index]), subStrLen);
	//data[index+subStrLen]
	data[strLen + subStrLen] = '\0';
	shrink();
}
int String::replace(String old, String newSubStr)
{
	int strLen = getLength();
	int replaceCount = 0;   //replaceCount means no. of replacements of old String
	for (int i = 0; i < strLen; i++)
	{
		int index = findIndex(&old);
		if (index >= 0)
		{
			remove(index, old.getLength());
			insert(index, newSubStr);
			i = i + newSubStr.getLength() - 1; // subtract 1 coz after this block i++ of for loop will also execute.
			replaceCount++;
		}
		strLen = getLength();    //strLen is also changing due to removing and inserting characters in array of calling String.
	}
	return replaceCount;
}
int String::compare(const String& s2) const
{
	int strLenA = getLength();
	int strLenB = s2.getLength();
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
		bool equalStatus = true;
		int i = 0;
		while ((i < strLenA) && equalStatus)
		{
			if (data[i] == s2.data[i])
			{
				equalStatus = true;
				i++;
			}
			else
			{
				equalStatus = false;
			}
		}
		if (!equalStatus)
		{
			if (data[i] > s2.data[i])
			{
				return 1;
			}
			return -1;
		}
		return 0;
	}
}
void String::makeUpper()
{
	int strLen = getStrLen(data);
	for (int i = 0; i < strLen; i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - ('a' - 'A');
		}
	}
}
void String::makeLower()
{
	int strLen = getStrLen(data);
	for (int i = 0; i < strLen; i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + ('a' - 'A');
		}
	}
}
void String::reverse()
{
	int strLen = getLength();
	for (int i = 0; i < (strLen / 2); i++)
	{
		swapCharacters(data[i], data[strLen - i - 1]);
	}
}
void String::trimRight()
{
	int i = getLength() - 1;
	while (data[i] == ' ' || data[i] == '\n' || data[i] == '\t')
	{
		i--;
	}
	i = i + 1;
	data[i] = '\0';
	shrink();
}
void String::trimLeft()
{
	int i = 0;
	while (data[i] == ' ' || data[i] == '\n' || data[i] == '\t')
	{
		i++;
	}
	remove(0, i);
	shrink();
}
void String::trim()
{
	trimLeft();
	trimRight();
}
void String::shrink()
{
	reSize(getLength() + 1);
}
String String::left(const int count)   // why didn't we make this function const?
{
	if (!(data && (count <= getLength() && count >= 0)))   // >= with 0 so that left(0) will not execute exit(0). instead it will return empty String.
	{
		exit(0);
	}
	String st{ *this };
	st.data[count] = '\0';
	st.shrink();
	return st;
}
String String::right(const int count)
{
	if (!(data && (count >= 0 && count <= getLength())))  // >= with 0 coz we do not want to execute exit(0) at right(0). that's why....
	{
		exit(0);
	}
	String st{ "" };
	st.reSize(count + 1);
	copyCharArray(&(data[getLength() - count]), st.data);
	return st;
}
long long int String::convertToInteger() const
{
	if (!isStringAnIntegralNumber())
	{
		exit(0);
	}
	int i = 0;
	if (isStringASignedNumber())  // skip sign character while concatinating number
	{
		i++;
	}
	long long int num = 0;
	while (data[i])
	{
		num = num * 10 + data[i] - '0';
		i++;
	}
	if (isStringANegativeNumber())
	{
		num = -1 * num;
	}
	return num;
}
float String::convertToFloat()
{
	if (!isStringAFloatNumber())
	{
		exit(0);
	}
	float num = 0;
	int i = 0, length = getLength();
	i = (isStringASignedNumber()) ? i + 1 : i;   // if number has + or - at 1st charcter , skip it while concatinating the number.
	while (i < length && data[i] != '.')     //concatination of integral part i.e. number before decimal point
	{
		num = num * 10 + (data[i] - '0');
		i++;
	}
	if (i == length)
	{
		return (isStringANegativeNumber()) ? num * (-1) : num;
	}
	i++;   //to skip decimal point (.) for concatination of number.
	float multiple = 0.1;
	while (i < length)
	{
		num = num + ((data[i] - '0') * multiple);
		multiple = multiple / 10.0;
		i++;
	}
	return (isStringANegativeNumber()) ? (-1) * num : num;
}
String String::operator +(const String& s2)
{
	if ((!data) || (!s2.data))
	{
		exit(0);
	}
	if (s2.getLength() == 0)
	{
		return *this;
	}
	String str{ *this };
	str.reSize(getLength() + s2.getLength() + 1);
	copyCharArray(s2.data, &((str.data)[getLength()]));
	/*int i = 0;
	while (s2.data[i])
	{
		cout << i << '\t';
		str.data[getLength()+i] = s2.data[i];
		i++;
	}
	str.data[getLength() + i] = '\0';*/
	return str;
}
void String::operator += (const String& s2)
{
	if (!data || !s2)
	{
		return;
	}
	if (size < (getLength() + s2.getLength() + 1))
	{
		reSize(getLength() + s2.getLength() + 1);
	}
	copyCharArray(s2.data, &(data[getLength()]));
}
void String::setNumber(const long long int num)
{
	if (!data)
	{
		size = 10;
		data = new char[size];
	}
	long long int temp = num;
	if (num < 0)
	{
		temp = -1 * temp;
	}
	int i = 0;
	while (temp)
	{
		if (!(i < size))
		{
			reSize(size + 10);
		}
		data[i] = (temp % 10) + '0';
		temp = temp / 10;
		i++;
	}
	if (num < 0)
	{
		data[i] = '-';
		i++;
	}
	if (num == 0)
	{
		data[i] = '0';
		i++;
	}
	data[i] = '\0';
	shrink();
	reverse();
}
String& String::operator = (const String& ref)
{
	cout << "String & operator = (const String & ref)\n";
	if (this == &ref)
	{
		return *this;
	}
	if (!ref.data || ref.size == 0)
	{
		exit(0);
	}
	this -> ~String();
	size = ref.size;
	data = new char[size];
	copyCharArray(ref.data, data);
	return *this;
}
String& String::operator =(String&& ref)
{
	cout << "String & operator = (String && ref)\n";
	if (this == &ref)   //to save from s1 = (move)s1; ie. movement of resources in itself as below used destructor will make dangle data (a data member ) of ref obj which is also calling obj coz both obj are same.
	{
		return *this;
	}
	if (!ref.data)
	{
		exit(0);
	}
	this->~String();
	size = ref.size;
	data = ref.data;	 // now data member data of both Strings now  point the same char array.
	ref.size = 0;
	ref.data = nullptr;
	return *this;
}
String::~String()
{
	if (!data)
	{
		return;
	}
	delete[] data;
	data = nullptr;
	size = 0;
}