CFLAGS = -Wall -Wextra -Wshadow -ansi -pedantic -g -O2

all: xor

xor: xor.o cryptanalysis.o hexUtils.o
	gcc -o xor xor.o cryptanalysis.o hexUtils.o

xor.o: xor.c cryptanalysis.c cryptanalysis.h hexUtils.c hexUtils.h
	gcc $(CFLAGS) xor.c -c

cryptanalysis.o: cryptanalysis.c cryptanalysis.h
	gcc $(CFLAGS) cryptanalysis.c -c

hexUtils.o: hexUtils.c hexUtils.h
	gcc $(CFLAGS) hexUtils.c -c

clean:
	rm -rf *.o *~ client
