#include<iostream>
using namespace std;
template <typename T>
class Matrix
{
	T** data;
	int rows;
	int columns;
	bool isAdditionPossible(const Matrix& m) const;
	bool isMultiplicationPossible(const Matrix& m) const;
	void makeMatrixNull();
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
	Matrix& multiply(const Matrix & m) const;
//	T operator [] (const Matrix& m) const;
	//T& operator [] (const Matrix& m);
};
int main()
{
	Matrix<int> m1{ 2,2 }, m2{ 2,2 };
	Matrix<int> m3 = m1.multiply(m2);
	m3.print();
	return 0;
}
//template <typename T>
//T Matrix<T>::operator [] (const Matrix& m) const
//{
//	return data
//}
//template <typename T>

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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i][j] = 1;
		}
	}
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
Matrix<T> & Matrix<T>::transpose() const
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
Matrix<T> & Matrix<T>::add(const Matrix<T> & m) const
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
		retrun temp;
	}
	exit(0);
}
template <typename T>
Matrix<T> & Matrix<T>::multiply(const Matrix <T>& m) const
{
	if (isMultiplicationPossible(m))
	{
		Matrix temp{ rows, m.columns };
		temp.makeMatrixNull();
		for (int i = 0; i < temp.rows && i < newRow; i++)
		{
			for (int j = 0; j < temp.columns && j < newCol; j++)
			{
				data[i][j] = data[i][j] + data[i][j] * m.data[i][j];
			}
		}
		retrun temp;
	}
	exit(0);
}
template <typename T>
bool Matrix<T>::isAdditionPossible(const Matrix<T>& m) const
{
	if ((m.columns == columns) && (m.rows == rows)
	{
		return true;
	}
	return false;
}
template <typename T>
bool Matrix<T>::isMultiplicationPossible(const Matrix<T>& m) const
{
	if ((m.columns == rows) && (m.rows == columns)
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
		for (int = 0; j < columns; j++)
		{
			data[i][j] = 0;
		}
	}
}
