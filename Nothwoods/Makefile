CC=clang -g -Wall

nothwoods: client-interactif.o client.o decryption.o
	$(CC) client-interactif.o client.o decryption.o -o nothwoods

client-interactif.o: Nothwoods.c ../client.h
	$(CC) -c client-interactif.c

client.o: ../client.c ../client.h
	$(CC) -c client.c

decryption.o: crypt.c crypt.h
	$(CC) -c decryption.c

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
