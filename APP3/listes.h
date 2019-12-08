#ifndef LISTES_H
#define LISTES_H

#include "arbres.h"
#include <stdbool.h>
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

int length(cellule_t *cel);

typedef struct Element Element;

struct Element {
  arbre a;
  Element *suivant;
};

typedef struct File File;

struct File {
  Element *tete;
};

void enfiler(File *file, arbre *a);
noeud defiler(File *file);

int present(liste_t *l, char *car);
int presentRec(cellule_t *c, char *car);

Element *nouveau_elt();

struct cellule_a {
    noeud *n;
    struct cellule *suivant;
};

typedef struct cellule_a cellule_a;

struct liste_a {
    cellule_a *tete;
};

typedef struct liste_a liste_a;

cellule_a *nouvelleCellule_a();
#endif /* _LISTES_H */
