#ifndef  MY_STRING_H
#define MY_STRING_H
#include<iostream>
using namespace std;
int getStringLength(const char*);
void concatenate(char* , const char* );
void copyString(char* , const char*);
int converttoInteger(const char*);
float convertToFloat(const char*);
void makeUpper(char*);
void makeLower(char*);
void reverse(char*);
void swapCharacters(char&, char&);
int compare( char*,  char*, bool = true);
int findSubStr(char* destination, char* key, int start = 0);
#endif
