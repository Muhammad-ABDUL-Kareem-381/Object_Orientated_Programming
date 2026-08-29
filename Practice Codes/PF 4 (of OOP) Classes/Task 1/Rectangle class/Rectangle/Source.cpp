#include <iostream>
using namespace std;
class Rectangle
{
private:
	int length;
	int width;
	bool validateRectangle()
	{
		if ((length > 0) && (width > 0))
		{
			return true;
		}
		return false;
	}
	void resetFactoryVersion()
	{
		length = 1;
		width = 3;
	}
public:
	Rectangle()
	{
		resetFactoryVersion();
	}
	Rectangle(int len, int wid): Rectangle()
	{
		length=len;
		width=wid;
		if(!validateRectangle())
		{
			resetFactoryVersion();
		}
	}
	void setLength(int len)
	{
		if (length > 0)
		{
			length = len;
		}
	}
	int getLength()
	{
		return length;
	}
	void setWidth(int wid)
	{
		if (wid > 0)
		{
			width = wid;
		}
	}
	int getWidth()
	{
		return width;
	}
	int calcPerimeter()
	{
		return (length + width) * 2;
	}
	int calcArea()
	{
		return(length * width);
	}
	bool isSquare()
	{
		return (length == width);
	}
};
int main()
{
	Rectangle rec{12,78};
	int a = 45;
	cout << rec.getLength()<<'\n';
	cout << rec.getWidth();
	return 0;
}