#include<iostream>
using namespace std;
class String
{
	char* data;
	int size;
	bool isNullPtr(const char* pointer)
	{
		return (pointer == nullptr);
	}
	bool isNullCharacter(const char character)
	{
		return (character == '\0');
	}
	void createString(char*& string, const int size)
	{
		string = new char[size];
	}
	int giveLengthOfGivenString(const char* temp)
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
	void copyString(char* dest, const char* sour)
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
	void copyStringByUsingLength(char* dest, const char* sour, const int size1)
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
	bool isValidIndex(const int index)
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
	int giveResultOfComparingGivenStringsIndexValue(const char str1, const char str2)
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
public:
	String()
	{
		data = nullptr;
		size = 0;
	}
	String(char c) : String()
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
		if (isNullPtr(temp) == true)
		{
			return;
		}
		size = (giveLengthOfGivenString(temp) + 1);
		createString(data, size);
		copyString(data, temp);
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
		/*if(isNullPtr(data)|| isNullCharacter(data[0]))
		{
			return;
		}*/
		int limit = (newSize < size) ? newSize : size;
		char* temp;
		createString(temp, newSize);
		copyStringByUsingLength(temp, data, limit);
		this->~String();
		data = temp;
		size = newSize;
	}
	bool isEmpty()
	{
		return (isNullPtr(data) || isNullCharacter(data[0]));
	}
	char& at(int index)
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
	int getLength()
	{
		if (isEmpty())
		{
			return 0;
		}
		return giveLengthOfGivenString(data);
	}
	int getSize()
	{
		if (isEmpty())
		{
			return 0;
		}
		return size;
	}
	void display()
	{
		if (isNullPtr(data))
		{
			return ;
		}
		else
		{
			cout << data;
		}
	}
	int find(String* subStr, int start = 0)
	{
		if (!isValidIndex(start))
		{
			return -1;
		}
		if (size < subStr->getSize())
		{
			return -1;
		}
		if (isEmpty() || subStr->isEmpty())
		{
			return -1;
		}
		int length = subStr->getLength();
		for (int i = start; i <= size - length; i++)
		{
			int result = 0;
			for (int j = 0; j < length; j++)
			{
				if (data[i + j] == subStr->data[j])
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
	void insert(int index, String* subStr)
	{
		if (isEmpty() || subStr->isEmpty() || !isValidIndex(index))
		{
			return;
		}
		char* temp;
		int newSize = size + subStr->getSize();
		createString(temp, newSize);
		copyString(temp, data);
		copyString(&temp[index], subStr->data);
		copyString(&temp[index + subStr->getLength()], &data[index]);
		this->~String();
		data = temp;
		size = newSize;
	}
	void remove(int index,int count = 1)
	{
		if (isEmpty() || !isValidIndex(index) || !isValidIndex(index + count))
		{
			return;
		}
		size = size - count;
		copyString(&data[index], &data[index + count]);
	}
	int replace(String* old,String* newSubStr)
	{
		if (isEmpty() || old->isEmpty() || newSubStr->isEmpty())
		{
			return 0;
		}
		int count = 0, index = 0;
		while ((index = find(old, index)) && index != -1)
		{
			remove(index, old->getLength());
			insert(index, newSubStr);
			index = index + newSubStr->getLength();
			count = count + 1;
		}
		return count;
	}void trimLeft()
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
		while (data[index] == ' ' || data[index] == '\t' || data[index] == '\n')
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
		for (int i = 0; i < size - 1; i++)
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
		for (int i = 0; i < size - 1; i++)
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
	void shrink()
	{
		if (isEmpty())
		{
			return;
		}
		reSize(getLength() + 1);
	}
	int compare(String& s2)
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
};
int main()
{
	String str{ "111Hello222"},str1{"Hello" };
	///*str.input();
	//cout << "\n";*/
	//cout<<str.getLength();
	//cout << "\n";
	//cout<<str.getSize();
	//cout << "\n";
	//str.display();
	str.remove(3, 5);
	str.display();
	return 0;
}