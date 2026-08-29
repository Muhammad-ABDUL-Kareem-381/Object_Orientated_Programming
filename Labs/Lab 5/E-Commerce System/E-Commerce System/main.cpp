#include "Customer.h"
#include "Vendor.h"
int main()
{
	Customer c1{ "umair","umair@yahoo.com","vendorpass" ,"lhr","Card" };
	c1.addToCart("laptop");
	c1.addToCart("mouse");
	Vendor v1{ "umair","umair@yahoo.com","vendorpass" , "tech store" };
	v1.addItemtoInventory("laptop");
	v1.addItemtoInventory("mouse") ;
	v1.addItemtoInventory("tv");
	v1.addItemtoInventory("lcd");
	//v1.displayVendorInfo();
	cout<<c1.placeOrder(v1);
	v1.displayVendorInfo();
}