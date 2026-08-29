#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include<iostream>
#include"String.h"
class Encryptor
{

public:
	virtual String encrypt(const String& plainText) const = 0;
	virtual String decrypt(const String& cipheredText) const = 0;
};
#endif // !ENCRYPTOR_H
