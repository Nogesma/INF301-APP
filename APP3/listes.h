#ifndef LISTES_H
#define LISTES_H

#include <stdbool.h>
#include "arbres.h"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
//
// #define printf(fmt, ...) (0)
// #define eprintf(fmt, ...) (0)
// #define putchar(c) (0)

#define TAILLE_MAX 5000

struct cellule {
  char *caract;
  struct cellule *suivant;
};

typedef struct cellule cellule_t;

struct liste {
  cellule_t *tete;
};

typedef struct liste liste_t;

cellule_t *nouvelleCellule();

extern bool silent_mode;

void afficher(liste_t *seq);

cellule_t *nouvelleCellule(void);
void detruireCellule(cellule_t *cel);

typedef struct Element Element;
struct Element
{
  arbre a;
  Element *suivant;
};

typedef struct File File;
struct File
{
  Element *tete;
};

void enfiler(File *file, int nvNombre);
arbre defiler(File *file);

int present(liste_t *l, char* car);
#endif /* _LISTES_H */