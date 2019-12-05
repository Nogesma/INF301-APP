#include "listes.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef NCURSES
#include <ncurses.h>
#endif

void afficher(liste_t *seq) {
	cellule_t *cel = seq->tete;
  printf("Les caracteristiques: ");
  while (cel != NULL) {
    printf("%s ", cel->caract);
    cel = cel->suivant;
  }
  printf("\n");
}

cellule_t *nouvelleCellule(void) {
  cellule_t *c;
  c = (cellule_t *)malloc(sizeof(cellule_t));
	c->suivant = NULL;
  return c;
}

void detruireCellule(cellule_t *cel) { free(cel); }

int length(cellule_t *cel){
	int counter = 0;
	while(cel != NULL){
		counter++;
		cel = cel->suivant;
	}
	return counter;
}
