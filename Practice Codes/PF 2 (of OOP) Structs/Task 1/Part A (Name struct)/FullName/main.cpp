#include<iostream>
using namespace std;
void copyCharArray(const char* src, char* tar);
struct FullName
{
private:
	char lastName[50];
	char middleName[50];
	char firstName[50];
	void setFactoryVersion()
	{
		copyCharArray("MMM", firstName);   //pass char array by value
		copyCharArray("Umer", middleName);
		copyCharArray("Farooq", lastName);
	}
public:
	FullName()
	{
		setFactoryVersion();
	}
	FullName(const char* f, const char* m, const char* l): FullName()
	{
		if (f && m && l)
		{
			copyCharArray(f, firstName);
			copyCharArray(m, middleName);
			copyCharArray(l, lastName);
		}
	}
	void setFirstName(const char* f)
	{
		if (f)
		{
			copyCharArray(f, firstName);
		}
	}
	void setMiddleName(const char* m)
	{
		if (m)
		{
			copyCharArray(m, middleName);
		}
	}
	void setLastName(const char* l)
	{
		if (l)
		{
			copyCharArray(l, lastName);
		}
	}
	const char* getFirstName()
	{
		return firstName;
	}
	const char* getMiddleName()
	{
		return middleName;
	}
	const char* getLastName()
	{
		return lastName;
	}
	void initializeFullName()
	{
		copyCharArray("Muhammad", firstName);   //pass char array by value
		copyCharArray("Umer", middleName);
		copyCharArray("Farooq", lastName);
	}
	void inputFullName()
	{
		cout << "Enter first name:";
		cin.getline (firstName, 50);
		cin.ignore();
		cout << "Enter middle name:";
		cin.getline (middleName, 50);
		cin.ignore();
		cout << "Enter last name:";
		cin.getline (lastName, 50);
		cin.ignore();
	}
	void displayName()
	{
		cout << "First Name:" << firstName << '\n';
		cout << "Middle Name:" << middleName << '\n';
		cout << "Last Name:" << lastName << '\n';
	}
};
int main()
{
	FullName info{};
	info.setFirstName(nullptr);
	info.displayName();
	return 0;
}
void copyCharArray(const char* src, char * tar)
{
	int i = 0;
	while (src[i] != '\0')
	{
		tar[i] = src[i];
		i++;
	}
	tar[i] = '\0';
}