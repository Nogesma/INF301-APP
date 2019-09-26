CC=clang
CFLAGS=-Wall -g

EXEC=client-introduction client-tutoriel client-interactif

all: $(EXEC)

client-interactif: client-interactif.o client.o

client-tutoriel: client-tutoriel.o client.o

client-introduction: client-introduction.o client.o

client.o: client.c client.h

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
