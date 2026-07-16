#include "BigNumber.h"
int main()
{
	BigNumber bn1{ "5" }, bn2{ "5" };
	cout << (bn1 - bn2);
	return 0;
}