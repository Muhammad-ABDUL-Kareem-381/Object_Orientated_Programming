#include<iostream>
using namespace std;
class Matrix
{
public:
	int** data;
	int rows;
	int cols;
	Matrix()
	{
		cout << "def";
	}

	Matrix(int a)
	{
		cout << "int";
	}
	~Matrix()
	{
		cout << '~';
	}

};

//externint X;
//void f();
int main()
{
	Matrix a;
}

void createMatrix(Matrix& m, int r, int c)
{
	m.rows = r;
	m.cols = c;
	m.data = new int*[m.rows];
	for (int i = 0; i < m.rows; i++)
	{
		m.data[i] = new int[m.cols];
	}
}
Matrix add(Matrix a, Matrix b)
{
	Matrix res;
	createMatrix(res, a.rows, a.cols);
	if (!(a.rows == b.rows && a.cols == b.cols))
	{
		res.data = nullptr;
	}
	for (int i = 0; i < res.rows; i++)
	{
		for (int j = 0; j < res.cols; j++)
			res.data[i][j] = a.data[i][j] + b.data[i][j];
	}
	return res;
}




//#include<iostream>
//using namespace std;
//class Test
//{
//	int i;
//	static Test* test;
//	Test(int f = 0)
//	{
//		i = f;
//		cout << "\nconstructor:" << f;
//	}
//	~Test()
//	{
//		cout << "\ndestructor:" << i;
//	}
//public:
//	static Test* getInstance(int i)
//	{
//		if (test == nullptr)
//		{
//			test = new Test{i};
//			//*test = i;
//		}
//		return test;
//	}
//	static void freeInstance()
//	{
//		test->~Test();
//		test = nullptr;
//	}
//};
//Test* Test::test = nullptr;
//int main()
//{
//	//Test tst;
//	Test::getInstance(3);
//	Test::freeInstance();
//	Test::getInstance(65);
//}