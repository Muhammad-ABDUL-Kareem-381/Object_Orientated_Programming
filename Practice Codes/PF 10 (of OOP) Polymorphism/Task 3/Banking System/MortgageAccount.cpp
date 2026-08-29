#include"MortgageAccount.h"
long long int MortgageAccount::calculateInterest(int months)
{
	if (getCusType() == Company)
	{
		if (months >= 0 && months <= 12)
		{
			getInterestRate() = 0.5 / 100;       // divided by 100 means per cent (ie. per 100 )
		}
	}
	else							// for "individual" block
	{
		if (months >= 0 && months <= 6)
		{
			return getBalance();
		}
	}
	return BankAccount::calculateInterest(months);
}