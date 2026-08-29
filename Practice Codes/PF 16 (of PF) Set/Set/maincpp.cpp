#include<iostream>
using namespace std;
class Set
{
public:
	int* set;
	int NOE;
	int capacity;
	void createSet()
	{
		if (capacity <= 0)
		{
			return;
		}
		set = new int[capacity];
	}
	bool addElement(int element)
	{
		if ((!set) || searchElement( element))
		{
			return false;
		}
		if (isFull())
		{
			reSize(&set, noe, &capacity, *noe + 5);
		}
		set[NOE] = element;
		NOE = NOE + 1;
		return true;
	}
	int searchElementPosition(int element)
	{
		if ((!set) || isEmpty())
		{
			return -1;
		}
		for (int i = 0; i < NOE; i++)
		{
			if (set[i] == element)
			{
				return i;
			}
		}
		return -1;
	}
	bool searchElement(int element)
	{
		if (searchElementPosition(element) >= 0)
		{
			return true;
		}
		return false;
	}
	void reSize(int newSize)
	{
		if ((!(set)) || (newSize < 0))
		{
			return;
		}
		Set temp;
		temp.NOE = 0;
		temp.capacity = newSize;
		temp.createSet();
		capacity = newSize;
		for (int i = 0; i < NOE; i++)
		{

		}
		/*int* temp, tempNoe=0;
		creatClone(*setA, *setANoe,0, &temp, &tempNoe, &newSize);
		delete[] * setA;
		*setA = temp;
		*setACapacity = newSize;
		*setANoe = (*setANoe > *setACapacity) ? *setACapacity : *setANoe;*/
	}
	void creatClone(Set targetSet)
	{
		if ((!capacity) || (!set))
		{
			return;
		}
		targetSet.capacity = capacity;
		targetSet.createSet();
		for (int i = 0; i < NOE; i++)
		{
			(targetSet.set)[i] = set[i];
		}
		targetSet.NOE = NOE;
	}
	bool removeElement(int element)
	{
		if (isEmpty())
		{
			return false;
		}
		if (!searchElement(element))
		{
			return false;
		}
		int elementPosition = searchElementPosition(element);
		set[elementPosition - 1] = set[NOE - 1];
		NOE = NOE - 1;
		return true;
	}
	bool isEmpty()
	{
		return (NOE > 0) ? false : true;
	}
	bool isFull()
	{
		return (NOE == capacity) ? true : false;
	}
	void displaySet()
	{
		if (NOE < 0)
		{
			return;
		}
		cout << '{';
		for (int i = 0; i < (NOE - 1); i++)
		{
			cout << set[i] << ',';
		}
		if (NOE - 1 >= 0)
		{
			cout << set[NOE - 1];
		}
		cout << '}';
	}
	Set calcIntersection(Set setB, Set res)
	{
		if (isEmpty() || setB.isEmpty())
		{
			return ;
		}
		res.capacity = (NOE < setB.NOE) ? NOE : setB.NOE;
		res.NOE = 0;
		res.createSet();
		for (int i = 0; i < NOE; i++)
		{
			if (setB.searchElement(set[i]))
			{
				res.set[NOE] = set[i];
				res.NOE = res.NOE + 1;
			}
		}
		return res;
	}
	int* calcUnion(int* setA, int* setB, int setANoe, int setBNoe, int* newSetNoe, int* newSetCapacity)
	{
		int* newSet;
		creatClone(setA, setANoe, setANoe, &newSet, newSetNoe, newSetCapacity);
		if (isEmpty(setBNoe))
		{
			return newSet;
		}
		if (isEmpty(setANoe))
		{
			creatClone(setB, setBNoe, setBNoe, &newSet, newSetNoe, newSetCapacity);
			return newSet;
		}
		reSize(&newSet, newSetNoe, newSetCapacity, setANoe + setBNoe);
		int j = 0;
		// j is to place B's elements (which are not in A) in new set.
		for (int i = 0; i < setBNoe; i++)
		{
			if (!searchElement(newSet, *newSetNoe, setB[i]))
			{
				newSet[*newSetNoe + j] = setB[i];
				*newSetNoe = *newSetNoe + 1;
				j++;
			}
		}
		return newSet;
	}
	int* calcDifference(int* setA, int* setB, int setANoe, int setBNoe, int* newSetNoe, int* newSetCapacity)
	{
		if (isEmpty(setANoe))
		{
			return nullptr;
		}
		int* newSet;
		*newSetCapacity = setANoe;
		*newSetNoe = 0;
		createSet(&newSet, *newSetCapacity);
		for (int i = 0; i < setANoe; i++)
		{
			if (!searchElement(setB, setBNoe, setA[i]))
			{
				newSet[*newSetNoe] = setA[i];
				*newSetNoe = *newSetNoe + 1;
			}
		}
		return newSet;
	}
	int isSubset(int* setA, int* setB, int setANoe, int setBNoe)
	{
		for (int i = 0; i < setBNoe; i++)
		{
			if (!searchElement(setA, setANoe, setB[i]))
			{
				return 0;
			}
		}
		if (setANoe == setBNoe)
		{
			return 2;
		}
		return 1;
	}
	void deallocateSet(int** set)
	{
		delete[] * set;
		*set = nullptr;
	}
	void displayCrossProduct(int* setA, int setANoe, int* setB, int setBNoe)
	{
		cout << '{';
		for (int i = 0; i < setANoe; i++)
		{
			for (int j = 0; j < setBNoe; j++)
			{
				cout << '(' << setA[i] << ',' << setB[j] << ')';
				cout << ',';
			}
		}
		cout << '}';
	}
};
int main()
{
	int *setA=nullptr;
	int setANoe = 0,setACapacity=2;
	createSet(&setA, setACapacity);
	addElement(setA, &setANoe, setACapacity, 1);
	addElement(setA, &setANoe, setACapacity, 2); 
	addElement(setA, &setANoe, setACapacity, 3);
	addElement(setA, &setANoe, setACapacity, 4);
	addElement(setA, &setANoe, setACapacity, 5);
	displaySet(setA, setANoe);
	return 0;
}
