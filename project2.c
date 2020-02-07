#include <stdio.h>
#define SIZE 2048

unsigned char rotate(unsigned char c);
int bits(unsigned char);

int main()
{
	unsigned char message[SIZE];
	unsigned char key[SIZE];
	int character;
	int messageLength = 0;
	int keyLength = 0;
	int keySum = 0;

//Message and key I/O
	while( (character = getchar()) != 255 && character != EOF
	&& messageLength < SIZE)
	{
		message[messageLength] = character;
		++messageLength;
	}

	while (character != 255 && character != EOF)
	{
		character = getchar();
	}

	while( (character = getchar()) != EOF && keyLength < SIZE)
	{
		key[keyLength] = character;
		++keyLength;
	}

//tiling
	for(int i = 0; i < messageLength; ++i)
	{
		if( i >= keyLength)
		{
			key[i] = key[i - keyLength];
		}
	}

//rotating
	keySum = key[messageLength - 1];
	keySum %= messageLength;
	for(int i = 0; i < messageLength; ++i)
	{
		if ( i == 0)
		{
			key[i] = rotate(key[i]^key[keySum], bits(key[messageLength-1]);
		}
		else
		{
			key[i] = rotate(key[i]^key[keySum], bits(key[i-1]);
		}
		
		keySum += key[i];
		keySum %= messageLength;
	}

//printing the message and the tiled key for testing purposes
	for( int j = 0; j < messageLength; ++j)
	{
		char c = message[j];
		putchar(c);
	}
	printf("\n\n\n");

	for( int j = 0; j < messageLength; ++j)
	{
		char c = key[j];
		putchar(c);
	}
	printf("\n\n\n");
}

unsigned char rotate(unsigned char c)
{

}

int bits(unsigned char)
{

}
