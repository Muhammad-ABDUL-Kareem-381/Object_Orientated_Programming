#include<iostream>
using namespace std;
int main(int argc, char * argv[])
{
	for (int i = 0; i < argc; i++)
	{
		cout << "\n" << argv[i];
	}
	return 0;
}