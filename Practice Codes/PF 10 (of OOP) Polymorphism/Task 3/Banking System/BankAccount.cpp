#include"BankAccount.h"
BankAccount::BankAccount(const String& cus, long long int bal, float rate, CustomerType type):customer(cus), balance(bal), interestRate(rate), cusType(type)
{}
long long int BankAccount::calculateInterest(int months)
{
	if (months <= 0)
	{
		return 0;
	}
	return balance * (1 + interestRate * months);
}
String& BankAccount::getCustomer()
{
	return customer;
}
long long int& BankAccount::getBalance()
{
	return balance;
}
float& BankAccount::getInterestRate()
{
	return interestRate;
}
CustomerType& BankAccount::getCusType()
{
	return cusType;
}
void BankAccount::deposit(long long int rs)
{
	if (rs <= 0)
	{
		return;
	}
	balance += rs;
}