#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"User.h"
class Vendor;
class Customer :public User
{
	String shippingAddress;
	String paymentMethod;
	String * cart;
	int sizeOfCart;
	void resetFactoryVersion();
	void reSize(const int newSize);
public:
	Customer();
	Customer(const String& userN, const String& mail, const String& password, const String& add, const String& method);
	Customer(const User& user, const String& add, const String& method);
	Customer(const Customer& ref);
	String& getShippingAddress();
	String& getPaymentMethod();
	int& getSizeOfCart();
	bool addToCart(const String& item);
	bool placeOrder(Vendor& vendor);
	void viewCart() const;
	void displayCustomerInfo();
	~Customer();
};
#endif