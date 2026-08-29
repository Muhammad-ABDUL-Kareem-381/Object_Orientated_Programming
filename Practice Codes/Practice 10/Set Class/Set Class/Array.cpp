#include"Array.h"
const bool Array::isValidIndex(const int index) const
{
	return (index >= 0 && index < capacity);
}
void Array::createArray(int*& temp, const int capacity)
{
	temp = new int[capacity];
}
bool Array::isValidCapacity(const int capacity)
{
	return (capacity > 0);
}
bool Array::isEmpty(const int* data)
{
	return (data == nullptr);
}
void Array::copyArrayByUsingLength(int* dest, const int* sour, const int cap)
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
	while (count < cap)
	{
		dest[count] = sour[count];
		count++;
	}
}


Array::Array(int cap)
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
Array::Array(const Array& ref) : Array()
{
	if (isEmpty(ref.data) || !isValidCapacity(ref.capacity))
	{
		return;
	}
	capacity = ref.capacity;
	createArray(data, capacity);
	copyArrayByUsingLength(data, ref.data,capacity);
}
Array::~Array()
{
	if (isEmpty(data))
	{
		return;
	}
	delete[]data;
	data = nullptr;
	capacity = 0;
}
int& Array::getSet(int index)
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
const int& Array::getSet(int index) const
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
int& Array::operator[](const int index)
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
const int Array::getCapacity() const
{
	return capacity;
}
void Array::reSize(const int newCapacity)
{
	if (capacity == newCapacity)
	{
		return;
	}
	if (newCapacity == 0)
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
void Array::printArray() const
{
	if (isEmpty(data))
	{
		return;
	}
	for (int i = 0; i < getCapacity(); i++)
	{
		cout << operator[](i) << '\t';
	}
	cout << '\n';
}
Array& Array::operator=(const Array& ref)
{
	if (this == &ref)
	{
		return*this;
	}
	if (!isEmpty(data))
	{
		this->~Array();
	}
	capacity = ref.capacity;
	createArray(data, capacity);
	copyArrayByUsingLength(data, ref.data,capacity);
	return*this;
}
const int& Array::operator[](const int index)const
{
	if (index < capacity && index >= 0)
	{
		return data[index];
	}
	else
	{
		exit(0);
	}
}
Array& Array::operator++()
{
	if (isEmpty(data))
	{
		exit(0);
	}
	for (int i = 0; i < capacity; i++)
	{
		data[i]++;
	}
	return*this;
}
Array Array::operator++(int)const
{
	if (isEmpty(data))
	{
		exit(0);
	}
	Array temp{ *this };
	for (int i = 0; i < capacity; i++)
	{
		temp.data[i]++;
	}
	return temp;
}

