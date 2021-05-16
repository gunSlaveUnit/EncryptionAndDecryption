#include "Headers.hpp"

int main(int argc, const char** argv)
{
	srand(time(NULL));

	auto start = std::chrono::high_resolution_clock::now();

	switch (argc)
	{
	case 2:
	{
		Text notEncryptedText;
		notEncryptedText.getTextFromFile(argv[1]);
		std::cout << "Plaintext received.\n\n";

		Key keyToEncryptFile(notEncryptedText.getLengthContent());
		std::cout << "Key generation started.\n";

		keyToEncryptFile.generateKey();
		std::cout << "key generation is over.\n";
		keyToEncryptFile.sendKeyToFile();
		std::cout << "Key sent to file.\n\n";

		std::cout << "Text encryption is in progress.\n";
		Text encryptedText(notEncryptedText.encrypt(keyToEncryptFile.returnPtrKey()));
		std::cout << "The text is encrypted.\n";
		encryptedText.sendTextToFile("encrypt.txt");
		std::cout << "Encrypted text sent to file.\n\n";

		break;
	}
	case 3:
	{		
		Text encryptedText;
		encryptedText.getTextFromFile(argv[1]);
		std::cout << "Encrypted text received.\n\n";

		Key keyToDecryptFile(encryptedText.getLengthContent());
		keyToDecryptFile.getKeyFromFile(argv[2]);
		std::cout << "Key received.\n\n";

		std::cout << "Text decryption is in progress.\n";
		Text decryptedText(encryptedText.decrypt(keyToDecryptFile.returnPtrKey()));
		std::cout << "The text is decrypted.\n";
		decryptedText.sendTextToFile("decrypt.txt");
		std::cout << "Decrypted text sent to file.\n\n";
		
		break; 
	}
	default:
		std::cout << "Error: Unknown combination of arguments.\n";
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> time = end - start;
	std::cout << "Done for " << time.count() << "s!\n";
}