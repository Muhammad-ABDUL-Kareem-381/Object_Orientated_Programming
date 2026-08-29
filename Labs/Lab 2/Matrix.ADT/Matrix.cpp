#include "Matrix.h"
bool Matrix::operator ! () const
{
	return (!(data && (rows > 0) && (columns > 0)));
}
bool Matrix::isMultiplicationPossible(Matrix m2) const
{
	return (columns == m2.rows);
}
void Matrix::multiplyRowWithScalar(int r, int mul)
{
	if ((r >= 0) && (r < rows))
	{
		int j = 0;
		while (j < columns)
		{
			data[r][j] = (data[r][j]) * mul;
			j++;
		}
	}
}
void Matrix::swapTwoRows(int r1, int r2)
{
	int j = 0;
	double temp = 0;
	while (j < columns)
	{
		temp = data[r1][j];
		data[r1][j] = data[r2][j];
		data[r2][j] = temp;
		j++;
	}
}
Matrix::Matrix() : rows(0), columns(0), data(nullptr)
{}
Matrix::Matrix(const int r, const int c) :Matrix()
{
	if (!(r > 0 && c > 0))
	{
		return;
	}
	rows = r;
	columns = c;
	data = new double* [r];
	for (int i = 0; i < columns; i++)
	{
		data[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i][j] = i + j - 1;
		}
	}
}
Matrix::Matrix(const Matrix& ref) :Matrix(ref.rows, ref.columns)
{
	if (!ref.data)
	{
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i][j] = (ref.data)[i][j];
		}
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;
	data = nullptr;
	rows = 0;
	columns = 0;
}
void Matrix::makeMatrixNull()
{
	if(!(*this))
	{
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			data[i][j] = 0;
		}
	}
}
double& Matrix::at(const int r, const int c)
{
	return data[r][c];    // no need to check in case of assuming it like a setter as an entry/element in matrix may be +ve, -ve or 0.
}
const double& Matrix::at(const int r, const int c) const
{
	return data[r][c];  // it's like a getter due to const return type, for a const object of Matrix. Also can be used for non-constant object of Matrix.
}
Matrix Matrix::operator + (const Matrix& m)
{
	if (!(this->rows == m.rows && this->columns == m.columns))
	{
		exit(0);
	}
	Matrix res{ *this };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			res.at(i, j) = this->at(i, j) + m.at(i, j);
		}
	}
	return res;
}
int Matrix::getRows() const    // basically for const object. But can also be used for non-constant object. Coz in programming limitations can be increased , but cannot b decreased.
{
	return rows;
}
int Matrix::getColumns() const
{
	return columns;
}
void Matrix::display() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << at(i, j) << '\t';
			//cout << i << ' ' << j;
		}
		cout << '\n';
	}
}
Matrix Matrix::transpose() const
{
	Matrix transposedMatrix(columns, rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			(transposedMatrix.data)[j][i] = data[i][j];
		}
	}
	return transposedMatrix;
}
Matrix Matrix::operator *(Matrix m2) const
{
	if (!(*this) || !m2)
	{
		exit(0);
	}
	if (!isMultiplicationPossible(m2))   //this condition is necessary for multiplication of 2 matrices
	{
		exit(0);
	}
	Matrix resMatrix(rows, m2.columns);
	resMatrix.makeMatrixNull();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < m2.columns; j++)
		{
			//resMatrix.data[i][j] = 0;
			for (int k = 0; k < columns || k < m2.rows; k++)    //as both columns and m2.rows are equal
			{
				resMatrix.data[i][j] = (data[i][k] * m2.data[k][j]) + resMatrix.data[i][j];
			}
		}
	}
	return resMatrix;
}
bool Matrix::operator ==(Matrix m2) const
{
	if (!(data && m2.data && rows == m2.rows && rows != 0 && columns == m2.columns && columns != 0))
	{
		return false;
	}
	bool equalStatus = true;
	int i = 0, j = 0;
	while (i < rows && equalStatus)
	{
		while (j < columns && equalStatus)
		{
			if (data[i][j] != (m2.data)[i][j])
			{
				equalStatus = false;
			}
			i++;
			j++;
		}
	}
	return equalStatus;
}
void Matrix::reSize(const int newRow, const int newCol)
{
	double** temp;
	temp = new double* [newRow];
	for (int i = 0; i < newRow; i++)
	{
		temp[i] = new double[newCol];
	}
	int smallerRows = (rows < newRow) ? rows : newRow;
	int smallerColumns = (columns < newCol) ? columns : newCol;
	for (int i = 0; i < smallerRows; i++)
	{
		for (int j = 0; j < smallerColumns; j++)
		{
			temp[i][j] = data[i][j];
		}
	}
}
bool Matrix::isSymmetric() const
{
	if (!(*this))
	{
		return false;
	}
	Matrix transposedMatrix = transpose();
	return (*this==transposedMatrix);
}