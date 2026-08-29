#include"file.h"
File::File()
{

}
File::File(const String& p, const String& f, const String& mes): Document(mes), pathName(p), fileName(f)
{}
void File::setPathName(String& p)
{
	pathName = p;
}
void File::setFileName(String& f)
{
	fileName = f;
}
String File::getPathName() const
{
	return pathName;
}
String File::getFileName() const
{
	return fileName;
}
String File::toString(int n) const
{
	cout << "\nFile.toString()";
	String temp = "File Path: ";
	temp += pathName + "\nFile Name: " + fileName + "\nContents: " + getText();
	return temp;
}
//ostream& operator << (ostream& os, File& f)
//{
//	f.display();
//	return os;
//}