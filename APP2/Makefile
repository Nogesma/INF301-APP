all: main

CC=clang
CFLAGS=-g -Wall -Wextra -Werror
LDFLAGS=

# Ici, on utilise l'"intelligence" de 'make' qui saura tout seul
# comment créer les .o à partir des .c
main: main.o curiosity.o listes.o interprete.o calculette.o type_pile.o

clean:
	rm -f main *.o
