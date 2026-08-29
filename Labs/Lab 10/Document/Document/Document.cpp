#include"Document.h"
#include <iostream>
using namespace std;
Document::Document()
{
}
Document::Document(const String& t):text{t}
{
}
void Document::setText(String& t)
{
	text = t;
}
String Document::getText() const
{
	cout << "\nDocument.getText()";
	return text;
}
String Document::toString() const
{
	cout << "\nDocument.toString()";
	return text;
}
//ostream& operator << (ostream& os, Document& d)
//{
//	d.display();
//	return os;
//}

