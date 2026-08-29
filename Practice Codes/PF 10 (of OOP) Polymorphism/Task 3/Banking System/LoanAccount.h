#ifndef LOAN_ACCOUNT_H
#define LOAN_ACCOUNT_H
#include "BankAccount.h"
class LoanAccount:public BankAccount
{
public:
	using BankAccount::BankAccount;
	long long int calculateInterest(int months);
};
#endif