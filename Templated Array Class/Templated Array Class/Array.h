#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<cstdarg>
using namespace std;
template <typename T>
class Array
{
	friend ostream& operator<< <>(ostream& out, Array<T>& arr);
	friend istream& operator>> <>(istream& in, Array<T>& arr);
	T* data;
	int capacity;
	bool isValidIndex(int index) const;
	static void myMemMove(void* src, void* dest, int byteCount);
	void input();
	void printArray() const;
	void inputCapacity();
public:
	Array(int count = 0, ...);
	Array<T>(const Array<T>& ref);
	Array<T>(Array<T>&& ref);
	Array <T> operator = (const Array<T>& ref);
	Array <T>operator = (Array<T>&& ref);
	T& operator [] (int index);
	const T& operator [] (int index) const;
	int getCapacity() const;
	void reSize(int newSize);
	~Array();
};
template<typename T>
ostream& operator << (ostream& out, Array<T>& arr);
template<typename T>
istream& operator >> (istream& in, Array<T>& arr);
#endif // ARRAY_H




template<typename T>
void Array<T>::inputCapacity()
{
	int cap;
	cout << "Enter capacity: ";
	cin >> cap;
	if (cap <= 0 || cap <= capacity)
	{
		return;
	}
	else
	{
		capacity = cap;
	}
}
template<typename T>
bool Array<T>::isValidIndex(int index) const
{
	if (index < capacity && index >= 0)
	{
		return true;
	}
	return false;
}
template<typename T>
void Array<T>::input()
{
	for (int i = 0; i < capacity; i++)
	{
		cin >> data[i];
	}
}
template<typename T>
Array<T>::Array(int count, ...)
{
	if (count <= 0)
	{
		capacity = 0;
		data = nullptr;
		return;
	}
	capacity = count;
	data = new T[capacity];
	va_list myList;
	va_start(myList, count);
	T arg;
	for (int i = 0; i < count; i++)
	{
		if (is_same<T, float>::value)
		{
			arg = static_cast<float>(va_arg(myList, double));
			data[i] = arg;
		}
		else
		{
			arg = va_arg(myList, T);
			data[i] = arg;
		}
	}
	va_end(myList);
}
template<typename T>
Array<T>::Array(const Array<T>& ref) : Array<T>(0)
{
	if (this == &ref)
	{
		return;
	}
	if (!ref.data)
	{
		exit(0);
	}
	// this->~Array();  // no need of this coz object is already at valid and null/reset state due to Array() ie default ctor
	capacity = ref.capacity;
	this->reSize(capacity);
	/*int i = 0;
	while (i < capacity)
	{
		data[i]=ref.data[i];
		i++;
	}*/
	myMemMove(ref.data, data, sizeof(int) * capacity);
}
template<typename T>
Array<T>::Array(Array <T>&& ref)
{
	if (this == &ref)
	{
		return;
	}
	if (!ref.data)
	{
		exit(0);
	}
	this->~Array();
	capacity = ref.capacity;
	data = ref.data;    // transfer of memory resource ie. array to pointer of calling obj.
	ref.data = nullptr;    // break the connection of array with old obj.
	ref.capacity = 0;
}
template<typename T>
Array<T> Array<T>::operator = (const Array<T>& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	if (!ref.data)
	{
		exit(0);
	}
	// this->~Array();  // no need of this coz object is already at valid and null/reset state due to Array() ie default ctor
	capacity = ref.capacity;
	this->reSize(capacity);
	/*int i = 0;
	while (i < capacity)
	{
		data[i]=ref.data[i];
		i++;
	}*/
	myMemMove(ref.data, data, sizeof(T) * capacity);
	return *this;
}
template<typename T>
Array<T> Array<T>::operator = (Array<T>&& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	if (!ref.data)
	{
		exit(0);
	}
	this->~Array<T>();
	capacity = ref.capacity;
	data = ref.data;    // transfer of memory resource ie. array to pointer of calling obj.
	ref.data = nullptr;    // break the connection of array with old obj.
	ref.capacity = 0;
	return *this;
}
template<typename T>
void Array<T>::myMemMove(void* src, void* dest, int byteCount)
{
	const char* s = (const char*)src;
	char* d = (char*)dest;
	for (int i = byteCount - 1; i >= 0; i--)
	{
		d[i] = s[i];
	}
}
template<typename T>
T& Array<T>::operator [] (int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
template<typename T>
const T& Array<T>::operator [] (int index) const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
template<typename T>
int Array<T>::getCapacity() const
{
	return capacity;
}
template<typename T>
void Array<T>::reSize(int newSize)
{
	if (newSize <= 0)
	{
		this->~Array<T>();
		return;
	}
	int* temp = new T[newSize];
	int i = 0;
	int smallerSize = (newSize < capacity) ? newSize : capacity;
	if (data)     // means if there was any data in calling obj then transfer it to new array otherwise skip it.
	{
		while (i < smallerSize)
		{
			temp[i] = data[i];
			i++;
		}
	}
	this->~Array<T>();
	capacity = newSize;
	data = temp;
}
template<typename T>
void Array<T>::printArray() const
{
	if (!data || !capacity)
	{
		return;
	}
	for (int i = 0; i < capacity; i++)
	{
		cout << data[i] << ' ';
	}
}
template<typename T>
Array<T>::~Array()
{
	delete[] data;
	data = nullptr;
	capacity = 0;
}
template<typename T>
ostream& operator << (ostream& out, Array<T>& arr)
{
	arr.printArray();    // OR u can implement whole logic of printArray () here by making it friend of class.
	return out;
}
template<typename T>
istream& operator >> (istream& in, Array<T>& arr)
{
	if (!arr.data)
	{
		arr.inputCapacity();
		arr.data = new T[arr.capacity];
	}
	arr.input();
	return in;
}
