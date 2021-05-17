#include <string.h>
#include "cryptanalysis.h"

#define MAXWORD 20

double average (double a, int b, int n)
{
	return((((n-1)*a)+b)/n);
}

double lettersPerWord(unsigned int hex[MAXCHAR])
{
	int nWords;
	int cont1, cont2;
	double stats;
	char word[MAXWORD];
	stats = 0;
	for(nWords = 0, cont1 = 0; (cont1 < MAXCHAR) && (hex[cont1-1] != '\n');)
	{
		cont2 = 0;
		do
		{
			word[cont2] = hex[cont1 + cont2];
			cont2++;
		} while((cont2 <= MAXWORD) && ((word[cont2-1] != '\n') && (word[cont2-1] != '\0') && (word[cont2-1] != ' ')));
		cont1 += cont2;
		if(cont2 == MAXWORD)
		{
			continue; /* nao queremos que essa palavra conte nem para o n de palavras nem para a estatistica do tamanho */
		}
		nWords++;
		stats = average(stats, (int) (strlen(word)-1), nWords);
	}
	return(stats);
}
