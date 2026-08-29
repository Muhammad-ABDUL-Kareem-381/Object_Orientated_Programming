#ifndef VENDOR_H
#define VENDOR_H
#include"User.h"
class Vendor : public User
{
	String storeName;
	String* inventory;
	int sizeOfInventory;
	void resetFactoryVersion();
	void reSize(const int newSize);
public:
	Vendor();
	Vendor(const String& userN, const String& mail, const String& password, const String& store);
	Vendor(const User& user, const String& store);
	Vendor(const Vendor& ref);
	String& getStoreName();
	int getSizeOfInventory()const;
	bool isItemAvailable(const String& item);
	bool addItemtoInventory(const String& item);
	void removeItemfromInventory(const String& item);
	void displayVendorInfo();
	~Vendor();
};
#endif