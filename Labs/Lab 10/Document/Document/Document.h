#ifndef DOCUMENT_H
#define DOCUMENT_H
#include"String.h"
class Document
{
	String text;
public:
	//friend ostream& operator << (ostream& os, Document& d);
	Document();
	Document(const String & t);
	void setText(String& t);
	String getText() const;
	String toString() const;
};
#endif