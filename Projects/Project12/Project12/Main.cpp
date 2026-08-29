#include<iostream>
#include<fstream>
#include"CaesarCipher.h"
#include"VigenereCipher.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (*argv[2] == 'c')
	{
		ifstream i1{argv[1]};
		ofstream o1{ argv[4]};
		String s{ argv[3] };
		if (!i1.is_open())
		{
			return 0;
		}
		char temp;
		while (i1.get(temp))
		{
			CaesarCipher e1{ (int)s.convertToInteger() };
			o1<<e1.encrypt(temp).at(0);
		}
		o1.close();
		i1.close();
	}
	else
	{
		ifstream i1{ argv[1] };
		ofstream o1{ argv[4] };
		if (!i1.is_open())
		{
			return 0;
		}
		char temp;
		while (i1.get(temp))
		{
			VigenereCipher e1{ argv[3] };
			o1 << e1.encrypt(temp).at(0);
		}
		o1.close();
		i1.close();

	}



	return 0;
}