CC=clang -g -Wall

nothwoods: client-interactif.o client.o decryption.o
	$(CC) client-interactif.o client.o decryption.o -o nothwoods

client-interactif.o: client-interactif.c ../client.h
	$(CC) -c client-interactif.c

client.o: ../client.c ../client.h
	$(CC) -c client.c

decryption.o: nothwoods.c nothwoods.h
	$(CC) -c decryption.c

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
