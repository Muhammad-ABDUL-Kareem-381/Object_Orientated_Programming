#include<iostream>
using namespace std;
template <typename T>
class Array;
template <typename T>
class Matrix
{
	Array<T>* data;
	int rows;
	int columns;
	bool isAdditionPossible(const Matrix& m) const;
	bool isMultiplicationPossible(const Matrix& m) const;
	void makeMatrixNull();
	friend ostream& operator << (ostream& os, Matrix& m);
	friend istream& operator >> (istream& is, Matrix& m);
	void input();
public:
	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& m);
	Matrix& operator =(const Matrix& m);
	~Matrix();
	int getRows() const;
	int getColumns() const;
	void print() const;
	bool operator ==(const Matrix& m) const;
	Matrix& transpose() const;
	bool isSymmetric() const;
	void resize(int newRow, int newCol);
	Matrix& add(const Matrix& m) const;
	Matrix& multiply(const Matrix& m) const;
	T & operator [] (const int i);
	const T& operator [] (const int i) const;
};
template <typename T>
class Array
{
	T* data;
	int capacity;
	int isValidIndex(int) const;
	void print() const;
	void input();
public:
	/*friend istream& operator >> (istream& is, Array& arr);
	friend ostream& operator << (ostream& os, Array& arr);*/
	//Array();
	Array(int =0);
	Array(const Array <T>& ref);
	int getCapacity() const;
	//void setSize(int s);
	T& operator [](int i);
	const T& operator [] (int) const;
	void reSize(int s);
	Array <T>& operator = (const Array <T>& ref);
	~Array();
};
//template <typename T>
//Array<T>::Array() : data(nullptr), size(0)
//{}
template <typename T>
int Array<T>::isValidIndex(int i) const
{
	if ((i < 0) || (i >= capacity))
	{
		return -1;
	}
	return 1;
}
template <typename T>
Array<T>::Array(int s)
{
	if (s < 0)
	{
		return;
	}
	size = s;
	data = new T[size];
}
template <typename T>
Array<T>::Array(const Array <T>& ref)
{
	size = ref.size;
	data = new T[size];
	myMemCpy(data, ref.data, size);
}
template <typename T>
void Array<T>::input()
{
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}
}
template <typename T>
T& Array<T>::operator [](int i)
{
	if (isValidIndex(i))
	{
		return (data[i]);
	}
	exit(0);
}
template <typename T>
const T& Array<T>::operator [] (int i) const
{
	if (i < 0)
	{
		exit(0);
	}
	return data[i];
}
template <typename T>
void Array<T>::reSize(int s)
{
	T* temp = new T[s];
	myMemCpy(temp, data, s);
	delete[] data;
	data = temp;
	temp = nullptr;
	size = s;
}
template <typename T>
Array <T>& Array<T>::operator = (const Array <T>& ref)
{
	this-> ~Array();
	size = ref.size;
	data = new T[size];
	myMemCpy(data, ref.data, size * sizeof(T));
	return *this;
}
template <typename T>
Array<T>::~Array()
{
	size = 0;
	delete[] data;
	data = nullptr;
}
template <typename T>
int Array<T>::getCapacity() const
{
	return size;
}
//template <typename T>
//void Array<T>::setSize(int s)
//{
//	if (s < 0)
//		return;
//	size = s;
//}
template<typename T>
void Array<T>::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << ' ';
	}
}
//template<typename T>
//ostream& operator << (ostream& os, Array<T> & arr)
//{
//	cout << arr.data[i];
//	return os;
//}
//template<typename T>
//istream& operator >> (istream& is, Array<T>& arr)
//{
//	cin >> data[i];
//	return is;
//}

int main()
{
	Matrix <int> mt1{2,2};
	mt1[0, 0] = 1;
	mt1[0, 1] = 2;
	mt1[1, 0] = 3;
	mt1[1, 1] = 4;
	Matrix<int> mt2{ mt1 };
	Matrix<int> mt3 = mt1.multiply(mt2);
	mt3.print();
	return 0;
	Array<int> m1{ 2 };
	m1[0] = 23;
	m1[1] = 2;
	cout << m1[1];
}
template <typename T>
T& Matrix<T>::operator [] (const int i)
{
	if (i < 0)
	{
		exit(0);
	}
	return data[i];
}
template <typename T>
const T& Matrix<T>::operator [] (const int i) const
{
	if (i < 0)
	{
		exit(0);
	}
	return data[i];
}
template <typename T>
Matrix<T>::Matrix()// : data(nullptr), rows(0), columns(0)
{
	data = nullptr;
	rows = 0;
	columns = 0;
}
template <typename T>
Matrix<T>::Matrix(int r, int c) : Matrix<T>()
{
	if (r <= 0 || c <= 0)
	{
		return;
	}
	rows = r;
	columns = c;
	data = new T[rows][columns];
}
template <typename T>
Matrix<T>::Matrix(const Matrix& m)
{
	this-> ~Matrix();
	data = m.data;
	columns = m.columns;
	rows = m.rows;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i][j] = m.data[i][j];
		}
	}
}
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m)
{
	this-> ~Matrix();
	data = m.data;
	columns = m.columns;
	rows = m.rows;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i][j] = m.data[i][j];
		}
	}
}
template <typename T>
Matrix<T>::~Matrix()
{
	delete[] data;
	data = nullptr;
	rows = 0;
	columns = 0;
}
template <typename T>
int Matrix<T>::getRows() const
{
	return rows;
}
template <typename T>
int Matrix<T>::getColumns() const
{
	return columns;
}
template <typename T>
void Matrix<T>::print() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << data[i][j] << ' ';
		}
		cout << '\n';
	}
}
template <typename T>
bool Matrix<T>::operator==(const Matrix& m) const
{
	if (rows != m.rows || columns != m.columns)
	{
		return false;
	}
	bool equalSt = true;
	while (equalSt)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (!(data[i][j] == m.data[i][j]))
				{
					equalSt = false;
				}
			}
		}
	}
	return equalSt;
}
template <typename T>
Matrix<T>& Matrix<T>::transpose() const
{
	Matrix<T> temp{ columns, rows };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i][j] == temp.data[j][i];
		}
	}
	return temp;
}
template <typename T>
bool Matrix<T>::isSymmetric() const
{
	Matrix transposedMatrix{ columns, rows };
	transposedMatrix = transpose();
	if (transposedMatrix == *this)
	{
		return true;
	}
	return false;
}
template <typename T>
void Matrix<T>::resize(int newRow, int newCol)
{
	if (newRow < 0)
	{
		newRow = 0;
	}
	if (newCol < 0)
	{
		newCol = 0;
	}
	Matrix temp{ newRow, newCol };
	for (int i = 0; i < rows && i < newRow; i++)
	{
		for (int j = 0; j < columns && j < newCol; j++)
		{
			temp.data[i][j] = data[i][j];
		}
	}
	*this = temp;
	temp.~Matrix();
}
template <typename T>
Matrix<T>& Matrix<T>::add(const Matrix<T>& m) const
{
	if (isAdditionPossible(m))
	{
		Matrix temp{ rows, columns };
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				temp.data[i][j] = data[i][j] + m.data[i][j];
			}
		}
		return temp;
	}
	exit(0);
}
template <typename T>
void Matrix<T>::input()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; i < columns; j++)
		{
			cin >> data[i][j];
		}
	}
}
template <typename T>
Matrix<T>& Matrix<T>::multiply(const Matrix <T>& m) const
{
	if (isMultiplicationPossible(m))
	{
		Matrix temp{ rows, m.columns };
		temp.makeMatrixNull();
		for (int i = 0; i < temp.rows; i++)
		{
			for (int j = 0; j < temp.columns; j++)
			{
				data[i][j] = data[i][j] + data[i][j] * m.data[i][j];
			}
		}
		return temp;
	}
	exit(0);
}
template <typename T>
bool Matrix<T>::isAdditionPossible(const Matrix<T>& m) const
{
	if ((m.columns == columns) && (m.rows == rows))
	{
		return true;
	}
	return false;
}
template <typename T>
bool Matrix<T>::isMultiplicationPossible(const Matrix<T>& m) const
{
	if ((m.columns == rows) && (m.rows == columns))
	{
		return true;
	}
	return false;
}
template <typename T>
void Matrix<T>::makeMatrixNull()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j= 0; j < columns; j++)
		{
			data[i][j] = 0;
		}
	}
}
template <typename T>
ostream& operator << (ostream& os, Matrix<T>& m)
{
	m.print();
	return os;
}
template <typename T>
istream& operator >> (istream& is, Matrix<T>& m)
{
	m.input();
	return is;
}

