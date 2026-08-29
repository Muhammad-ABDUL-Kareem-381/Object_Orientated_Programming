#include<iostream>
using namespace std;
class Rectangle
{
	double length;
	double width;
	bool isInputValid(double num)
	{
		return (num > 0.0) ? true : false;
	}
public:
	Rectangle()
	{
		length = 0.0;
		width = 0.0;
	}
	Rectangle(double l, double w) : Rectangle()
	{
		setLength(l);
		setWidth(w);
	}
	void setLength(double l)
	{
		if (isInputValid(l))
		{
			length = l;
		}
	}
	void setWidth(double w)
	{
		if (isInputValid(w))
		{
			width = w;
		}
	}
	double getLength()
	{
		return length;
	}
	double getWidth()
	{
		return width;
	}
	double calculatePerimeter()
	{
		return (length + width) * 2.0;
	}
	double calculateArea()
	{
		return (length * width);
	}
	bool isSquare()
	{
		return(length == width) ? true : false;
	}
};
int main()
{
	Rectangle r = { 2.7, 2.7 };
	cout << r.getLength() << "\n" << r.getWidth()<<"\n"<<r.isSquare()<<"\n"<<r.calculateArea()<<"\n"<<r.calculatePerimeter();
	return 0;
}