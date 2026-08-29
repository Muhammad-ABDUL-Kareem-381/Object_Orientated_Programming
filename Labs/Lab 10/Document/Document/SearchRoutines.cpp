#include "SearchRoutines.h"
#include "String.h"
//static bool SearchRoutines::containsKeyword(const Document& docObject, const String& keyWord);
bool SearchRoutines::containsKeyword(const Document& docObject, const String& keyWord)
{
	if (docObject.getText().find(keyWord)!=-1)
	{
		return true;
	}
	return false;
}
