#include <stdio.h>
#include <stdbool.h>

#include "hexUtils.h"

void getXor0(char hex1[MAXCHAR], char hex2[MAXCHAR], int length1, int length2, unsigned int hexXor[MAXCHAR]);
void getXor1(char hex1[MAXCHAR], char hex2[MAXCHAR], int length1, int length2, unsigned int hexXor[MAXCHAR]);
void printChar(unsigned int string[MAXCHAR], int length);
bool menu();
bool menu2();
int getModule(int i, int j);

int getModule(int i, int j)
{
	if(i > j)
	{
		return(i-j);
	}
	else
	{
		return(j-i);
	}
}

void printChar(unsigned int string[MAXCHAR], int length)
{
	int cont;
	printf("Your phrase is: \n");
	for(cont = 0; cont < length/2; cont++)
	{
		printf("%c", string[cont]);
	}
	printf("\n");
}

bool menu()
{
	bool option;
	int opt = 2;
	do
	{
		printf("Options:\n\t0 - Encryption\n\t1 - Decryption\n\nYour option: ");
		scanf("%d", &opt);
		if((opt != 0) && (opt != 1))
		{
			printf("\nPlease input an option that exists\n");
		}
	} while((opt != 0) && (opt != 1));
	getchar();
	option = opt;
	return(option);
}

bool menu2()
{
	bool option;
	int opt = 2;
	do
	{
		printf("Options:\n\t0 - I have the key\n\t1 - I don't have a key\n\nYour option: ");
		scanf("%d", &opt);
		if((opt != 0) && (opt != 1))
		{
			printf("\nPlease input an option that exists\n");
		}
	} while((opt != 0) && (opt != 1));
	getchar();
	option = opt;
	return(option);
}


void getXor0(char hex1[MAXCHAR], char hex2[MAXCHAR], int length1, int length2, unsigned int hexXor[MAXCHAR])
{	
	int cont, mod;
	unsigned int hexOne, hexTwo;
	mod = getModule(length1, length2);
	if(length1 > length2)
	{
		for(cont = 0; cont < mod; cont++)
		{
			hex2[cont+mod] = hex2[cont];
			hex2[cont] = '0';
		}
	}
	else if(length2 > length1) 
	{
		for(cont = 0; cont < mod; cont++)
		{
			hex1[cont+mod] = hex1[cont];
			hex1[cont] = '0';
		}
	}
	printf("Your values are:\n1\t%s\n2\t%s\n\n", hex1, hex2);
	for(cont = 0; cont < length1; cont++)
	{
		hexOne = charToHex(hex1[cont]);
		hexTwo = charToHex(hex2[cont]);
		hexXor[cont] = hexOne^hexTwo;
		printf("%x", hexXor[cont]);
	}
	printf("\n\n");
}

void getXor1(char hex3[MAXCHAR], char hex4[MAXCHAR], int length3, int length4, unsigned int hexXor[MAXCHAR])
{	
	int cont, mod;
	unsigned int hexOne, hexTwo;
	mod = getModule(length3, length4);
	if(length3 > length4)
	{
		for(cont = 0; cont < mod; cont++)
		{
			hex4[cont+mod] = hex4[cont];
			hex4[cont] = '0';
		}
	}
	else if(length4 > length3) 
	{
		for(cont = 0; cont < mod; cont++)
		{
			hex3[cont+mod] = hex3[cont];
			hex3[cont] = '0';
		}
	}
	printf("Your values are:\n1\t%s\n2\t%s\n\n", hex3, hex4);
	for(cont = 0; cont < (length3/2); cont++)
	{
		hexOne = hex3[cont];
		hexTwo = hex4[cont];
		hexXor[cont] = hexOne^hexTwo;
		printf("%x", hexXor[cont]);
	}
	printf("\n\n");	
}

int main()
{
	int i, j;
	char hex1[MAXCHAR], hex2[MAXCHAR];
	unsigned int hexXor[MAXCHAR];
	i = j = 0;
	if(!(menu()))
	{
		printf("Your first hex: ");
		if(!(getHexAsString(hex1, &i)))
		{
			return(-1);
		}
		printf("Your second hex: ");
		if(!(getHexAsString(hex2, &j)))
		{
			return(-1);
		}
		printf("Your values were:\n1\t%s\n2\t%s\n", hex1, hex2);
		getXor0(hex1, hex2, i, j, hexXor);
	}
	else
	{
		printf("Your encrypted hex: ");
		if(!(getHexAsString(hex1, &i)))
		{
			return(-1);
		}
		printf("Your encrypted hex was:\n%s", hex1);
		if(!(menu2()))
		{
			printf("Your key: ");
			if(!(getHexAsString(hex2, &j)))
			{
				return(-1);
			}
			printf("Your key was: \n%s", hex2);
			hexToChar(hex1, i);
			hexToChar(hex2, j);
			getXor1(hex1, hex2, i, j, hexXor);
			printChar(hexXor, i);
		}
	}
	return(0);
}
