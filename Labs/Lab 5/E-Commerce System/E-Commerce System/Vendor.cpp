#include"Vendor.h"
Vendor::Vendor() :inventory(nullptr), sizeOfInventory(0)
{}
Vendor::Vendor(const String& userN, const String& mail, const String& password, const String& store) : User(userN, mail, password)
{
	resetFactoryVersion();
	if (!store)
	{
		return;
	}
	storeName = store;
	inventory = new String[sizeOfInventory];
}
Vendor::Vendor(const User& user, const String& store) : User(user)
{
	resetFactoryVersion();
	if (!storeName)
	{
		return;
	}
	storeName = store;
	inventory = new String[sizeOfInventory];
}
Vendor::Vendor(const Vendor& ref) :User(ref)
{
	if (!(&ref))
	{
		return;
	}
	storeName = ref.storeName;
	sizeOfInventory = ref.sizeOfInventory;
	inventory = new String[sizeOfInventory];
	for (int i = 0; i < sizeOfInventory; i++)
	{
		inventory[i] = (ref.inventory)[i];
	}
}
void Vendor::resetFactoryVersion()
{
	sizeOfInventory = 0;
	inventory = nullptr;
}
void Vendor::reSize(const int newSize)
{
	if (newSize <= 0)
	{
		delete[] inventory;
		inventory = nullptr;
		sizeOfInventory = 0;
		return;
	}
	String* temp = new String[newSize];
	int smallerSize = (newSize < sizeOfInventory) ? newSize : sizeOfInventory;
	for (int i = 0; i < smallerSize; i++)
	{
		temp[i] = inventory[i];
	}
	delete[] inventory;
	sizeOfInventory = newSize;
	inventory = temp;
}
String& Vendor::getStoreName()
{
	return storeName;
}
int Vendor::getSizeOfInventory()const
{
	return sizeOfInventory;
}
bool Vendor::isItemAvailable(const String& item)
{
	if (!item || !inventory || !sizeOfInventory)
	{
		return false;
	}
	for (int i = 0; i < sizeOfInventory; i++)
	{
		if ((inventory[i] == item) ==0)
		{
			return true;
		}
	}
	return false;
}
bool Vendor::addItemtoInventory(const String& item)
{
	if (isItemAvailable(item))
	{
		return false;
	}
	reSize(sizeOfInventory + 1);
	inventory[sizeOfInventory - 1] = item;
	return true;
}
void Vendor::removeItemfromInventory(const String& item)
{
	if (!isItemAvailable(item))
	{
		return;
	}
	int i;
	for (i = 0; i < sizeOfInventory; i++)
	{
		if ((inventory[i] == item)==0)
		{
			break;
		}
	}
	inventory[i] = inventory[sizeOfInventory - 1];
	reSize(sizeOfInventory - 1);
}
void Vendor::displayVendorInfo()
{
	if (!this)
	{
		return;
	}
	displayUserInfo();
	cout << "\nStore Name: " << storeName<<"\nInventory:";
	for (int i = 0; i < sizeOfInventory; i++)
	{
		cout << '\n' << i + 1 << ":\t" << inventory[i];
	}
}
Vendor::~Vendor()
{
	if (!this)
	{
		return;
	}
	delete[] inventory;
	inventory = nullptr;
	sizeOfInventory = 0;
}