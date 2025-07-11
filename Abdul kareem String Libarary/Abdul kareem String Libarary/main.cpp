#include"String.h"
int main()
{
	String a{"This,Q--a sample string. nothing"}, b{"Hello"}, c{"or"};
	String token;
	while (a)
	{
		token = a(".-,");
		cout << "Token = " << token;
		cout << '\n';
	}
	a.display();
	/*long long int num = (long long int)a;
	cout << "\n" << num;*/
	//String s3 = move(a);
	//s3.display();
	/*cout << "\n";
	b.display();
	cout << "\n";
	c.display();*/
	
	
	return 0;
}
