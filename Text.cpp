#include "Text.hpp"

Text::Text() {}

Text::Text(std::string text) : Content(text) {}

Text::~Text() {}

void Text::getTextFromFile(const char* fileName)
{
	std::ifstream fileWithText;
	fileWithText.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	
	try
	{
		fileWithText.open(fileName);

		std::string inputStringFromFile;
		while (!fileWithText.eof())
		{
			std::getline(fileWithText, inputStringFromFile);
			Content += inputStringFromFile;
		}

		fileWithText.close();
	}
	catch(const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}	
}

void Text::sendTextToFile(const char* fileName)
{
	try
	{
		std::ofstream fileForText(fileName, std::ios::app);

		fileForText << Content;

		fileForText.flush();
		fileForText.close();
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

int Text::getLengthContent()
{
	return Content.length();
}

std::string Text::encrypt(int* key)
{
	int size = Content.length();
	std::string encryptedText(size, ' ');

	for (int i = 0; i < size; ++i)
		encryptedText[i] = Content[static_cast<double>(key[i]) - 1];

	return encryptedText;
}

std::string Text::decrypt(int* key)
{
	int size = Content.length();
	std::string decryptedText(size, ' ');

	for (int i = 0; i < size; ++i)
		decryptedText[static_cast<double>(key[i]) - 1] = Content[i];

	return decryptedText;
}
