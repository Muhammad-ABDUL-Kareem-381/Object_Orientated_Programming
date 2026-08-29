#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H
#include"Encryptor.h"
#include<iostream>
using namespace std;
class CaesarCipher : public Encryptor
{
	int shift;
	bool isLowerCaseAlphabet(const char& ref) const ;
	bool isUpperCaseAlphabet(const char& ref) const ;
public:
	CaesarCipher(int i = 0);
	void setShift(unsigned int num);
	unsigned int getShift();
	String encrypt(const String& plainText) const override;
	String decrypt(const String& cipheredText) const override;
};
#endif // !CAESAR_CIPHER_H
