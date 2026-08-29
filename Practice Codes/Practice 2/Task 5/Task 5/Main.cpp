#include<iostream>
#include<iomanip>
using namespace std;
struct SoftDrink
{
	char name[50];
	double cost;
	int noOfDrinks;
};
void softDrinkMachineSimulator();
void printList(SoftDrink* ref,int type);
void selectSoftDrink(int & decision);
bool isValidDecision(int decision);
bool isDrinkAvailable(int quantity);
void checkAmount(double& amount, double a);
void inputAmount(int decision, double& amount, SoftDrink* a);

int main()
{
	softDrinkMachineSimulator();
	return 0;
}
void softDrinkMachineSimulator()
{
	int decision = 0;
	double totalAmount = 0.0;
	bool result1,result2;
	SoftDrink info[5] = { "Cola",0.75,20,"Roor Beer",0.75,20,"Lemon-Lime",0.75,20,"Grape Soda",0.80,20,"Cream Soda",0.80,20 };
	do
	{
		double amount = 0.0;
		printList(info, 5);
		selectSoftDrink(decision);
		if (isValidDecision(decision))
		{
			if (isDrinkAvailable(info[decision-1].noOfDrinks))
			{
				inputAmount(decision, amount,info);

			}
			else
			{
				cout << "The selected drink is soled out";
			}
		}



	} while (decision != 0);
	cout << "The total amount is = " << totalAmount << "\n";
}
void printList(SoftDrink* ref, int type)
{
	cout << setw(20) << left << setfill(' ') << "Drink Name" << setw(19) << setfill(' ') << "cost" << setw(30) << setfill(' ') << "Number in Machine" << "\n";
	for (int i = 0; i < type; i++)
	{
		cout << setw(20) << left << setfill(' ') << ref[i].name << setw(19) << setfill(' ') << ref[i].cost << setw(30) << setfill(' ') << ref[i].noOfDrinks << "\n";
	}
}
void selectSoftDrink(int& decision)
{
	cout << "\n1 for cola" << "\n";
	cout << "2 for Roor Bear" << "\n";
	cout << "3 for Leamon Lime" << "\n";
	cout << "4 for Grape Soda" << "\n";
	cout << "5 for Cream Soda" << "\n";
	cout << "0 for exit" << "\n";
	cout << "Enter your decision = ";
	cin >> decision;
}
bool isValidDecision(int decision)
{
	return (decision > 0 && decision < 6) ? true : false;
}
bool isDrinkAvailable(int quantity)
{
	return (quantity > 0) ? true : false;
}
void inputAmount(int decision, double& amount, SoftDrink*a)
{
	cout << "Enter the amount ";
	cin >> amount;
	checkAmount(amount, a[decision- 1].cost);
}
void checkAmount(double& amount, double a)
{
	if (amount < a || amount>1.00)
	{
		do
		{
			cout << "invalid amount " << "\n";
			cout << "enter again: ";
			cin >> amount;
		} 
		while (amount < a || amount>1.00);
	}
}