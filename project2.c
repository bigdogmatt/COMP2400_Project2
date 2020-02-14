/*******************************
 *
 *  Project Name: Project 2: One Time, One Time
 *  Description: This project takes a message and key a encrypts the message
 *  File names: project2.c
 *  Date: 02/14/2020
 *  Authors: Matt Kleman & James Erpenbeck
 *
 *******************************/

#include <stdio.h>
#define SIZE 2048 //The max size of the arrays
#define DELIM 255 //The value of the delimiter

//Prototyping the two function 'rotate' and 'bits'
unsigned char rotate(unsigned char c, int bits);
int bits(unsigned char);

/*
Main function that takes care of the message and key I/O,
key tiling, chaining, and the final encryption
*/
int main()
{
	unsigned char message[SIZE]; //Array to store the message
	unsigned char key[SIZE]; //Array to store the key
	int character; //Variable to store the current character
	int messageLength = 0; //Variable to keep track of the message length
	int keyLength = 0; //Variable to keep track of the key length
	int keySum = 0; //Variable to store the total of the processed key characters

	//Message and key I/O:
	/**********************
	While loop that cycles through the input file, adding each character
	to the message array until the delimiter or EOF is reached or the array
	is full. This loop also increments messageLength each iteration to keep
	track of the size of the message.
	**********************/
	while( (character = getchar()) != DELIM && character != EOF
	&& messageLength < SIZE)
	{
		message[messageLength] = character;
		++messageLength;
	}

	/**********************
	While loop runs only if the character value in c at the end of
	the first loop is not equal to the delimiter or the end of the file. This
	means that the message input is longer than the size of the array. This
	loop takes the remaining characters in the message, up to the delimiter,
	and throws them away.
	**********************/
	while (character != DELIM && character != EOF)
	{
		character = getchar();
	}

	/**********************
	While loop cycles through the rest of the input file, adding each
	remaining character to the key array until the EOF is reached or the array
	is full. This loop also increments keyLength each iteration to keep
	track of the size of the key.
	**********************/
	while( (character = getchar()) != EOF && keyLength < SIZE)
	{
		key[keyLength] = character;
		++keyLength;
	}

	//Tiling:
	/**********************
	For loop that makes the key the same length as the message by repeating the
	characters in the key until they are the same length.
	**********************/
	for(int i = 0; i < messageLength; ++i)
	{
		if( i >= keyLength)
		{
			key[i] = key[i - keyLength];
		}
	}

	//Chaining:
	//Set the keySum equal to the last character in key to begin with.
	keySum = key[messageLength - 1];
	//Mod keySum by the length so we can use it when we call rotate
	keySum %= messageLength;
	/**********************
	For loop that runs for the length of the message, and also key. This loop
	sets the current character in key equal to itself XOR the character in key
	at location keySum then rotated by the number of one bits in the previous
	character in key. It then adds the new random key character to the keySum.
	**********************/
	for(int i = 0; i < messageLength; ++i)
	{
		if ( i == 0)
		{
			key[i] = rotate(key[i]^key[keySum], bits(key[messageLength-1]));
		}
		else
		{
			key[i] = rotate(key[i]^key[keySum], bits(key[i-1]));
		}

		keySum += key[i];
		keySum %= messageLength;
	}

	/**********************
	For loop that preforms the final XOR of the message characters with the
	manipulated random key
	**********************/
	for( int i = 0; i < messageLength; ++i)
	{
		putchar(message[i] ^ key[i]);
	}

	return 0;
}

/**********************
This function rotates the 7 least significant bits in the character c by n. We
first mod n by 7 because rotating the value by 7 is the same as doing nothing.
We then shift the bits in c to the right by n and bitwise OR that with the bits
in c shifted to the left by 7 - n. We then bitwise AND this result with 0x7F
which is a value with a 7 ones in the 7 least significant bits and a 0 in the
8th bit. This removes any 1 that ends up in the 8th bit.
**********************/
unsigned char rotate(unsigned char c, int n)
{
	n %= 7;
	return 0x7F & ((c >> n)|(c << (7 - n)));
}

/**********************
This function counts the number of ones in the bit representation of the given
character, c. It does this by bitwise ANDing the value with 1. If there is a
0 in the least significant bit then the value will be 0. If there is a 1 in the
least significant bit then the result will be a 1. We add this to the count
variable and then shift c to the right and repeat until c is 0.
**********************/
int bits(unsigned char c)
{
	int count = 0;

	while(c)
	{
		count += c & 1;
		c >>= 1;
	}
	return count;
}
