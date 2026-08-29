#include<iostream>
using namespace std;
int xyz=4567;
int getStrLen(const char* ch);
void copyCharArray(const char* src, char * dest);
void swapCharacters(char & a, char &b);
void myMemMove(void* src, void* dest, int byteCount);
class String
{
private:
	char * data;
	int size;
	bool isValidIndex(int index)
	{
		if ((index >= 0) && (index < getStrLen(data)))
		{
			return true;
		}
		return false;
	}
	int findIndex(String* subStr)   //find index of subStr's 1st character in 1st its occurrence String.
	{
		int index = -1;
		int strLen = getLength();
		int subStrLen = subStr->getLength();
		bool equalStatus = false;
		for (int i=0; i < strLen; )
		{
			int j = 0;
			do
			{
				if (data[i] == subStr->at(j))
				{
					equalStatus = true;
					j++;
				}
				else
				{
					equalStatus = false;
				}
				i++;
			}
			while ((j < subStrLen) && (equalStatus));
			if ((j == subStrLen) && (equalStatus))
			{
				return (i - j);
			}
		}
		return -1;
	}
public:
	String()
	{
		data = nullptr;
		size = 0;
	}
	String(char c):String()
	{
		if (!c)
		{
			size = 1;
			data = new char {'\0'};   // same as data=new char [1] {'\0'};
			return;
		}
		size = 2;
		data = new char[size] {c,'\0'};
		//data[0] = c;
		//data[1] = '\0';
	}
	String(const char* ch): String()
	{
		if (ch)
		{
			size = getStrLen(ch) + 1;
			data = new char[size];
			copyCharArray(ch, data);
		}
	}
	int getLength()
	{
		return (getStrLen(data));
	}
	void input()
	{
		if (!data || size<=0)
		{
			/*size = 10;
			data = new char[size];*/
			reSize(10);
		}
		char temp;
		int i = 0;
		while (cin.get(temp) && temp!='\n')
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
	void display()
	{
		if (data)
		{
			cout << data;
		}
	}
	const char & at(int index)
	{
		/*if (!data)
		{
			exit(0);
		}*/
		if (isValidIndex(index))
		{
			return data[index];
		}
		exit(0);
	}
	bool isEmpty()
	{
		if ((!data) || (! getLength()))
		{
			return true;
		}
		return false;
	}
	int getSize()
	{
		return size;
	}
	void reSize(int newSize)
	{
		if (!(newSize > 0))
		{
			this->~String();
			return;
		}
		size = newSize ;
		char* temp = new char[size];
		copyCharArray(data, temp);
		delete[] data;
		data = temp;
	}
	int find(String* subStr, int start = 0)
	{
		int count = 0;
		int strLen = getLength();
		int subStrLen = subStr->getLength();
		bool equalStatus = false;
		for (; start < strLen; )
		{
			int j = 0;
			do
			{				
				if (data[start] == subStr->at(j))
				{
					equalStatus = true;
					j++;
				}
				else
				{
					equalStatus = false;
				}
				start++;
			} while ((j < subStrLen) && (equalStatus));
			if ((j == subStrLen) && (equalStatus))
			{
				count++;
			}
		}
		return count;
	}
	//Qazxsw12@
	void remove(int index, int count = 1)
	{
		int strLen = getLength();
		if ((index + count) > strLen)
		{
			return;
		}
		int i=index;
		while( (i < (index + count)) && ( data[i+count] ))
		{
			data[i] = data[i + count];
			i++;
		}
		while ( i < (strLen-count))
		{
			data[i] = data[i + count];
			i++;
		}
		data[i] = '\0';
		shrink();
	}
	void insert(int index, String* subStr)
	{
		if ((index >= getSize()) || (!subStr))
		{
			return;
		}
		int subStrLen = subStr->getLength();
		int strLen = getLength();
		if (getSize() < (strLen + subStrLen + 1))
		{
			reSize(strLen + subStrLen + 1);
		}
		myMemMove(&(data[index]),&(data[index+subStrLen]),strLen-index);
		myMemMove((void*) & (subStr->at(0)), &(data[index]), subStrLen);
		//data[index+subStrLen]
		data[strLen + subStrLen ] = '\0';
		shrink();
	}
	int replace(String* old, String* newSubStr)
	{
		int strLen = getLength();
		int replaceCount = 0;   //replaceCount means no. of replacements of old String
		for (int i = 0; i < strLen; i++)
		{
			int index = findIndex(old);
			if (index>=0)
			{
				remove(index, old->getLength());
				insert(index, newSubStr);
				i = i + newSubStr->getLength()-1;
				replaceCount++;
			}
		}
		return replaceCount;
	}
	int compare(String &s2)
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
				if (data[i] == s2.at(i))
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
				if (data[i] > s2.at(i))
				{
					return 1;
				}
				return -1;
			}
			return 0;
		}
	}
	void makeUpper()
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
	void makeLower()
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
	void reverse()
	{
		int strLen =getLength();
		for (int i = 0; i < (strLen / 2); i++)
		{
			swapCharacters(data[i], data[strLen - i - 1]);
		}
	}
	void trimRight()
	{
		int i = getLength()-1;
		while (data[i] == ' ' || data[i] == '\n' || data[i] == '\t')
		{
			i--;
		}
		i = i + 1;
		data[i] = '\0';
		shrink();
	}
	void trimLeft()
	{
		int i = 0;
		while (data[i] == ' ' || data[i] == '\n' || data[i] == '\t')
		{
			i++;
		}
		remove(0, i);
		shrink();
	}
	void trim()
	{
		trimLeft();
		trimRight();
	}
	void shrink()
	{
		reSize(getLength()+1);
	}
	~String()
	{
		if (!data)
		{
			return;
		}
		delete[] data;
		data = nullptr;
		size = 0;
	}
};
int main()
{
	String s1{};
	s1.input();
	s1.display();
	cout<<'\t'<<s1.getSize();
}
int getStrLen(const char* ch)
{
	int i = 0;
	while (ch[i])
	{
		i++;
	}
	return i;
}
void copyCharArray(const char* src, char * dest)
{
	if (!src)
	{
		return;
	}
	int i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
void swapCharacters(char & a, char & b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void myMemMove(void* src, void* dest, int byteCount)
{
	const char* s = (const char*)src;
	char* d = (char*)dest;
	for (int i = byteCount - 1;i>=0; i--)
	{
		d[i] = s[i];
	}
}
// prob 1 use strsize in at() instead of strLen to set values of characters at null or higher index
/*
replace () is giving for this code written in main():

	String st{ "abcdecdecd" }, old{"cd"}, newS{"12345"};
	cout << st.replace(&old,&newS)<<'\n';
	st.display();
*/
// why I can't input directly in data[i] character by character instead of taking input in char temp and then storing it in our Strin in input()??