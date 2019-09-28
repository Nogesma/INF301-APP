CC=clang
CFLAGS=-Wall -g

all: projetX decrypte planB crypteSeq Nothwoods LostCause

# Create executables for all the exercises
projetX: projetX projetX/cesar.o client.o
	$(CC) projetX/projetX.c projetX/cesar.o client.o -o projetX_exec

decrypte: decrypte-v1/decrypte-v1.c client.o
	$(CC) decrypte-v1/decrypte-v1.c client.o -o decrypte-v1_exec

planB: planB/planB.c client.o
	$(CC) planB/planB.c client.o -o planB_exec

crypteSeq: crypteSeq/crypteSeq.c crypteSeq/crypt.o client.o
	$(CC) crypteSeq/crypteSeq.c crypteSeq/crypt.o client.o -o crypteSeq_exec

Nothwoods: Nothwoods/Nothwoods.c Nothwoods/crypt.o client.o
	$(CC) Nothwoods/Nothwoods.c Nothwoods/crypt.o client.o -o Nothwoods_exec

LostCause: LostCause/LostCause.c client.o
	$(CC) LostCause/LostCause.c client.o -o LostCause_exec

# Files
client.o: client.c

projetX/cesar.o: projetX/cesar.c

crypteSeq/crypt.o: crypteSeq/crypt.c

Nothwoods/crypt.o: Nothwoods/crypt.c

clean:
	rm -f client.o **/*.o *_exec
