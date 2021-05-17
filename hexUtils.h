#include <stdio.h>
#include <stdbool.h>

#define MAXCHAR 1024

/* returns the module: |i-j| */
int getModule(int i, int j);

/* Takes a string, converts each pair of chars that represent
 * a 2 numbered hexadecimal value and converts to its corresponding
 * integer/ascii value 
 * Example: if it receives 6d6d
 * it will firstly convert the char '6' to the value 6
 * then it'll multiply it by 16. After that it will convert 'd' to 
 * to the value 13 and multiply it by 1. It will then take the sum of
 * those 2 numbers and make the corresponding integer: 109 ('m') */
void hexToDecimal(unsigned int hex[MAXCHAR], int length);

/* Scans for user input, saving it as a string
 * Only accepts input formatted as a Hex number */
bool getHexAsString (char hex[MAXCHAR], int *cont);

/* Converts a char ascii number to its hexadecimal value
 * example, char 'a' = 97 and it's converted to 10 */
int charToHex(char a);

/* */
void getXor(char hex1[MAXCHAR], char hex2[MAXCHAR], int length1, int length2, unsigned int hexXor[MAXCHAR]);

/* */
void decryptHex(char hex[MAXCHAR], int length, unsigned int letter[2], unsigned int hexXor[MAXCHAR]);
