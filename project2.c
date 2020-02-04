#include <stdio.h>


int main()
{
	unsigned char message[2048];
	unsigned char key[2048];
	int character;
	int messageLength = 0;
	int keyLength = 0;

	while( (character = getchar()) != 255 && character != EOF
	&& messageLength < 2048)
	{
		message[messageLength] = character;
		++messageLength;
	}

	while (character != 255 && character != EOF)
	{
		character = getchar();
	}

	while( (character = getchar()) != EOF && keyLength < 2048)
	{
		key[keyLength] = character;
		++keyLength;
	}

	for( int j = 0; j < messageLength; ++j)
	{
		char c = message[j];
		putchar(c);
	}

	for( int j = 0; j < keyLength; ++j)
	{
		char c = key[j];
		putchar(c);
	}
}
