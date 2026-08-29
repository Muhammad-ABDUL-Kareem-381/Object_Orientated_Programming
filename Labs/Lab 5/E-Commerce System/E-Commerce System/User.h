#ifndef USER_H
#define USER_H
#include "D:\Academics\OOP 2.0\Labs\Lab 4\String.ADT\String3.ADT\String.h"
class User
{
	String username;
	String email;
	String password;
public:
	User();
	User(const String& userN, const String& mail, const String& password);
	String& getUsername();
	String& getEmail();
	String& getPassword();
	bool login(const String& userN, const String& mail, const String& password);
	void displayUserInfo();
};
#endif