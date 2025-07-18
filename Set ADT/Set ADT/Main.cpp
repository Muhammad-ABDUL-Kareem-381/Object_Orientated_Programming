#include"Set.h"

//int main()
//{
//	//Set a;
//	//a.createSet();
//	//a.setCapacity(10);
//	//a.inputSet(5);
//	//a.addelement(10);
//	//a.removeelement(3);
//	//a.searchelement(5) ? cout << "element found.\n" : cout << "element not found.\n";
//	//a.searchelementposition(5) != -1 ? cout << "element found at position: " << a.searchelementposition(5) << "\n" : cout << "element not found.\n";
//	//a.isempty() ? cout << "set is empty.\n" : cout << "set is not empty.\n";
//	//a.isfull() ? cout << "set is full.\n" : cout << "set is not full.\n";
//	//a.displaySet();
//
//
//	return 0;
//}


#include "Set.h"

int main()
{
    Set A, B;

    // Prepare Set A
    A.setCapacity(10);
    A.setNoe(0);
    for (int i = 1; i <= 5; i++)  // A = {1, 2, 3, 4, 5}
        A.addElement(i);

    // Prepare Set B
    B.setCapacity(10);
    B.setNoe(0);
    for (int i = 3; i <= 7; i++)  // B = {3, 4, 5, 6, 7}
        B.addElement(i);

    cout << "Set A: " << A << endl;
    cout << "Set B: " << B << endl;

    // UNION
    Set unionSet = A.calculateUnion(B, 20);
    cout << "A ∪ B: " << unionSet << endl;

    // INTERSECTION
    Set intersectionSet = A.calcIntersection(B, 10);
    cout << "A ∩ B: " << intersectionSet << endl;

    // DIFFERENCE A - B
    Set differenceAB = A.calculateDifference(B, 10);
    cout << "A - B: " << differenceAB << endl;

    // DIFFERENCE B - A
    Set differenceBA = B.calculateDifference(A, 10);
    cout << "B - A: " << differenceBA << endl;

    // SUBSET CHECK
    cout << "Is A a subset of B? " << boolalpha << A.isSubset(B) << endl;
    cout << "Is B a subset of A? " << boolalpha << B.isSubset(A) << endl;

    return 0;
}
