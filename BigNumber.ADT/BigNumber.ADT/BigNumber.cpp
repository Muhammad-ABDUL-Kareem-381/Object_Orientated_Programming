#include"BigNumber.h"
BigNumber::BigNumber(): number(nullptr),numberLength(0)
{}
BigNumber::BigNumber(const char * bn) :BigNumber()
{
	if (!bn || getLength(bn) )
	{
		return;
	}
	numberLength=getLength(bn);
	number = new char[numberLength + 1];
	myMemCpy(number, bn, numberLength);
	number[numberLength] = '\0';
}
BigNumber::BigNumber(const BigNumber& bn) :BigNumber()
{
	numberLength=bn.numberLength;
	number = new char[numberLength + 1];
	myMemCpy(number, bn.number, numberLength);
	number[numberLength] = '\0';
}
BigNumber::BigNumber(BigNumber&& ref):BigNumber()
{
	number = ref.number;
	numberLength = ref.numberLength;
	ref.number = nullptr;
	ref.numberLength = 0;
}
BigNumber::~BigNumber()
{
	delete [] number;
	numberLength=0;
	number = nullptr;
}
void BigNumber::inputBigNumber()
{
	this-> ~BigNumber();
	numberLength=5;
	number = new char[numberLength];
	char temp;
	int i = 0;
	while (cin.get(temp) && temp != '\n')
	{
		if (i == (numberLength - 1))
			resize(numberLength * 2);
		number[i] = temp;
		i++;
	}
	number[i] = '\0';
	shrink();
}
BigNumber& BigNumber::operator = (const BigNumber & other)
{
	this->~BigNumber();
	numberLength=other.numberLength;
	number = new char[numberLength + 1];
	myMemCpy(number, other.number, numberLength + 1);
	return *this;
}
BigNumber BigNumber::operator + (const BigNumber& other) const
{
	if (!this)
		return *this;
	BigNumber bn1{ *this }, bn2{ other };
	if (bn1.getNumberLength() < bn2.getNumberLength())
		bn1.reLength(bn2.getNumberLength());
	else
		bn2.reLength(bn1.getNumberLength());
	BigNumber resultBn;
	resultBn.setNumberLength(bn2.getNumberLength() + 1);   
	resultBn.number = new char[resultBn.getNumberLength() + 1];
	int i, carry = 0;
	for (i = 1; i < resultBn.numberLength; i++)
	{
		resultBn.number[resultBn.getNumberLength() - i] = (bn1.number[bn1.getNumberLength() - i] + bn2.number[bn2.getNumberLength() - i] - '0' + carry);
		carry = (resultBn.number[resultBn.getNumberLength() - i] - '0') / 10;
		resultBn.number[resultBn.getNumberLength() - i] = ((resultBn.number[resultBn.numberLength - i] - '0') % 10) + '0';
	}
	resultBn.number[0] = carry + '0';
	resultBn.number[resultBn.numberLength] = '\0';
	//resultBn.removeZerosAtLeft();
	return resultBn;
}
Comparison BigNumber::compare(const BigNumber bn2)const
{
	if (!this)
		exit(0);
	int i = 0, j = 0;
	while ((i < numberLength) && (number[i] == '0'))
		i++;
	while ((j < bn2.numberLength) && (bn2.number[j] == '0'))
		j++;
	if (((numberLength - i) - (bn2.numberLength - j)) > 0)
	{
		return LARGE;
	}
	else if (((numberLength - i) - (bn2.numberLength - j)) < 0)
	{
		return SMALL;
	}
	else
	{
		bool equalStatus = true;
		while ((i < getNumberLength()) && (j < bn2.getNumberLength()) && (equalStatus))
		{
			if (number[i] != bn2.number[j])
				equalStatus = false;
			i++;
			j++;
		}
		//I mean (i!=numberlength)
		if (!(equalStatus))
		{
			if (number[i - 1] > bn2.number[j - 1])
			{
				return LARGE;
			}
			return SMALL;
		}
		return EQUAL;
	}
}
int BigNumber::getNumberLength() const
{
	return numberLength;
}
BigNumber BigNumber::operator * (const BigNumber& other)const
{
	if (!this)
		return BigNumber{};
	BigNumber resultBn{ "0" };
	resultBn.numberLength=numberLength* other.numberLength;
	resultBn.resize(resultBn.numberLength + 1);
	BigNumber counterBn{ "0" };
	counterBn.numberLength = other.numberLength;
	resultBn.makeBigNumberZero();
	counterBn.makeBigNumberZero();
	while (counterBn < other)
	{
		resultBn += *this;
		counterBn ++;
	}
	resultBn.removeZerosAtLeft();
	return resultBn;
}
BigNumber BigNumber::operator -(const BigNumber& other)const
{
	if (!this)
		return *this;
	BigNumber resultBn{ "0" };
	if (*this <= other)
		return resultBn;
	resultBn.numberLength = (numberLength> other.numberLength) ? numberLength : other.numberLength;
	resultBn.makeBigNumberZero();
	BigNumber bn2{ other };
	bn2.reLength(numberLength);
	int borrow = (number[numberLength - 1] < bn2.number[bn2.numberLength - 1]) ? 1 : 0;
	resultBn.number[resultBn.numberLength - 1] = (char)(((borrow * 10 + number[numberLength - 1]) - bn2.number[bn2.numberLength - 1]) + '0');
	int i = 1;
	char temp;
	int len = numberLength;
	while (i < len)
	{
		temp = number[numberLength - i - 1] - borrow;
		borrow = (temp< bn2.number[bn2.getNumberLength() - i - 1]) ? 1 : 0;
		resultBn.number[resultBn.getNumberLength() - i - 1] = (char)(((borrow * 10 + temp) - bn2.number[bn2.getNumberLength() - i - 1]) + '0');
		i++;
	}
	resultBn.removeZerosAtLeft();
	return resultBn;
}
BigNumber BigNumber::operator / (const BigNumber& other) const
{
	if (!this)
		return *this;
	BigNumber numeratorBN{ *this };
	if (*this < other)
	{
		BigNumber temp{ "0" };
		return temp;
	}
	BigNumber counterBn{ "0" };
	while (numeratorBN >= other)
	{
		//numeratorBN -= other;
		numeratorBN = (numeratorBN - other);
		++counterBn;
	}
	//counterBn.removeZerosAtLeft();
	return counterBn;
}
BigNumber BigNumber::operator %(const BigNumber& other) const
{
	if (!this)
		return *this;
	BigNumber numeratorBN{ *this };
	if (*this < other)
	{
		return *this;
	}
	BigNumber counterBn{ "0" };
	while (numeratorBN >= other)
	{
		//numeratorBN -= other;
		numeratorBN = (numeratorBN - other);
		++counterBn;
	}
	return numeratorBN;
}
void BigNumber::operator += (BigNumber& other)
{
	if (!this)
		return;
	*this = *this + other;
}
void BigNumber::operator -= (BigNumber& other)
{
	if (!this)
		return;
	*this = *this - other;
}
void BigNumber::operator *= (BigNumber& other)
{
	if (!this)
		return;
	*this = (*this) * other;
}
void BigNumber::operator /= (BigNumber& other)
{
	if (!this)
		return;
	*this = (*this / other);
}
BigNumber& BigNumber::operator ++ ()   //pre-increment
{
	if (!this)
		return *this;
	BigNumber temp{ "1" };
	*this = *this + temp;
	removeZerosAtLeft();
	return *this;
}
BigNumber BigNumber::operator ++ (int)   //post-increment
{
	if (!this)
		return *this;
	BigNumber oldNum{ *this };
	++(*this);
	return oldNum;
}
bool BigNumber::operator == (const BigNumber& other)const
{
	if (!this)
		exit(0);
	if (compare(other) == EQUAL)
		return true;
	return false;
}
bool BigNumber::operator >  (const BigNumber& other)const
{
	if (!this)
		exit(0);
	if (compare(other) == LARGE)
		return true;
	return false;
}
bool BigNumber::operator <  (const BigNumber& other)const
{
	if (!this)
		exit(0);
	if (compare(other) == SMALL)
		return true;
	return false;
}
bool BigNumber::operator >=  (const BigNumber& other)const
{
	if (!this)
		exit(0);
	if (compare(other) == LARGE || compare(other) == EQUAL)
		return true;
	return false;
}
bool BigNumber::operator <=  (const BigNumber& other)const
{
	if (!this)
		exit(0);
	if (compare(other) == SMALL || compare(other) == EQUAL)
		return true;
	return false;
}
bool BigNumber::operator != (const BigNumber& other)const
{
	if (!this)
		exit(0);
	if (compare(other) == EQUAL)
		return false;
	return true;
}
void BigNumber::shrink()
{
	if (!this)
		return;
	if ((getNumberLength() - getNumberLength()) >= 1)
	{
		resize(getNumberLength() + 1);  //1 is added in length to provide an index for placing null character.
		numberLength = getNumberLength();
	}
	//removeZerosAtLeft();
	//cout << "shrink() " << endl;
}
void BigNumber::removeZerosAtLeft()
{
	int i = 0;
	int len = getNumberLength();
	while ((i < len) && (number[i] == '0'))
	{
		i++;
	}
	if (i < (len - 1))
	{
		myMemCpy(number, &(number[i]), len - i + 1);
		setNumberLength(len - i);
		number[len - i] = '\0';
		shrink();
	}
}
void BigNumber::setNumberLength(const int l)
{
	if (!this)
		return;
	if (l >= 0)
		numberLength = l;
	//cout << "setNumberLength(const int l) " << endl;
}
void BigNumber::setNumberSize(const int size)
{
	if (!this)
		return;
	resize(size);
}
void BigNumber::reLength(int newLength)
{
	if (!this)
		return;
	if (newLength <= numberLength)
		return;
	char* temp = new char[newLength + 1];
	for (int i = 0; i < newLength - numberLength; i++)
		temp[i] = '0';
	myMemCpy(&(temp[newLength - numberLength]), number, numberLength);
	temp[newLength] = '\0';
	delete[] number;
	number = temp;
	setNumberLength(newLength);
}
void BigNumber::resize(int newLength)
{
	if (!this && number[0] != '\0')    //0th index can be '\0' and it can be given to us in order to increase its size
		return;
	char * tempData = new char[newLength];
	//myMemCpy(tempData, data, newSize);
	setNumberLength(newLength);
	int i = 0;
	//myMemCpy(tempData, number, getNumberLength());
	while ((i < newLength) && (number[i] != '\0'))
	{
		tempData[i] = number[i];
		i++;
	}
	*(tempData + i) = '\0';   // This statement is equal to tempData[i] = '\0';
	delete[] number;
	number = tempData;
	//removeZerosAtLeft();
	//cout << "resize(int newLength) " << endl;
}
void BigNumber::makeBigNumberZero()
{
	if (!this)
		return;
	int j;
	for (j = 0; j < numberLength; j++)
	{
		number[j] = '0';
	}
	number[j] = '\0';
}
void BigNumber::print()const
{
	if (!this)
		return;
	//	removeZerosAtLeft();
	int i = 0;
	while ((i < numberLength) && (number[i] != '\0'))
	{
		cout << (char)(number[i]);
		i++;
	}
	//cout << "print() " << endl;
}
void BigNumber::setNumber(const char* num)
{
	if (!this)
		return;
	number = (char*)num;
	setNumberLength(getLength(number));
	number = new char[numberLength + 1];
	myMemCpy(number, num, numberLength);
	number[numberLength] = '\0';
	removeZerosAtLeft();
}
bool BigNumber::operator !()const
{
	if (number[0] == '\0' || number)
		return true;
	return false;
	/*return (number[0] == '\0' || number);*/
}
void BigNumber::myMemCpy(void* dest, const void* src, int byteCount)
{
	int i;
	char* d = (char*)dest;
	const char* s = (const char*)src;
	if ((int)(&(d[byteCount - 1]) - (int)(s)))
	{
		for (i = 0; i < byteCount; i++)
		{
			d[i] = s[i];
		}
	}
}
int BigNumber::getLength(const char* num)
{
	if (!num)
		return 0;
	if (num[0] == '\0')
	{
		return 0;
	}
	int i = 1;
	while (num[i] != '\0')
	{
		i++;
	}
	//cout << "getLength() " << endl;
	return i;
}
istream& operator >> (istream& is, BigNumber& bn)
{
	bn.inputBigNumber();
	//cin >> bn.number;
	// but if i dont have member function to inpuct BigNumber then i can use cin>>bn.number instead of bn.inputBigNumber().
	return is;
}
ostream& operator << (ostream& os, const BigNumber& bn)
{
	bn.print();
	return os;
}
