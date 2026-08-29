#ifndef MORTGAGE_ACCOUNT_H
#define MORTGAGE_ACCOUNT_H
#include"BankAccount.h"
class MortgageAccount :public BankAccount
{
public:
	using BankAccount::BankAccount;
	long long int calculateInterest(int month);
};
#endif