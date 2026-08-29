#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include"D:/Academics/OOP 2.0/Labs/Lab 4/String.ADT/String3.ADT/String.h"
enum CustomerType {Individual, Company};
class BankAccount
{
	String customer;
	long long int balance;
	float interestRate;
	CustomerType cusType;
public:
	BankAccount(const String& cus, long long int bal, float rate, CustomerType type);
	String& getCustomer();
	long long int& getBalance();
	float& getInterestRate();
	CustomerType& getCusType();
	virtual long long int calculateInterest(int months);
	void deposit(long long int rs);
};
#endif