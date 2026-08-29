#include "CaesarCipher.h"
#include"VigenereCipher.h"
//#include "String.h"
#include<fstream>
String fileIntoString(char* argv[])
{
	String str;
	char ch;
	ifstream ifs1{argv[1]};
	while (ifs1.get(ch))
	{
		str = str.concatenate(ch);
	}
	return str;
}
String getOutputFileName(char* argv[])
{
	String str = argv[4];
	return str;
}
int main(int argc, char * argv[])
{
	char* input = argv[1];
	char* mode = argv[2];
	char* incre = argv[3];
	char* output = argv[4];
	if (atoi(argv[2]) == 'c')
	{
		CaesarCipher cr;
		cr.setShift(atoi(argv[3]));
		String encryptedString=cr.encrypt(fileIntoString(argv));
		ofstream ofs{ input};
		int i = 0;
		while (encryptedString.at(i) != '\0')
		{
			ofs << encryptedString.at(i);
			i++;
		}
	}
	else if (atoi(argv[2]) == 'v')
	{
		VigenereCipher vc;
		String s = argv[3];
		vc.setKey(s);
		String encryptedString = vc.encrypt(fileIntoString(argv));
		ofstream ofs{ "Output.txt" };
		int i = 0;
		while (encryptedString.at(i) != '\0')
		{
			ofs << encryptedString.at(i);
			i++;
		}
	}
	else
	{
		cout << "Invalid choice";
	}
	//VigenereCipher st;
	////st.setShift(3);
	//String s;
	//cout << "Enter String:";
	//s.input();
	//String key = "OK";
	////cout << "\nEnter Key:";
	//st.setKey(key);
	//cout << "\nEncrypted String:";
	//(st.encrypt(s)).display();
	return 0;
}