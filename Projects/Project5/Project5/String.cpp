#include"string.h"
bool String::isValidIndex(const int index) const
{
	return (index >= 0 && index < size) ? true : false;
}
void String::mySwap(char* a, char* b)
{
	if (isNullPtr(a) == true || isNullCharacter(a[0]) == true || isNullPtr(b) == true || isNullCharacter(b[0]) == true)
	{
		return;
	}
	char temp = *a;
	*a = *b;
	*b = temp;
}
int String::giveResultOfComparingGivenStringsIndexValue(const char str1,const char str2) const
{
	if (str1<str2)
	{
		return -1;
	}
	else if (str1>str2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool String::isStringNegative() const
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return false;
	}
	if (data[0] == '-')
	{
		return true;
	}
	return false;
}
bool String::isStringPositive() const
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return false;
	}
	if (data[0] == '+')
	{
		return true;
	}
	return false;
}
int String::giveNumberLength(long long int& a)
{
	int length = 0;
	if (a==0)
	{
		length = 1;
	}
	else
	{
		if (a<0)
		{
			length++;
			a = a * -1;
		}
		while (a>0)
		{
			length++;
			a = a / 10;
		}
	}
	return length;
}









String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const String&ref) : String()
{
	if (isNullPtr(ref.data)==true || ref.size <= 0)
	{
		return;
	}
	size = ref.size;
	createString(data, size);
	copyStringByUsingLength(data, ref.data, ref.size);
}
String::String(const char c) : String()
{
	if ( isNullCharacter(c) == true )
	{
		size = 1;
		createString(data, size);
		data[0] = '\0';
		return;
	}
	size = 2;
	createString(data, size);
	data[0] = c;
	data[1] = '\0';
}
String::String(const char* c) : String()
{
	if (isNullPtr(c) == true)
	{
		return;
	}
	int count = giveLengthOfGivenString(c);
	size = count + 1;
	createString(data, size);
	copyString(data, c);
}
String::String(const long long int a)
{
	long long int temp = a;
	size = (giveNumberLength(temp) + 1);
	createString(data, (size));
	if (a == 0)
	{
		data[0] = '0';
		data[1] = '\0';
	}
	else
	{
		temp = a;
		if (a < 0)
		{
			data[size - 2] = '-';
			temp = temp * -1;
			for (int i = 0; i < size - 2; i++)
			{
				data[i] = '0' + (temp % 10);
				temp = temp / 10;
			}
		}
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				data[i] = '0' + (temp % 10);
				temp = temp / 10;
			}

		}
		data[size - 1] = '\0';
		reverse();
	}
}
void String::input()
{
	if (isNullPtr(data)==false)
	{
		this->~String();
	}
	char character;
	int count = 0,length=0;
	size = 2;
	createString(data, size);
	while (cin.get(character)&&character!='\n')
	{
		if (count==size-1)
		{
			length=size+1;
			reSize(length);
		}
		data[count] = character;
		count++;
	}
	data[count] = '\0';
}
void String::reSize(int newSize)
{
	if (newSize<=0)
	{
		this->~String();
		return;
	}
	if(isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return;
	}
	int limit = (newSize < size) ? newSize : size;
	char* temp;
	createString(temp, newSize);
	copyStringByUsingLength(temp, data, limit);
	this->~String();
	data = temp;
	size = newSize;
}
void String::display() const
{
	if (isNullPtr(data) == true)
	{
		return;
	}
	cout << data;
}
char& String::at(const int index)
{
	if (isNullPtr(data)==false && isNullCharacter(data[0]) == false && isValidIndex(index) == true)
	{
		return data[index];
	}
	exit(0);
}
const char& String::at(const int index) const
{
	if (isNullPtr(data) == false && isNullCharacter(data[0]) == false && isValidIndex(index) == true)
	{
		return data[index];
	}
	exit(0);
}
String::~String()
{
	if (isNullPtr(data)==true)
	{
		return;
	}
	delete[]data;
	data = nullptr;
	size = 0;
}
bool String::isEmpty() const
{
	return (isNullPtr(data) == true || isNullCharacter(data[0]) == true) ? true : false;
}
int String::getLength() const
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return 0;
	}
	return giveLengthOfGivenString(data);
}
int String::getSize() const
{
	return size;
}
int String::find(const String& subStr, const int start) const
{
	if (isNullPtr(data)==true || isNullCharacter(data[0]) == true || isNullPtr(subStr.data) == true || isNullCharacter(subStr.data[0]) == true)
	{
		return -1;
	}
	int length=subStr.getLength();
	for (int i = start; i <= size-length; i++)
	{
		int result = 0;
		for (int j = 0; j < length; j++)
		{
			if (data[i+j]==subStr.data[j])
			{
				result =result+ 1;
			}
		}
		if (result==length)
		{
			return i;
		}
	}
	return -1;
}
void String::insert(const int index, const String& subStr)
{
	if (isNullPtr(data)==true||isNullCharacter(data[0]) == true || isNullPtr(subStr.data) == true || isValidIndex(index) == false)
	{
		return;
	}
	char* temp;
	int newSize = size + subStr.getSize();
	createString(temp, newSize);
	copyString(temp,data);
	copyString(&temp[index], subStr.data);
	copyString(&temp[index+subStr.getLength()], &data[index]);
	this->~String();
	data = temp;
	size = newSize;
}
void String::remove(const int index, const int count)
{
	if (isNullPtr(data)==true|| isNullCharacter(data[0]) == true || isValidIndex(index) == false || isValidIndex(index + count) == false)
	{
		return;
	}
	size = size - count;
	copyString(&data[index], &data[index + count]);
}
int String::replace(const String& old, const String& newSubStr)
{
	if (isNullPtr(data)==true||isNullCharacter(data[0]) == true || isNullPtr(old.data) == true || isNullCharacter(old.data[0]) == true || isNullPtr(newSubStr.data) == true || isNullCharacter(newSubStr.data[0]) == true)
	{
		return 0;
	}
	int count = 0, index = 0;
	while (count<4)
	{

		index = find(old, index);
		remove(index, old.getLength());
		insert(index, newSubStr);
		index = index + newSubStr.getLength();
		count = count + 1;
	}
	return count;
}
void String::trimLeft()
{
	if (isNullPtr(data)==true||isNullCharacter(data[0]) == true)
	{
		return;
	}
	int count = 0, i = 0;
	while (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
	{
		count = count + 1;
		i++;
	}
	remove(0, count);
	size = size - count;
}
void String::trimRight()
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return;
	}
	int count = 0, i = (getLength()-1);
	while (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
	{
		count = count + 1;
		i--;
	}
	data[getLength() - count] = '\0';
	size = size - count;
}
void String::trim()
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return;
	}
	trimLeft();
	trimRight();
}
void String::makeUpper()
{
	if (isNullPtr(data)==true||isNullCharacter(data[0]) == true)
	{
		return;
	}
	for (int i = 0; i < size-1; i++)
	{
		if (data[i]>='a'&&data[i]<='z')
		{
			data[i] = data[i] - 32;
		}
	}
}
void String::makeLower()
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
	}
}
void String::reverse()
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return;
	}
	for (int i = 0,j = getLength()-1; i < j; i++,j--)
	{
		mySwap(&data[i], &data[j]);
	}
}
void String::shrink()
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return;
	}
	reSize(getLength() + 1);
} 
int String::compare(const String& s2) const
{
	if ((isNullPtr(data) == true || isNullCharacter(data[0]) == true) && (isNullPtr(s2.data) == true || isNullCharacter(s2.data[0]) == true))
	{
		return 0;
	}
	if ((isNullPtr(data) == true || isNullCharacter(data[0]) == true) && (isNullPtr(s2.data) == false || isNullCharacter(s2.data[0]) == false))
	{
		return -1;
	}
	if ((isNullPtr(data) == false || isNullCharacter(data[0]) == false) && (isNullPtr(s2.data) == true || isNullCharacter(s2.data[0]) == true))
	{
		return 1;
	}
	int index = 0;
	while (isNullCharacter(data[index])==false&&isNullCharacter(s2.data[index])==false&&data[index]==s2.data[index])
	{
		index++;
	}
	return giveResultOfComparingGivenStringsIndexValue(data[index], s2.data[index]);
}
String String::left(const int count)
{
	if (isNullPtr(data)==true||isNullCharacter(data[0]) == true || isValidIndex(count) == false)
	{
		return *this;
	}
	String a;
	int length = (count < size) ? count : size;
	a.size = length + 1;
	createString(a.data, a.size);
	copyStringByUsingLength(a.data, data, a.size);
	return a;
}
String String::right(const int count)
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true || isValidIndex(count) == false)
	{
		return *this;
	}
	String a;
	int length = (count < size) ? count : size;
	a.size = length + 1;
	createString(a.data, a.size);
	copyStringByUsingLength(a.data, &data[getLength() - count], a.size);
	return a;
}
long long int String::convertToInteger() const
{
	if (isNullPtr(data)==true||isNullCharacter(data[0]) == true)
	{
		return 0;
	}
	int index = 0;
	int sign = 1;
	if (isStringNegative()==true)
	{
		sign = -1;
		index = 1;
	}
	if (isStringPositive()==true)
	{
		index = 1;
	}
	long long int number = 0;
	for (int i = index; data[i]!='\0'; i++)
	{
		if (data[i]>='0'&&data[i]<='9')
		{
			number = number * 10;
			number = number + (long long int)(data[i] - '0');
		}
		else
		{
			return number*sign;
		}
	}
	return number*sign;
}
float String::convertToFloat() const
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return 0.0;
	}
	int index1 = 0, index2 = 0,length=0;
	float sign = 1.0;
	if (isStringNegative() == true)
	{
		sign = -1.0;
		index1 = 1;
	}
	if (isStringPositive() == true)
	{
		index1 = 1;
	}
	bool alreadyFind = false;
	float num=0.0;
	for (int i = index1; data[i] != '\0'; i++)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			num = num * 10;
			num = num + (data[i] - '0');
			length = length + 1;
			cout << num << "\n";
		}
		else if (data[i]=='.' && alreadyFind==false)
		{
			index2 = i;
			alreadyFind = true;
		}
		else
		{
			if (alreadyFind==true)
			{
				for (int j = 0; j < (length - index2); j++)
				{
					num = num / 10;
				}
			}
			return num * sign;
		}
	}
	if (alreadyFind == true)
	{
		for (int j = 0; j < (length - index2); j++)
		{
			num = num / 10;
		}
	}
	return num * sign;
}
String String::concatenate(const String& s2) const
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true || isNullPtr(s2.data) == true || isNullCharacter(s2.data[0]) == true)
	{
		return *this;
	}
	String a;
	a.size = size + s2.size;
	createString(a.data, a.size);
	copyStringByUsingLength(a.data, data, size);
	copyStringByUsingLength(&a.data[size - 1], s2.data, s2.size);
	return a;
}
void String::concatEqual(const String& s2)
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true || isNullPtr(s2.data) == true || isNullCharacter(s2.data[0]) == true)
	{
		return ;
	}
	int length = s2.getLength();
	reSize(size+s2.getLength());
	copyStringByUsingLength(&data[getLength()], s2.data, s2.getSize());
}
void String::setNumber(const long long int a)
{
	this->~String();
	long long int temp = a;
	size = (giveNumberLength(temp) + 1);
	createString(data, (size));
	if (a == 0)
	{
		data[0] = '0';
		data[1] = '\0';
	}
	else
	{
		temp = a;
		if (a < 0)
		{
			data[size - 2] = '-';
			temp = temp * -1;
			for (int i = 0; i < size - 2; i++)
			{
				data[i] = '0' + (temp % 10);
				temp = temp / 10;
			}
		}
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				data[i] = '0' + (temp % 10);
				temp = temp / 10;
			}

		}
		data[size - 1] = '\0';
		reverse();
	}
}
String	String::operator +(const String & s2) const
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true || isNullPtr(s2.data) == true || isNullCharacter(s2.data[0]) == true)
	{
		return *this;
	}
	return this->concatenate(s2);
}
void String::operator +=(const String& s2)
{
	if (isNullPtr(s2.data) == true || isNullCharacter(s2.data[0]) == true)
	{
		return ;
	}
	this->concatEqual(s2);
}
void String::operator()(const int count, ...)
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return;
	}
	if (count==0)
	{
		return;
	}
	va_list listOfCount;
	__crt_va_start(listOfCount, count);
	char* temporary = nullptr;
	for (int i = 0; i < count; i++)
	{
		String temp(__crt_va_arg(listOfCount, char*));
		while (find(temp) != -1)
		{
			remove(find(temp), temp.getLength());
		}
	}
	__crt_va_end(listOfCount);
}
String String::operator =(const long long int a)
{
	setNumber(a);
	return*this;
}
bool String::operator ==(const String& s2) const
{
	if (compare(s2) == 0)
	{
		return 1;
	}
	return 0;
}
String String::operator -(const String& s2) const
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true || isNullPtr(s2.data) == true || isNullCharacter(s2.data[0]) == true)
	{
		return *this;
	}
	String temp{*this};
	while (temp.find(s2) != -1)
	{
		temp.remove(temp.find(s2), s2.getLength());
	}
	return temp;
}
String String::operator = (const String& s2)
{
	if (compare(s2)==0)
	{
		return *this;
	}
	if (isNullPtr(s2.data) == true || s2.size <= 0)
	{
		this->~String();
		return *this;
	}
	if (isNullPtr(data) == false || size > 0)
	{
		this->~String();
	}
	size = s2.size;
	createString(data, size);
	copyStringByUsingLength(data, s2.data, s2.size);
	return *this;
}
bool String::operator >(const String& s2) const
{
	if (compare(s2) == 1)
	{
		return 1;
	}
	return 0;
}
bool String::operator <(const String& s2) const
{
	if (compare(s2) == -1)
	{
		return 1;
	}
	return 0;
}
bool String::operator <=(const String& s2) const
{
	if (( *this < s2 ) || ( *this == s2 ))
	{
		return 1;
	}
	return 0;
}
bool String::operator >=(const String& s2) const
{
	if ((*this == s2)|| (*this > s2))
	{
		return 1;
	}
	return 0;
}
bool String::operator !=(const String& s2) const
{
	if (*this == s2)
	{
		return 0;
	}
	return 1;
}



istream & operator>>( istream s1,const String& s2)
{
	if (isNullPtr(s2.data) || isNullCharacter(s2.data[0]) )
	{
		return s1;
	}
	return s1 >> s2.data;
}
ostream& operator<<(ostream s1, const String& s2)
{
	if (isNullPtr(s2.data) || isNullCharacter(s2.data[0]))
	{
		return s1;
	}
}