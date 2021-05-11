#include <stdio.h>
#include <stdbool.h>

#define MAXCHAR 1024

void printInt(unsigned int hex[MAXCHAR], int length);
void getXor(char hex1[MAXCHAR], char hex2[MAXCHAR], int length1, int length2, unsigned int hexXor[MAXCHAR]);
bool menu();
bool menu2();
bool getHexChar (char hex[MAXCHAR], int *cont);
int conversion(char a);
void hexToInt(char hex[MAXCHAR], char hexRes[MAXCHAR], int length);
int getModule(int i, int j);
void printChar(char string[MAXCHAR], int length);

void hexToInt(char hex[MAXCHAR], char hexRes[MAXCHAR], int length)
{
	int cont;
	printf("traducao abaixo:\n");
	for(cont = 0; cont < (length); cont += 2)
	{
		hexRes[(cont/2)] = ((conversion(hex[cont])*16) + conversion(hex[cont+1]));
		printf("%c", hexRes[(cont/2)]);
	}
	/* printChar(hexRes, length); */
}

void printChar(char string[MAXCHAR], int length)
{
	int cont;
	for(cont = 0; cont < length; cont++)
	{
		printf("%c", string[cont]);
	}
	printf("\n");
}

void printInt(unsigned int hex[MAXCHAR], int length)
{
	int cont;
	for(cont = 0; cont < length; cont++)
	{
		printf("%d", hex[cont]);
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

int conversion(char a)
{
		if(a <= 57 && a >= 48)
		{
			return(a - 48);	
		}
		else if (a <= 70 && a >= 65)
		{
			return(a - 55);
		}
		else if (a <= 102 && a >= 97)
		{
			return(a - 87);
		}
		else
		{
			return(-1);
		}
}

bool getHexChar (char hex[MAXCHAR], int *cont)
{	
	int tCont = *cont;
	do
	{
		scanf("%c", &hex[tCont]);
		if((hex[tCont] >= 65 && hex[tCont] <= 70) || (hex[tCont] <= 102 && hex[tCont] >= 97) || (hex[tCont] <= 57 && hex[tCont] >= 48) || (hex[tCont] == '\n'))
		{
		}
		else
		{
			printf("Please input a Hexadecimal value\n");
			return(0);
		}
		if(hex[tCont] != '\n')
		{
			tCont++;		
		}
	} while((hex[tCont] != '\n') && (tCont < MAXCHAR));
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
	printf("Your values are:\n1\t%s\n2\t%s\n\n", hex1, hex2);
	for(cont = 0; cont < length1; cont++)
	{
		hexOne = conversion(hex1[cont]);
		hexTwo = conversion(hex2[cont]);
		hexXor[cont] = hexOne^hexTwo;
		printf("%x", hexXor[cont]);
	}
	printf("\n\n");
}

int main()
{
	int cont;
	unsigned int hexOne, hexTwo;
	int i, j;
	char hex1[MAXCHAR], hex2[MAXCHAR], hex3[MAXCHAR], hex4[MAXCHAR];
	unsigned int hexXor[MAXCHAR];
	i = j = 0;
	if(!(menu()))
	{
		printf("Your first hex: ");
		if(!(getHexChar(hex1, &i)))
		{
			return(-1);
		}
		printf("Your second hex: ");
		if(!(getHexChar(hex2, &j)))
		{
			return(-1);
		}
		printf("Your values were:\n1\t%s\n2\t%s\n", hex1, hex2);
		getXor(hex1, hex2, i, j, hexXor);
	}
	else
	{
		printf("Your encrypted hex: ");
		if(!(getHexChar(hex1, &i)))
		{
			return(-1);
		}
		printf("Your encrypted hex was:\n%s", hex1);
		if(!(menu2()))
		{
			printf("Your key: ");
			if(!(getHexChar(hex2, &j)))
			{
				return(-1);
			}
			printf("Your key was: \n%s", hex2);
			hexToInt(hex1, hex3, i);
			hexToInt(hex2, hex4, j);
			for(cont = 0; cont < i/2; cont++)
			{
				hexOne = hex3[cont];
				hexTwo = hex4[cont];
				hexXor[cont] = hexOne^hexTwo;
				printf("%x", hexXor[cont]);
			}
			/* getXor(hex3, hex4, i, j, hexXor); */
			/*
			getXor(hex1, hex2, i, j, hexXor);
			printInt(hexXor, i);
			*/
		}
	}
	return(0);
}
