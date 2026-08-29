#include "File.h"
#include "Email.h"
#include "SearchRoutines.h"
int main()
{
	//String d[2]{ String{"hello"},String{"word"} };
	Email emailObj{ "bsef23m001", "bsef23m002", "My Friend", "You're my best manners." };
	File fileObj{"c:\\abc\\work\\file.txt", "Test.txt", "//This is some sample text in a file containig C++ code.\nbool ContainsKeyword(const Document & docObject, const String & keyword)\n{\n\treturn true;\n}" };
	emailObj.toString();// .display();
	fileObj.toString(123);// .display();
	/*if (SearchRoutines::containsKeyword(emailObj, "manners"))
		cout << "\nThe email contains the keyword 'manners'." << '\n';
	else
		cout << "\nThe email  does NOT contain the keyword 'manners'." << '\n';
	if (SearchRoutines::containsKeyword(fileObj, "manners"))
		cout << "The file contains the keyword 'manners'." << '\n';
	else
		cout << "The file does NOT contain the keyword 'manners'." << '\n'; */
	cout << '\n';
	//emailObj.getText();
	return 0;
	return 0;
}