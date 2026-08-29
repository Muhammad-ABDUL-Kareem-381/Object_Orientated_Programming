#ifndef EMAIL_H
#define EMAIL_H
#include"Document.h"
class Email : protected Document
{
	String sender;
	String recipient;
	String title;
public:
	//friend ostream& operator << (ostream& os, Email& email);
	Email();
	Email(const String& s, const String& r, const String& t, const String& mes);
	void setSender(String& s);
	void setRecipient(String& r);
	void setTitle(String& t);
	String getSender() const;
	String getRecipient() const;
	String getTitle() const;
	void setMessage(String& mes);
	String toString() const;
};
#endif