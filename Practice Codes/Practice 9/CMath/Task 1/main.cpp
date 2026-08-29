#include"String.h"
int main()
{
	String a{ "123.960" }, B{ "hjddddddddddddddddddddddddddddutfjhhyrtriurytetlhsyuiotyeyt8ouysdtirtaer8oyu7er8t" }, C{"J"};
	//a.replace(B, C);
	//a.setNumber(+948.75);
	cout << a.convertToInteger()<<'\n';
	cout << a.convertToFloat();
	//a.display();
	
	return 0;
}