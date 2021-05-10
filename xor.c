#include <stdio.h>
#include <stdbool.h>

#define MAXCHAR 50

void getXor(char hex1[MAXCHAR], char hex2[MAXCHAR], int length1, int length2, unsigned int hexXor[MAXCHAR]);
bool menu();
bool getHexChar (char hex[MAXCHAR], int *cont);
int conversion(char a);
int getModule(int i, int j);

bool menu()
{
	int opt;
	bool option;
	printf("Options:\n\t0 - Encryption\n\t1 - Decryption\n\nYour option: ");
	scanf("%d", &opt);
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
}

int main()
{
	int i, j;
	char hex1 [MAXCHAR], hex2 [MAXCHAR];
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
		printf("you selected decrypt\n");	
	}
	return(0);
}
