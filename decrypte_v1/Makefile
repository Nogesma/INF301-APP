CC=clang -Wall -g

all: decrypte_v1

client.o: client.c client.h
	$(CC) -c client.c
decrpyte_v1.o: decrypte_v1.c client.h
	$(CC) -c decrypte_v1.c
decrypte_v1: decrypte_v1.o client.o
	$(CC) decrypte_v1.o client.o -o decrypte_v1
clean:
	rm -f decrypte_v1 *.o
