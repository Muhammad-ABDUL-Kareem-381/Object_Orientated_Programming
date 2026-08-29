#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
#include "Encryptor.h"
class CaesarCipher : public Encryptor
{
	int shift;
public:
	CaesarCipher();
	CaesarCipher(int n);
	void setShift(int n);
	int getShift() const;
	String encrypt(const String& plainText) const override;
	String decrypt(const String& cipheredText) const override;
};
#endif