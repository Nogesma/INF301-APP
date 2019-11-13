#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"

bool silent_mode = false;

void ajout_en_tete(sequence_t *seq, char command) {
  cellule_t *c = nouvelleCellule();
  c->command = command;
  c->suivant = seq->tete;
  seq->tete = c;
}

void conversion(char *texte, sequence_t *seq) {
  int i;
  for (i = strlen(texte) - 1; i >= 0; i--) {
    ajout_en_tete(seq, texte[i]);
  }
}

void afficher(sequence_t *seq) {
  cellule_t *c = seq->tete;
  printf("Sequence de commandes: ");
  while (c != NULL) {
    printf("%c", c->command);
    c = c->suivant;
  }
  printf("\n");
}

cellule_t *nouvelleCellule(void) {
  cellule_t *c;
  c = (cellule_t *)malloc(sizeof(cellule_t));
  return c;
}

void detruireCellule(cellule_t *cel) { free(cel); }
