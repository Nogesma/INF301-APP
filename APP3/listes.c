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

int length(cellule_t *cel) {
  int counter = 0;
  while (cel != NULL) {
    counter++;
    cel = cel->suivant;
  }
  return counter;
}

void enfiler(File *file, arbre *a) {
  Element *nouveau = malloc(sizeof(*nouveau));
  if (file == NULL || nouveau == NULL) {
    exit(EXIT_FAILURE);
  }

  nouveau->a = *a;
  nouveau->suivant = NULL;

  if (file->tete != NULL) /* La file n'est pas vide */ {
    /* On se positionne à la fin de la file */
    Element *elementActuel = file->tete;
    while (elementActuel->suivant != NULL) {
      elementActuel = elementActuel->suivant;
    }
    elementActuel->suivant = nouveau;
  } else /* La file est vide, notre élément est le premier */ {
    file->tete = nouveau;
  }
}

arbre defiler(File *file) {
  if (file == NULL) {
    exit(EXIT_FAILURE);
  }

  arbre *nombreDefile;
  /* On vérifie s'il y a quelque chose à défiler */
  if (file->tete != NULL) {
    Element *elementDefile = file->tete;

    nombreDefile = &elementDefile->a;
    file->tete = elementDefile->suivant;
    free(elementDefile);
  }

  return *nombreDefile;
}

int present(liste_t *l, char *car) {
  cellule_t *c = nouvelleCellule();
  c = l->tete;
  return presentRec(c, car);
}

int presentRec(cellule_t *c, char *car) {
  if (c == NULL)
    return 1;
  if (c->caract == car)
    return 0;
  return presentRec(c->suivant, car);
}
