#include <stdio.h>
#include <stdbool.h>

#include "hexUtils.h"

void hexToChar(char hex[MAXCHAR], int length)
{
	int cont;
	for(cont = 0; cont < length; cont += 2)
	{
		hex[(cont/2)] = ((charToHex(hex[cont])*16) + charToHex(hex[cont+1]));
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
	*cont = tCont;
	return(1);
}
