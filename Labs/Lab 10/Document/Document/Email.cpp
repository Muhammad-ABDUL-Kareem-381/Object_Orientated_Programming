#include "Email.h"
#include<iostream>
using namespace std;
Email::Email()
{}
Email::Email(const String& s, const String& r, const String& t, const String& mes) :Document(mes), sender(s), recipient(r), title(t)
{}
void Email::setSender(String& s)
{
	sender = s;
}
void Email::setRecipient(String& r)
{
	recipient = r;
}
void Email::setTitle(String& t)
{
	title = t;
}
String Email::getSender() const
{
	return sender;
}
String Email::getRecipient() const
{
	return recipient;
}
String Email::getTitle() const
{
	return title;
}
void Email::setMessage(String& mes)
{
	setText(mes);
}
String Email::toString() const
{
	getText();
	cout << "\nEmail.toString()";
	String temp = "Sender: ";
	temp += sender + "\nRecipient: " + recipient + "\nTitle: " + title + "\nMessage: " + getText() + "\n";
	return temp;
}
//ostream& operator << (ostream& os, Email& email)
//{
//	email.display();
//	return os;
//}
