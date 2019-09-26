CC=clang
CFLAGS=-Wall -g

all: client-tutoriel

client-interactif: client-interactif.o client.o

client-tutoriel: client-tutoriel.o client.o crypt.o

client-introduction: client-introduction.o client.o

client.o: client.c client.h

crypt.o : crypt.c crypt.h

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
