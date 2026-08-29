#ifndef DEPOSIT_ACCOUNT_H
#define DEPOSIT_ACCOUNT_H
#include"BankAccount.h"
class DepositAccount : public BankAccount
{
public:
	using BankAccount::BankAccount;
	void withdraw(long long int rs);
	long long int calculateInterest(int months);
};
#endif