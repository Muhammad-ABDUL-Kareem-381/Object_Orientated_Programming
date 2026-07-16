////#include "functions.h"
//#include"BigNumber.h"
//void myMemCpy(void* dest, const void* src, int byteCount)
//{
//	int i;
//	char* d = (char*)dest;
//	const char* s = (const char*)src;
//	if ((int)(&(d[byteCount - 1]) - (int)(s)))
//	{
//		for (i = 0; i < byteCount; i++)
//		{
//			d[i] = s[i];
//		}
//	}
//}
//int getLength(const char* num)
//{
//	if (!num)
//		return 0;
//	if (num[0] == '\0')
//	{
//		return 0;
//	}
//	int i = 1;
//	while (num[i] != '\0')
//	{
//		i++;
//	}
//	//cout << "getLength() " << endl;
//	return i;
//}
//istream & operator >> (istream & is, BigNumber& bn)
//{
//	bn.inputBigNumber();
//	//cin >> bn.number;
//	// but if i dont have member function to inpuct BigNumber then i can use cin>>bn.number instead of bn.inputBigNumber().
//	return is;
//}
//ostream & operator << (ostream & os, BigNumber& bn)
//{
//	bn.print();
//	return os;
//}
