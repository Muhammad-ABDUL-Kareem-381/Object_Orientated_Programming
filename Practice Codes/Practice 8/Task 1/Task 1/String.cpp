#include<iostream>
using namespace std;
class String
{
	char* data;
	int size;
	bool isValidIndex(const int index) const
	{
		return (index >= 0 && index < size);
	}
	void mySwap(char* a, char* b)
	{
		if (isNullPtr(a) || isNullCharacter(a[0]) || isNullPtr(b) || isNullCharacter(b[0]))
		{
			return;
		}
		char temp = *a;
		*a = *b;
		*b = temp;
	}
	int giveResultOfComparingGivenStringsIndexValue(const char str1, const char str2) const
	{
		if (str1 < str2)
		{
			return -1;
		}
		else if (str1 > str2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	bool isStringNegative() const
	{
		if (isEmpty())
		{
			return false;
		}
		if (data[0] == '-')
		{
			return true;
		}
		return false;
	}
	bool isStringPositive() const
	{
		if (isEmpty())
		{
			return false;
		}
		if (data[0] == '+')
		{
			return true;
		}
		return false;
	}
	int giveNumberLength(long long int a) const
	{
		int length = 0;
		if (a == 0)
		{
			length = 1;
		}
		else
		{
			if (a < 0)
			{
				length++;
				a = a * -1;
			}
			while (a > 0)
			{
				length++;
				a = a / 10;
			}
		}
		return length;
	}
	int giveLengthOfGivenString(const char* temp) const
	{
		if (isNullPtr(temp) || isNullCharacter(temp[0]))
		{
			return 0;
		}
		int count = 0;
		while (temp[count] != '\0')
		{
			count++;
		}
		return count;
	}
	bool isNullPtr(const char* pointer) const
	{
		return (pointer == nullptr);
	}
	bool isNullCharacter(const char character) const
	{
		return (character == '\0');
	}
	void createString(char*& string, const int size) const
	{
		string = new char[size];
	}
	void copyString(char* dest, const char* sour) const
	{
		if (isNullPtr(dest))
		{
			return;
		}
		if (isNullPtr(sour))
		{
			delete[]dest;
			dest = nullptr;
			return;
		}
		int count = 0;
		while (sour[count] != '\0')
		{
			dest[count] = sour[count];
			count++;
		}
		dest[count] = '\0';
	}
	void copyStringByUsingLength(char* dest, const char* sour, const int size1) const
	{
		if (size <= 0)
		{
			dest = nullptr;
			return;
		}
		if (isNullPtr(dest))
		{
			return;
		}
		if (isNullPtr(sour))
		{
			delete[]dest;
			dest = nullptr;
			return;
		}
		int count = 0;
		while (count < size1 - 1)
		{
			dest[count] = sour[count];
			count++;
		}
		dest[count] = '\0';
	}
	
public:

	String()
	{
		data = nullptr;
		size = 0;
	}
	String(const char c) : String()
	{
		if (isNullCharacter(c))
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
	String(const char* temp) : String()
	{
		if (isNullPtr(temp))
		{
			return;
		}
		size = (giveLengthOfGivenString(temp) + 1);
		createString(data, size);
		copyString(data, temp);
	}
	String(const String& ref) : String()
	{
		if (isNullPtr(ref.data))
		{
			return;
		}
		size = ref.size;
		createString(data, size);
		copyStringByUsingLength(data, ref.data, ref.size);
	}
	~String()
	{
		if (isNullPtr(data))
		{
			return;
		}
		delete[]data;
		data = nullptr;
		size = 0;
	}
	void input()
	{
		if (!isNullPtr(data))
		{
			this->~String();
		}
		char character;
		int count = 0, length = 0;
		size = 2;
		createString(data, size);
		while (cin.get(character) && character != '\n')
		{
			if (count == size - 1)
			{
				length = size + 1;
				reSize(length);
			}
			data[count] = character;
			count++;
		}
		data[count] = '\0';
	}
	void reSize(int newSize)
	{
		if (size == newSize)
		{
			return;
		}
		if (newSize <= 0)
		{
			this->~String();
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
	void shrink()
	{
		if (isEmpty())
		{
			return;
		}
		reSize(getLength() + 1);
	}
	char& at(const int index)
	{
		if (!isEmpty() && isValidIndex(index))
		{
			return data[index];
		}
		else
		{
			exit(0);
		}
	}
	const char& at(const int index) const
	{
		if (!isEmpty() && isValidIndex(index))
		{
			return data[index];
		}
		else
		{
			exit(0);
		}
	}
	bool isEmpty() const
	{
		return (isNullPtr(data) || isNullCharacter(data[0]));
	}
	int getLength() const
	{
		if (isEmpty())
		{
			return 0;
		}
		return giveLengthOfGivenString(data);
	}
	int getSize() const
	{
		return size;
	}
	void display() const
	{
		if (isEmpty())
		{
			return;
		}
		cout << data;
	}
	int find(String subStr, const int start = 0) const
	{
		if (!isValidIndex(start))
		{
			return -1;
		}
		if (size < subStr.getSize())
		{
			return -1;
		}
		if (isEmpty() || subStr.isEmpty())
		{
			return -1;
		}
		int length = subStr.getLength();
		for (int i = start; i <= size - length; i++)
		{
			int result = 0;
			for (int j = 0; j < length; j++)
			{
				if (data[i + j] == subStr.data[j])
				{
					result++;
				}
			}
			if (result == length)
			{
				return i;
			}
		}
		return -1;
	}
	void insert(const int index, const String& subStr)
	{
		if (isEmpty() || isNullPtr(subStr.data) || !isValidIndex(index))
		{
			return;
		}
		if (size>=(getLength()+subStr.getLength()+1))
		{
			char* temp;
			createString(temp,(getLength()+1));
			copyStringByUsingLength(temp,data,(getLength() + 1));
			copyString(&data[index], subStr.data);
			copyString(&data[index + subStr.getLength()], &temp[index]);
			delete[]temp;
			temp = nullptr;
		}
		else
		{
			char* temp;
			int newSize = getLength() + subStr.getSize() + 1;
			createString(temp, newSize);
			copyStringByUsingLength(temp, data, (index + 1));
			copyString(&temp[index], subStr.data);
			copyString(&temp[index + subStr.getLength()], &data[index]);
			this->~String();
			data = temp;
			size = newSize;
		}
	}
	void remove(const int index, const int count = 1)
	{
		if (isEmpty() || !isValidIndex(index) || !isValidIndex(index + count))
		{
			return;
		}
		copyString(&data[index], &data[index + count]);
	}
	int replace(String old,String newSubStr)
	{
		if (isEmpty() || old.isEmpty() || newSubStr.isEmpty())
		{
			return 0;
		}
		int count = 0, index = 0;
		while ((index = find(old, index)) && index != -1)
		{
			remove(index, old.getLength());
			insert(index, newSubStr);
			index = index + newSubStr.getLength();
			count++;
		}
		return count;
	}
	void trimLeft()
	{
		if (isEmpty())
		{
			return;
		}
		int count = 0, index = 0;
		while (data[index] == ' ' || data[index] == '\t' || data[index] == '\n')
		{
			count++;
			index++;
		}
		remove(0, count);
		size = size - count;
	}
	void trimRight()
	{
		if (isEmpty())
		{
			return;
		}
		int count = 0, index = (getLength() - 1);
		while (index >= 0 && data[index] == ' ' || data[index] == '\t' || data[index] == '\n')
		{
			count++;
			index--;
		}
		data[getLength() - count] = '\0';
		size = size - count;
	}
	void trim()
	{
		if (isEmpty())
		{
			return;
		}
		trimLeft();
		trimRight();
	}
	void makeUpper()
	{
		if (isEmpty())
		{
			return;
		}
		for (int i = 0;data[i] != '\0'; i++)
		{
			if (data[i] >= 'a' && data[i] <= 'z')
			{
				data[i] = data[i] - 32;
			}
		}
	}
	void makeLower()
	{
		if (isEmpty())
		{
			return;
		}
		for (int i = 0;data[i]!='\0'; i++)
		{
			if (data[i] >= 'A' && data[i] <= 'Z')
			{
				data[i] = data[i] + 32;
			}
		}
	}
	void reverse()
	{
		if (isEmpty())
		{
			return;
		}
		for (int i = 0, j = getLength() - 1; i < j; i++, j--)
		{
			mySwap(&data[i], &data[j]);
		}
	}
	int compare(const String& s2) const
	{
		if (isEmpty() && s2.isEmpty())
		{
			return 0;
		}
		if (isEmpty() && !s2.isEmpty())
		{
			return -1;
		}
		if (!isEmpty() && s2.isEmpty())
		{
			return 1;
		}
		int index = 0;
		while (!isNullCharacter(data[index]) && !isNullCharacter(s2.data[index]) && data[index] == s2.data[index])
		{
			index++;
		}
		return giveResultOfComparingGivenStringsIndexValue(data[index], s2.data[index]);
	}
	String left(const int count)
	{
		if (isEmpty() || !isValidIndex(count))
		{
			return *this;
		}
		String a;
		a.size = count + 1;
		createString(a.data, a.size);
		copyStringByUsingLength(a.data, data, a.size);
		remove(0, count);
		return a;
	}
	String right(const int count)
	{
		if (isEmpty() || !isValidIndex(count))
		{
			return *this;
		}
		String a;
		a.size = count + 1;
		createString(a.data, a.size);
		copyStringByUsingLength(a.data, &data[getLength() - count], a.size);
		remove((getLength() - count), count);
		return a;
	}
	long long int convertToInteger() const
	{
		if (isEmpty())
		{
			return 0;
		}
		int index = 0;
		int sign = 1;
		if (isStringNegative())
		{
			sign = -1;
			index = 1;
		}
		if (isStringPositive())
		{
			index = 1;
		}
		long long int number = 0;
		for (int i = index; data[i] != '\0'; i++)
		{
			if (data[i] >= '0' && data[i] <= '9')
			{
				number = number * 10;
				number = number + (data[i] - '0');
			}
			else
			{
				return number * sign;
			}
		}
		return number * sign;
	}
	float convertToFloat() const
	{
		if (isEmpty())
		{
			return 0.0;
		}
		int index1 = 0, index2 = 0, length = 0;
		float sign = 1.0;
		if (isStringNegative())
		{
			sign = -1.0;
			index1 = 1;
		}
		if (isStringPositive())
		{
			index1 = 1;
		}
		bool decimalPoint = false;
		float num = 0.0;
		for (int i = index1; data[i] != '\0'; i++)
		{
			if (data[i] >= '0' && data[i] <= '9')
			{
				num = num * 10;
				num = num + (data[i] - '0');
				length++;
			}
			else if (data[i] == '.' && !decimalPoint)
			{
				index2 = i;
				decimalPoint = true;
			}
			else
			{
				if (decimalPoint)
				{
					for (int j = 0; j < (length - index2); j++)
					{
						num = num / 10;
					}
				}
				return num * sign;
			}
		}
		if (decimalPoint)
		{
			for (int j = 0; j < (length - index2); j++)
			{
				num = num / 10;
			}
		}
		return num * sign;
	}
	String concatenate(const String& s2) const
	{
		if (isEmpty() || s2.isEmpty())
		{
			return *this;
		}
		String temp;
		temp.size = (getLength() + s2.getLength() + 1);
		createString(temp.data, temp.size);
		copyString(temp.data, data);
		copyString(&temp.data[size - 1], s2.data);
		return temp;
	}
	void concatEqual(const String& s2)
	{
		if (isEmpty() || s2.isEmpty())
		{
			return;
		}
		insert(getLength(), s2);
	}
	void setNumber(const long long int num)
	{
		if (!isEmpty())
		{
			this->~String();
		}
		long long int temp = num;
		size = (giveNumberLength(temp) + 1);
		createString(data, (size));
		if (num == 0)
		{
			data[0] = '0';
			data[1] = '\0';
		}
		else
		{
			if (num < 0)
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
};
int main()
{
	String s1{ "12345.87" };
	s1.display();
	cout<<"\n" << s1.convertToFloat();
	float num = 12345.87;
	cout << '\n' << num;
	/*cout << "\n";
	String s2{ s1.right(5) };
	s1.display();
	cout << "\n";
	s2.display();*/
	return 0;
}