#include<iostream>
using namespace std;
class Array
{
	int* data;
	int capacity;
	bool isValidIndex(int index)
	{
		return (index >= 0 && index < capacity);
	}
	void createArray(int*& temp, int capacity)
	{
		temp = new int[capacity];
	}
	bool isValidCapacity(int capacity)
	{
		return (capacity > 0);
	}
	bool isEmpty(const int* data)
	{
		return (data == nullptr);
	}
	void copyArrayByUsingLength(int*& dest, const int* sour, int cap)
	{
		if (!isValidCapacity(cap))
		{
			return;
		}
		if (isEmpty(dest))
		{
			return;
		}
		if (isEmpty(sour))
		{
			dest = nullptr;
			return;
		}
		int count = 0;
		while (count < cap - 1)
		{
			dest[count] = sour[count];
			count++;
		}
		dest[count] = '\0';
	}
public:
	Array(int cap = 0)
	{
		if (isValidCapacity(cap))
		{
			capacity = cap;
			createArray(data, capacity);
		}
		else
		{
			capacity = 0;
			data = nullptr;
		}
	}
	Array(const Array& other)
	{
		capacity = other.capacity;
		if (capacity > 0)
		{
			data = new int[capacity];
			for (int i = 0; i < capacity; i++)
			{
				data[i] = other.data[i];
			}
		}
		else
		{
			data = nullptr;
		}
	}
	Array(Array&& other) noexcept
	{
		data = other.data;
		capacity = other.capacity;
		other.data = nullptr;
		other.capacity = 0;
	}
	~Array()
	{
		if (isEmpty(data))
		{
			return;
		}
		delete[]data;
		data = nullptr;
		capacity = 0;
	}
	int& getSet(int index)
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		else
		{
			exit(0);
		}
	}
	int& operator [](int index)
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		else
		{
			exit(0);
		}
	}
	int getCapacity()
	{
		return capacity;
	}
	void reSize(int newCapacity)
	{
		if (capacity == newCapacity)
		{
			return;
		}
		if (newCapacity==0)
		{
			this->~Array();
			return;
		}
		if (!isValidCapacity(newCapacity))
		{
			return;
		}
		int limit = (newCapacity < capacity) ? newCapacity : capacity;
		int* temp = nullptr;
		createArray(temp, newCapacity);
		copyArrayByUsingLength(temp, data, limit);
		this->~Array();
		data = temp;
		capacity = newCapacity;
	}
	Array& operator++()
	{
		cout << "\n pre \n";
		for (int i = 0; i < capacity; i++)
		{
			data[i]++;
		}
		return *this;
	}
	Array operator++(int)
	{
		cout << "\n post \n";
		Array temp(*this);
		for (int i = 0; i < capacity; i++)
		{
			data[i]++;
		}
		return temp;
	}
};
int main()
{
	Array arr;
	arr.reSize(3);
	for (int i = 0; i < arr.getCapacity(); i++)
	{
		arr.getSet(i) = i * 2;
	}
	arr++;
	for (int i = 0; i < arr.getCapacity(); i++)
	{
		cout<<arr.getSet(i);
	}
	return 0;
}