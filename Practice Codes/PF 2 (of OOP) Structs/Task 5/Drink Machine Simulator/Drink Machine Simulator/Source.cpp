#include<iostream>
using namespace std;
struct DrinkMachineSimulator
{
	char drinkName[50];
	float drinkCost;
	int numberOfDrinks;
};
void copyCharArray(const char* src, char* tar);
void initializeOneDrink(DrinkMachineSimulator*, const char *, float );
void initializeAllDrinks(DrinkMachineSimulator* drinks);
float purchaseDrink(DrinkMachineSimulator * , char);
int main()
{
	DrinkMachineSimulator drinks[5];
	initializeAllDrinks(drinks);
		for (int i = 0; i < 5; i++)
	{
		cout << i+1<<' '<< drinks[i].drinkName << '\n';
	}
	cout << "Enter a number to select a drink.";
	cout << "\nEnter q to quit the application.";
	char choice;
	cin.get(choice);
	float money;
	float earnedMoney = 0;
	float remainingAmount;
	do
	{
		switch (choice)
		{
		case '1':case '2': case '3': case '4': case '5':
			remainingAmount= purchaseDrink(drinks, choice);
			if (remainingAmount == -1)
			{
				cout << "All drinks are sold out.";
				break;
			}
			earnedMoney = earnedMoney + drinks[choice + '0'].drinkCost;
			cout << "Remaining amount:" << remainingAmount;
			//delete &remainingAmount;
			break;
		default:
			break;
		}
	}
	while (choice != 'q');
	cout << "Total earning: " << earnedMoney;
}
void initializeOneDrink(DrinkMachineSimulator* drink, const char* name, float cost)
{
	copyCharArray(name, drink->drinkName);
	drink->drinkCost = cost;
	drink->numberOfDrinks = 20;
}
void copyCharArray(const char* src, char* tar)
{
	int i = 0;
	while (src[i] != '\0')
	{
		tar[i] = src[i];
		i++;
	}
	tar[i] = '\0';
}
void initializeAllDrinks(DrinkMachineSimulator* drinks)
{
	//DrinkMachineSimulator drinks[5];
	initializeOneDrink(&(drinks[0]), "Cola", 0.75);
	initializeOneDrink(&(drinks[1]), "Root Beer", 0.75);
	initializeOneDrink(&(drinks[2]), "Lemon-Lime", 0.75);
	initializeOneDrink(&(drinks[3]), "Grape-Soda", 0.80);
	initializeOneDrink(&(drinks[4]), "Cream-Soda", 0.80);
}
float purchaseDrink(DrinkMachineSimulator* drinks, char drinkNum)
{
	drinkNum = drinkNum;
	float money;
	if (drinks[drinkNum].numberOfDrinks == 0)
	{
		return -1;
	}
	do
	{
		cout << "Enter amount:";
		cin >> money;
	} 
	while ((money < 0) || (money > 1) || (money < 0.75));
	drinks[drinkNum].numberOfDrinks = drinks[drinkNum].numberOfDrinks - 1;
	return (money - drinks[drinkNum].drinkCost);
}
