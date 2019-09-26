CC=clang
CFLAGS=-Wall -g

all: ProjetX

client.o: client.c client.h

cesar.o : cesar.c cesar.h

ProjetX : projetX.c client.o cesar.o
	$(CC) -o ProjetX projetX.c client.o cesar.o

clean:
	rm -f *.o

clear:
	rm -f ProjetX