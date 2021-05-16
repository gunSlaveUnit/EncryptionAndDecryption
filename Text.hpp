#pragma once

#include "Headers.h"

class Text
{
public:
	Text();
	Text(std::string text);
	~Text();

	void getTextFromFile(const char* fileName);
	void sendTextToFile(const char* fileName);

	int getLengthContent();

	std::string encrypt(int* key);
	std::string decrypt(int* key);
private:
	std::string Content;
};

