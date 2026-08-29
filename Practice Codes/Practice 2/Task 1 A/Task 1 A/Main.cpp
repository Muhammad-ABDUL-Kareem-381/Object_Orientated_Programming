#include<iostream>
using namespace std;
struct FullName
{
	char firstName[50];
	char middleName[50];
	char lastName[50];
};
void inputName(char  tempArr[],const char*temp);
void printFullName(FullName& a);
int	main()
{
	FullName info;
	inputName(info.firstName, "Muhammad");
	inputName(info.middleName, "Abdul Kareem");
	inputName(info.lastName, "Saeed");
	printFullName(info);
	return 0;
}	
void inputName(char  tempArr[],const char*temp)
{
	int count = 0;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		tempArr[i] = temp[i];
		count = i;
	}
	tempArr[count + 1] = '\0';
}
void printFullName(FullName& a)
{
	cout << "Full name is = " << a.firstName << " " << a.middleName << " " << a.lastName << "\n";
}