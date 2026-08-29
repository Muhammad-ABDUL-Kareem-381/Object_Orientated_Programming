#ifndef FILE_H
#define FILE_H
#include "Document.h"
class File: protected Document
{
	String pathName;
	String fileName;
	using Document::toString;
public:
	//friend ostream& operator << (ostream& os, File& f);
	File();
	File(const String& p, const String& f, const String & mes);
	void setPathName(String& p);
	void setFileName(String& f);
	String getPathName() const;
	String getFileName() const;
	String toString(int n) const;
};
#endif