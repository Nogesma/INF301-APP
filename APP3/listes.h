#ifndef LISTES_H
#define LISTES_H

#include <stdbool.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
//
// #define printf(fmt, ...) (0)
// #define eprintf(fmt, ...) (0)
// #define putchar(c) (0)

#define TAILLE_MAX 5000

extern bool silent_mode;

struct cellule {
  char* valeur;
  struct cellule *suivant;
};
typedef struct cellule cellule_t;

struct liste {
  cellule_t *tete;
};
typedef struct liste liste_t;

void afficher(liste_t *seq);

cellule_t *nouvelleCellule(void);
void detruireCellule(cellule_t *cel);

#endif
