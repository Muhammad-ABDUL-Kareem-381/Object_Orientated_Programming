#include<iostream>
using namespace std;
void copyCharArray(const char* src, char* tar);
class Student
{
private:
	char rollNo[11];
	int semester;
	char name[100];
	float CGPA;
	void resetFactoryVersion()
	{
		copyCharArray("bsef23m004",rollNo);
		semester = 2;
		copyCharArray("Muhammad Umer Farooq", name);
		CGPA = 1;
	}
	bool validateRollNo()
	{
		return (rollNo[7] >= '0' && rollNo[7] <= '9') && (rollNo[8] >= '0' && rollNo[8] <= '9') && (rollNo[9] >= '1' && rollNo[9] <= '9');
	}
	bool validateSemester()
	{
		return (semester > 0) && (semester <= 8);
	}
	bool validateCGPA()
	{
		return (CGPA >= 0) && (CGPA <= 4);
	}
public:
	Student()
	{
		resetFactoryVersion();
	}
	Student(const char* n, const char* roll, int sem, float cgpa): Student()
	{
		semester = sem;
		copyCharArray(roll, rollNo);
		copyCharArray(n, name);
		CGPA = cgpa;
		if (!(validateRollNo() && validateSemester() && validateCGPA() && name))
		{
			resetFactoryVersion();
		}
	}
	void setRollNo(const char* roll)
	{
		if ((roll[7] >= '0' && roll[7] <= '9') && (roll[8] >= '0' && roll[8] <= '9') && (roll[9] >= '1' && roll[9] <= '9')&&(roll[10]=='\0'))
		{
			copyCharArray(roll, rollNo);
		}
	}
	void setSemester(int sem)
	{
	
		if ((sem > 0) && (sem <= 8))
		{
			semester = sem;
		}
	}
	void setName(const char* n)
	{
		copyCharArray(n, name);
	}
	void setCGPA(float cgpa)
	{
		if ((cgpa >= 0) && (cgpa <= 4))
		{
			CGPA = cgpa;
		}
	}
	int getSemester()
	{
		return semester;
	}
	float getCGPA()
	{
		return CGPA;
	}

	const char* getName()
	{
		return name;
	}
	const char* getRollNo()
	{
		return rollNo;
	}
	bool isStudentdropOut()
	{
		if ((semester == 1) && (CGPA < 1.5))
		{
			return true;
		}
		else if ((semester>=2) &&  (CGPA < 1.7))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isStudentOnProbation()
	{
		if ((semester == 1) && (CGPA >= 1.5) && (CGPA < 2))
		{
			return true;
		}
		else if ((CGPA >= 1.7) && (CGPA< 2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{
	Student st{ "Muhammad Umer Bajwa","BSEF23M004",2, 1.3 };
	//st.printStudentInfo();
	st.setName("Muhammad Umer Farooq Bajwa Bin Muhammad Nawaz Mansoor Bajwa");
	st.setRollNo("bsef23m000");
	st.setSemester(7);
	st.setCGPA(4);
	//st.printStudentInfo();
	return 0;
}
void copyCharArray(const char* src, char* tar)
{
	int i = 0;
	while (src[i] != '\0')
	{
		tar[i] = src[i];
		i++;
	}
	tar[i] = '\0';
}