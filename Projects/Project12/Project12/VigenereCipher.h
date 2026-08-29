#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H
#include"Encryptor.h"
class VigenereCipher :public Encryptor
{
	String key;
	bool isLowerCaseAlphabet(const char& ref) const;
	bool isUpperCaseAlphabet(const char& ref) const;
public:
	VigenereCipher(const String& temp);
	void setKey(const String& temp);
	String getKey()const;
	virtual String encrypt(const String& plainText)const override;
	virtual String decrypt(const String& cipheredText)const override;
};
#endif // !VIGENERE_CIPHER_H
