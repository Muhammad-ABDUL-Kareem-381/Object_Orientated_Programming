#include<iostream>
using namespace std;
void f(const AClass& ref);
class AClass
{
	int a1;
	friend void f(const AClass& ref);
public:
	AClass(int i = 10) : a1(10)
	{

	}
	void print()
	{
		cout << a1;
	}
};
void f(const AClass& ref)
{
	cout << "\n" << ref.a1;
	AClass obj1{ 12 };
	cout << "\n" << obj1.a1;
}
int main()
{
	AClass abc{ 23 };
	f(abc);
	return 0;
}