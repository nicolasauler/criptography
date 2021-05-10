all: xor

xor: xor.c
	gcc -Wall -Wextra -Wshadow -ansi -pedantic -g -O2 xor.c -o xor
