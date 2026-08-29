#include "Customer.h"
#include"Vendor.h"
Customer::Customer() :cart(nullptr), sizeOfCart(0)
{}
Customer::Customer(const String& userN, const String& mail, const String& password, const String& add, const String& method) :User(userN, mail, password)
{
	resetFactoryVersion();
	if (!add || !method)
	{
		return;
	}
	shippingAddress = add;
	paymentMethod = method;
	cart = new String[sizeOfCart];
}
Customer::Customer(const User& user, const String& add, const String& method) :User(user)
{
	resetFactoryVersion();
	if (!add || !method)
	{
		return;
	}
	shippingAddress = add;
	paymentMethod = method;
	if (!add || !method)
	{
		return;
	}
	cart = new String[sizeOfCart];
}
Customer::Customer(const Customer& ref) :User(ref)
{
	if (!(&ref))
	{
		return;
	}
	sizeOfCart = ref.sizeOfCart;
	shippingAddress = ref.shippingAddress;
	paymentMethod = ref.paymentMethod;
	cart = new String[sizeOfCart];
	for (int i = 0; i < sizeOfCart; i++)
	{
		cart[i] = (ref.cart)[i];
	}
}
void Customer::resetFactoryVersion()
{
	cart = nullptr;
	sizeOfCart = 0;
}
void Customer::reSize(const int newSize)
{
	if (newSize <= 0)
	{
		delete [] cart;
		sizeOfCart = 0;
		cart = nullptr;
		return;
	}
	String* temp = new String[newSize];
	int smallerSize = (newSize < sizeOfCart) ? newSize : sizeOfCart;
	for (int i = 0; i < smallerSize; i++)
	{
		temp[i] = cart[i];
	}
	delete [] cart;
	sizeOfCart = newSize;
	cart=temp;
}
String& Customer::getShippingAddress()
{
	return shippingAddress;
}
String& Customer::getPaymentMethod()
{
	return paymentMethod;
}
int& Customer::getSizeOfCart()
{
	return sizeOfCart;
}
bool Customer::placeOrder(Vendor& vendor)
{
	int i = 0;
	while (i < sizeOfCart)
	{
		if (!vendor.isItemAvailable(cart[i]))
		{
			return false;
		}
		i++;
	}
	i = 0;
	while (i < sizeOfCart)
	{
		vendor.removeItemfromInventory(cart[i]);
		i++;
	}
	return true;
}
bool Customer::addToCart(const String& item)
{
	if ((bool ) item)
	{
		reSize(sizeOfCart + 1);
		cart[sizeOfCart - 1]=item;
		return true;
	}
	return false;
}
void Customer::viewCart() const
{
	if (!cart)
	{
		return;
	}
	cout << "Items in cart:\n";
	for (int i = 0; i < sizeOfCart; i++)
	{
		cout << (i + 1) << ":\t" << cart[i] << '\n';
	}
}
void Customer::displayCustomerInfo()
{
	displayUserInfo();
	cout << "\nShipping Address: " << shippingAddress << '\n';
	cout << "Payment Method: " << paymentMethod;
}
Customer::~Customer()
{
	if (!cart)
	{
		return;
	}
	delete[] cart;
	cart = nullptr;
	sizeOfCart = 0;
}