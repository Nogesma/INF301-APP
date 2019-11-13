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
  char command;
  struct cellule *suivant;
};
typedef struct cellule cellule_t;

struct sequence {
  cellule_t *tete;
};
typedef struct sequence sequence_t;

void conversion(char *texte, sequence_t *seq);

void afficher(sequence_t *seq);

cellule_t *nouvelleCellule(void);

void detruireCellule(cellule_t *);

#endif
