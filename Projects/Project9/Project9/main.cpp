#include"String.h"
int main()
{
	String S{ }, S1{"hello world"};
	/*cin >> s1;
	cout << S;*/
	/*cout << S.operator==(s1);
	cout<<S.operator!=(s1);*/
	S1 -= S;
	cout<<S1[1];
	S1.display();
	return 0;
}