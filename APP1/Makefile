CC=clang $(CFLAGS)
CFLAGS=-Wall -g

all: build projetX decrypte planB crypteSeq Nothwoods LostCause

# Create executables for all the exercises
projetX: cesar.o client.o
	$(CC) src/projetX.c o/cesar.o o/client.o -o exec/projetX

decrypte: client.o
	$(CC) src/decrypte-v1.c o/client.o -o exec/decrypte-v1

planB: client.o
	$(CC) src/planB.c o/client.o -o exec/planB

crypteSeq: cryptSeq.o client.o
	$(CC) src/crypteSeq.c o/crypteSeq.o o/client.o -o exec/crypteSeq


Nothwoods: NothLost.o client.o
	$(CC) src/Nothwoods.c o/NothLost.o o/client.o -o exec/Nothwoods

LostCause: NothLost.o client.o
	$(CC) src/LostCause.c o/NothLost.o o/client.o -o exec/LostCause

# Files
client.o: client.c
	$(CC) -c client.c -o o/client.o

cesar.o: src/projetX/cesar.c
	$(CC) -c src/projetX/cesar.c -o o/cesar.o

cryptSeq.o: src/crypteSeq/crypt.c
	$(CC) -c src/crypteSeq/crypt.c -o o/crypteSeq.o

NothLost.o: src/NothLost/NothLost.c
	$(CC) -c src/NothLost/NothLost.c -o o/NothLost.o

build:
	mkdir -p o exec

clean:
	rm -rf o exec
