#include "DepositAccount.h"
void DepositAccount::withdraw(long long int rs)
{
	if (rs > 0 && rs <= getBalance())
	{
		getBalance() = getBalance() - rs;
	}
}
long long int DepositAccount::calculateInterest(int months)
{
	if (getBalance() > 0 && getBalance() < 1000)
	{
		return getBalance();
	}
	return BankAccount::calculateInterest(months);
}