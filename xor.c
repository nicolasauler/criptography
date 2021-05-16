#include <stdio.h>
#include <stdbool.h>

#include "hexUtils.h"

/*********************************************************/
/**                                                     **/
/**       prototipos de funcoes e suas descricoes       **/
/**                                                     **/
/*********************************************************/

/* Takes the hex-Xor produced by the getXor in the decrypt mode
 * and prints the correspondent string, converting the hex to
 * decimal, with the hexToDecimal function, so it prints with the
 * correct ascii code */
void printChar(unsigned int string[MAXCHAR], int length);

/* Prints the mode menu (encryption or decryption) */
bool menu();

/* Prints the decryption menu (key or not to key haha) */
bool menu2();

/*********************************************************/
/**                                                     **/
/**           implementacao de funcoes extras           **/
/**                                                     **/
/*********************************************************/

void printChar(unsigned int string[MAXCHAR], int length)
{
	int cont;
	printf("Decrypted phrase is: \n");
	hexToDecimal(string, length);
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
		printf("\nOptions:\n\t0 - I have the key\n\t1 - I don't have a key\n\nYour option: ");
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

/*********************************************************/
/**                                                     **/
/**                        main                         **/
/**                                                     **/
/*********************************************************/

int main()
{
	int i, j;
	char hex1[MAXCHAR], hex2[MAXCHAR];
	unsigned int hexXor[MAXCHAR];
	i = j = 0;
	if(!(menu()))
	{
		printf("Your first hex:  ");
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
		getXor(hex1, hex2, i, j, hexXor);
	}
	else
	{
		printf("Your encrypted hex: ");
		if(!(getHexAsString(hex1, &i)))
		{
			return(-1);
		}
		printf("\nYour encrypted hex was: %s\n", hex1);
		if(!(menu2()))
		{
			printf("Your key: ");
			if(!(getHexAsString(hex2, &j)))
			{
				return(-1);
			}
			printf("\nYour key was: %s\n", hex2);
			getXor(hex1, hex2, i, j, hexXor);
			printChar(hexXor, i);
		}
	}
	return(0);
}
