CFLAGS = -Wall -Wextra -Wshadow -ansi -pedantic -g -O2

all: xor

xor: xor.o hexUtils.o
	gcc -o xor xor.o hexUtils.o

xor.o: xor.c hexUtils.c hexUtils.h
	gcc $(CFLAGS) xor.c -c

hexUtils.o: hexUtils.c hexUtils.h
	gcc $(CFLAGS) hexUtils.c -c

clean:
	rm -rf *.o *~ client
