CC=clang
CFLAGS=-Wall -g

all: crypteSeq

crypteSeq: client-tutoriel.o client.o crypt.o
	clang $(CFLAGS) -o crypteSeq client-tutoriel.o client.o crypt.o
	
client.o: client.c client.h

crypt.o : crypt.c crypt.h

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
