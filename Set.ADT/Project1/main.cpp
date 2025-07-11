#include "Set.h"
int main()
{
	Set A, B;
	cout << '1' << '\n';
	A.setCapacity(10);
	cout << '2' << '\n';
	A.setNoe(0);
	cout << '3' << '\n';
	for (int i = 0; i < A.getCapacity(); i++)
	{
		cout << i << '\t';
		cout<< boolalpha<<A.addElement(i);
	}
	cout << '4' << '\n';
	cout << "comp\n";
	cout << '5' << '\n';
	A.displaySet();
	cout << '6' << '\n';
	//cout << A;
	return 0;
	cout << "Enter set A:\t";
	cin >> A;
	cout << "Enter set B:\t";
	cin >> B;
	//int capacityForUnion =
	Set unionSet = A.calculateUnion(B, 12);
	cout << "\nUnion Result:\t" << unionSet << "\nEnd";
}