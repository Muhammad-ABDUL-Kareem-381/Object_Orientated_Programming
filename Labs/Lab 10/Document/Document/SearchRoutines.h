#ifndef SEARCH_ROUTINES_H
#define SEARCH_ROUTINES_H
#include "String.h"
#include "Document.h"
class SearchRoutines//: public String
{
public:
	static bool containsKeyword(const Document& docObject, const String& keyWord);
};
#endif
