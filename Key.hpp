#pragma once

#include "Headers.h"

class Key
{
public:
	Key();
	Key(int keyLength);
	~Key();

	void generateKey();
	void getKeyFromFile(const char* fileName);
	void sendKeyToFile();
	int* returnPtrKey();
private:

	int length;
	int* key;
};