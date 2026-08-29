#include"DepositAccount.h"
#include"LoanAccount.h"
#include "MortgageAccount.h"
int main()
{
	MortgageAccount ba1{ "Oil Limited company",230,1/100.0,Individual};
	DepositAccount ba2{ "Oil Limited company",230,1 / 100.0,Individual };
	LoanAccount ba3{ "Oil Limited company",230,1 / 100.0,Individual };
	BankAccount* p = &ba1, * q = &ba2, * r = &ba3;

	cout<<p->calculateInterest(7)<<'\n';
	cout << q->calculateInterest(7) << '\n';
	cout << r->calculateInterest(7) << '\n';

}