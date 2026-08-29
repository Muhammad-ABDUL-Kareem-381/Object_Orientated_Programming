#include "User.h"
User::User()
{}
User::User(const String& userN, const String& mail, const String& password) :User()
{
	if (!userN || !mail || !password)
	{
		return;
	}
	username = userN;
	email = mail;
	this->password = password;
}
String& User::getUsername()
{
	return username;
}
String& User::getEmail()
{
	return email;
}
String& User::getPassword()
{
	return password;
}
bool User::login(const String& userN, const String& mail, const String& password)
{
	if (!userN || !mail || !password)
	{
		return false;
	}
	if ((userN == username) && (mail == email) && (password == this->password))
	{
		return true;
	}
	return false;
}
void User::displayUserInfo()
{
	if (!username || !email || !password)
	{
		return;
	}
	cout << "Username: " << username << "\nEmail: " << email ;
}