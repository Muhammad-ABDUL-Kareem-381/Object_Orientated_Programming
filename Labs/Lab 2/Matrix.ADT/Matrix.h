#ifndef MATRIX_H
#define MATRIX_H
#include "D:\Academics\OOP 2.0\Labs\Lab 4\String.ADT\String3.ADT\String.h"
using namespace std;
class Matrix
{
public:
	double** data;   //a double pointer (ie **) that will point an array to pointers in which every pointer pointer an array double(data type).
	int rows;
	int columns;
	bool operator !() const;
	bool isMultiplicationPossible(Matrix m2) const;
	void multiplyRowWithScalar(int r, int mul);
	void swapTwoRows(int r1, int r2);
public:
	Matrix();
	Matrix(const int r, const int c);
	Matrix(const Matrix& ref);
	~Matrix();
	void makeMatrixNull();
	double& at(const int r, const int c);
	const double& at(const int r, const int c) const;
	Matrix operator + (const Matrix& m);
	int getRows() const;    // basically for const object. But can also be used for non-constant object. Coz in programming limitations can be increased , but cannot b decreased.
	int getColumns() const;
	void display() const;
	Matrix transpose() const;
	Matrix operator *(Matrix m2) const;
	bool operator ==(Matrix m2) const;
	void reSize(const int newRow, const int newCol);
	bool isSymmetric() const;
};
#endif