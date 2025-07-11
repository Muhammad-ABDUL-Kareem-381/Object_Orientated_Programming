#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H
#include<iostream>
using namespace std;
int giveLengthOfGivenString(const char* c);
bool isNullPtr(const char* pointer);
bool isNullCharacter(const char character);
void createString(char* & string, int size);
void copyString(char* dest, const char* sour);
void copyStringByUsingLength(char* dest, const char* sour, int size);

#endif // !STRING_FUNCTIONS_H
