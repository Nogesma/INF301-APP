CC=clang
CFLAGS=-Wall -g

all: projetX decrypte planB crypteSeq Nothwoods

# Create executables for all the exercises
projetX: projetX/main.c projetX/cesar.o client.o
	$(CC) projetX/main.c projetX/cesar.o client.o -o projetX_exec

decrypte: decrypte-v1/main.c client.o
	$(CC) decrypte-v1/main.c client.o -o decrypte-v1_exec

crypteSeq: crypteSeq/client-tutoriel.o client.o crypt.o
	clang $(CFLAGS) -o crypteSeq client-tutoriel.o client.o crypt.o

# Files
client.o: client.c client.h

projetX/cesar.o: projetX/cesar.c projetX/cesar.h

crypt.o: crypt.c crypt.h

clean:
	rm -f */*.o

clear:
	rm -f $(EXEC)
