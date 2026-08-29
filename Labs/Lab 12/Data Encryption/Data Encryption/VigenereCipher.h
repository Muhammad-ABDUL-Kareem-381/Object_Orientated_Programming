#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H
#include "Encryptor.h"
class VigenereCipher : public Encryptor
{
	int shift;
	String key;
public:
	VigenereCipher();
	VigenereCipher(int n);
	void setShift(int n);
	int getShift() const;
	void setKey(String& k);
	String getKey() const;
	String encrypt(const String& plainText) const ;
	String decrypt(const String& cipheredText) const ;
};
#endif