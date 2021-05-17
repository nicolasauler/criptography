#include <stdio.h>
#include <stdbool.h>

#include "hexUtils.h"

int getModule(int i, int j)
{
	if(i > j)
	{
		return(i-j);
	}
	return(j-i);
}

void hexToDecimal(unsigned int hex[MAXCHAR], int length)
{
	int cont;
	for(cont = 0; cont < length; cont += 2)
	{
		hex[(cont/2)] = ((hex[cont]*16) + hex[cont+1]);
	}
}

int charToHex(char a)
{
	if(a <= 57 && a >= 48)			/* if beetween 0 and 9 */
	{
		return(a - 48);	
	}
	else if (a <= 70 && a >= 65)	/* if beetween a and f */
	{
		return(a - 55);
	}
	else if (a <= 102 && a >= 97)	/* if beetween A and F */
	{
		return(a - 87);
	}
	else
	{
		return(-1);
	}
}

bool getHexAsString (char hex[MAXCHAR], int *cont)
{	
	int tCont = *cont;
	do
	{
		scanf("%c", &hex[tCont]);
		if(!((hex[tCont] >= 65 && hex[tCont] <= 70) || (hex[tCont] <= 102 && hex[tCont] >= 97) || (hex[tCont] <= 57 && hex[tCont] >= 48) || (hex[tCont] == '\n')))
		{
			printf("Please input a Hexadecimal value\n");
			return(0);
		}
		if(hex[tCont] != '\n')
		{
			tCont++;		
		}
	} while((hex[tCont] != '\n') && (tCont < MAXCHAR));
	hex[tCont] = '\0';
	*cont = tCont;
	return(1);
}

void getXor(char hex1[MAXCHAR], char hex2[MAXCHAR], int length1, int length2, unsigned int hexXor[MAXCHAR])
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
	printf("\nYour values are:\n\nCipher\t%s\nKey\t%s\n\n", hex1, hex2);
	printf("Xor(cipher^key) is:\n");
	for(cont = 0; cont < length1; cont++)
	{
		hexOne = charToHex(hex1[cont]);
		hexTwo = charToHex(hex2[cont]);
		hexXor[cont] = hexOne^hexTwo;
		printf("%x", hexXor[cont]);
	}
	printf("\n\n");
}

void decryptHex(char hex[MAXCHAR], int length, unsigned int letter[2], unsigned int hexXor[MAXCHAR])
{
	int cont;
	unsigned int hexBit;
	for(cont = 0; cont < length; cont++)
	{
		hexBit = charToHex(hex[cont]);
		hexXor[cont] = hexBit^letter[cont % 2];
		printf("%x", hexXor[cont]);
	}
}
