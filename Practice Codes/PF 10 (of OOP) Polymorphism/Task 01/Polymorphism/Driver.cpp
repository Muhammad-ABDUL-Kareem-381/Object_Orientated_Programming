#include"Driver.h"
Ship** Driver::createArray()
{
	int size = 4;
	Ship** p;
	p = new Ship * [size];
	return p;
}
void Driver::driveApp()
{
	Ship**p=createArray();
	int size = 4;
	p[0] = new Ship{"Badar","2012"};
	p[1] = new CruiseShip{"Badar","2010",100};
	p[2] = new CargoShip{"Hilal","2018",100};
	p[3] = new BattleShip{"Saif","2021",791};
	for (int i = 0; i < size; i++)
	{
		p[i]->print();
		cout << '\n';
	}
	freeMemory(p);
}
void Driver::freeMemory(Ship**& p)			// destructor id needed if instance ie. object of class is made but here
{
	for (int i = 0; i < 4; i++)
	{
		delete p[i];		// delete each object explicitly
	}
	delete[] p;		// delete array (made on heap)  of pointers 
	p = nullptr;
}
//Driver::~Driver()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		delete p[i];		// delete each object explicitly
//	}
//	delete [] p;		// delete array (made on heap)  of pointers 
//	p = nullptr;
//}
//void Driver::reSize(int newSize)
//{
//	if (newSize <= 0)
//	{
//		this->~Driver();
//	}
//	Ship ** temp;
//	temp = new Ship* [newSize] ;
//	int smallerSize = (newSize > size) ? size : newSize;
//	for (int i = 0; i < smallerSize; i++)
//	{
//		temp[i] = p[i];
//	}
//	delete[] p;    // don't invoke destructor of class here coz destructor will not only delete the array of pointers
//	// but also in destructor there is logic to delete each cobject coz objects are also on heap. So just array deletion.
//	p = temp;
//	size = newSize;
//}