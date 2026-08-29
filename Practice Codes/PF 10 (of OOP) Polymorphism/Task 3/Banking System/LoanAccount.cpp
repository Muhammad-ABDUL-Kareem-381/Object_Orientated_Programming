#include"LoanAccount.h"
long long int LoanAccount::calculateInterest(int months)
{
	if (getCusType() == Individual)
	{
		return (months <= 3 && months >= 0)? getBalance(): BankAccount::calculateInterest(months);
	}
	else
	{
		return (months <= 2 && months >= 0) ? getBalance(): BankAccount::calculateInterest(months);
	}
}