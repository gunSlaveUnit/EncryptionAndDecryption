#include "Key.hpp"

Key::Key() : length(0), key(nullptr)
{
}

Key::Key(int keyLength) : length(keyLength), key(new int[length])
{
}

Key::~Key()
{
	delete[] key;
}

void Key::generateKey()
{
	for (int i = 0; i < length; ++i)
		key[i] = i + 1;

	for (int i = 0; i < length; ++i)
	{
		int indexToSwap = rand() % length;
		int temp = key[i];
		key[i] = key[indexToSwap];
		key[indexToSwap] = temp;
	}
}

void Key::getKeyFromFile(const char* fileName)
{
	std::ifstream fileWithKey;

	fileWithKey.open(fileName);

	for (int i = 0; i < length; ++i)
		fileWithKey >> key[i];
}

void Key::sendKeyToFile()
{
	std::ofstream fileForKey;

	fileForKey.open("key.txt");

	for (int i = 0; i < length; ++i)
		fileForKey << key[i] << " ";
}

int* Key::returnPtrKey()
{
	return key;
}
