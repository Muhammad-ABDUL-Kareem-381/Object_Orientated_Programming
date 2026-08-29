#include<iostream>
using namespace std;
class Student
{
	char rollNo[11];
	int semester;
	char name[100];
	float CGPA;
	bool isValidSemester(int temp)
	{
		return (temp >= 1 && temp <= 8) ? true : false;
	}
	bool isValidCGPA(float temp)
	{
		return (temp >= 0.0 && temp <= 4.0) ? true : false;
	}
	int getIntegralPartOfRollNo(const char* temp)
	{
		int num = 0;
		for (int i = 7; i < 10; i++)
		{
			num = num * 10;
			num = num + (temp[i] - '0');
		}
		return num;
	}
	bool isIntegralPartOfRollNoValid(const char*temp)
	{
		int num = getIntegralPartOfRollNo(temp);
		return (num >= 1 && num <= 999) ? true : false;
	}
	bool isRollNoValid(const char* temp)
	{
		return isIntegralPartOfRollNoValid(temp);
	}
	void copyString(char* dest, const char* sour)
	{
		int count = 0;
		while (sour[count] != '\0')
		{
			dest[count] = sour[count];
			count++;
		}
		dest[count] = '\0';
	}
public:
	Student()
	{
		copyString(rollNo, "\0");
		semester = 0;
		copyString(name, "\0");
		CGPA = 0.0;
	}
	Student(const char* r, int s, const char* n, float num) : Student()
	{
		setRollNo(r);
		setSemester(s);
		setName(n);
		setCGPA(num);
	}
	void setRollNo(const char* temp)
	{
		if (isRollNoValid(temp))
		{
			copyString(rollNo, temp);
		}
	}
	void setSemester(int temp)
	{
		if (isValidSemester(temp))
		{
			semester = temp;
		}
	}
	void setName(const char* temp)
	{
		copyString(name, temp);
	}
	void setCGPA(float temp)
	{
		if (isValidCGPA(temp))
		{
			CGPA = temp;
		}
	}
	const char* getRollNo()
	{
		return rollNo;
	}
	int getSemester()
	{
		return semester;
	}
	const char* getName()
	{
		return name;
	}
	float getCGPA()
	{
		return CGPA;
	}
	bool isStudentDropOut()
	{
		return ( ( CGPA < 1.5 && semester == 1 ) || ( CGPA < 1.7 && semester > 1 ) ) ? true : false;
	}
	bool isStudentOnProbation()
	{
		return ( ( ( CGPA >= 1.5 && CGPA < 2 ) && semester == 1) || ( ( CGPA >= 1.7 && CGPA < 2) && semester > 1 ) ) ? true : false;
	}
};
int main()
{
	Student s = { "BSEF23M014",2,"Hadi",1.7 };
	cout << s.isStudentDropOut();
	cout << s.isStudentOnProbation();
	return 0;
}