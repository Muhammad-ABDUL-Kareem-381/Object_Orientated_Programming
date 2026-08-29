#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include "String.h"
#include <iostream>
using namespace std;
class Encryptor
{
public: 
	virtual String encrypt(const String & plainText) const = 0;
	virtual String decrypt(const String & cipheredText) const = 0;
};
#endif