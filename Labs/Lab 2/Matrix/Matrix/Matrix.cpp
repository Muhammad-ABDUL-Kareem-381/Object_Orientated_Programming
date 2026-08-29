#include<iostream>
using namespace std;
class Matrix
{
	double** data;
	int rows;
	int columns;
	const bool isValidRows(const int r) const
	{
		return (r > 0);
	}
	const bool isValidColumns(const int c) const
	{
		return (c > 0);
	}
	const bool isNullPtr(double** temp) const
	{
		return (temp == nullptr);
	}
	void createMatrix(double**& temp,const int r,const int c)
	{
		*temp = new double[r];
		for (int i = 0; i < r; i++)
		{
			temp[i] = new double[c];
		}
	}
	void copyMatrix(Matrix& dest ,const Matrix& sour)
	{
		if (isNullPtr(dest.data))
		{
			return;
		}
		if (isNullPtr(sour.data))
		{
			dest.~Matrix();
			return;
		}
		for (int i = 0; i < sour.rows; ++i) 
		{
			for (int j = 0; j < sour.columns; ++j) 
			{
				dest.data[i][j] = sour.data[i][j];
			}
		}
	}
public:
	Matrix() : rows(0),columns(0),data(nullptr)
	{

	}
	Matrix(const int r, const int c) :Matrix()
	{
		if (isValidRows(r) && isValidColumns(c))
		{
			rows = r;
			columns = c;
			createMatrix(data, r, c);
		}
	}
	Matrix(const Matrix& ref) : Matrix()
	{
		if (isNullPtr(ref.data))
		{
			return;
		}
		rows = ref.rows;
		columns = ref.columns;
		copyMatrix(*this, ref);

	}
	~Matrix()
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
	double& at(const int r, const int c)
	{
		if (!isNullPtr(data) && isValidRows(r) && isValidColumns(c))
		{
			return data[r][c];
		}
		else
		{
			exit(0);
		}
	}
	const double& at(const int r, const int c) const
	{
		if (!isNullPtr(data) && isValidRows(r) && isValidColumns(c))
		{
			return data[r][c];
		}
		else
		{
			exit(0);
		}
	}
	int getRows() const
	{
		return rows;
	}
	int getColumns() const
	{
		return columns;
	}
	void display()
	{
		if (isNullPtr(data))
		{
			return;
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << data[i][j];
			}
			cout << "\n";
		}
	}
};
int main()
{
	Matrix m1{ 3,4 };
	/*for (int i = 0; i < m1.getRows(); i++)
	{
		for (int j = 0; j < m1.getColumns(); j++)
		{
			cin >> m1.at(i, j);
		}
	}*/
	m1.display();
	return 0;
}