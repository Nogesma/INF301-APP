#include "type_pile.h"
#include "interprete.h"
#include <stdio.h>
void creer_pile(PileCellules *p) { p->n = 0; };

int est_vide(PileCellules p) { return p.n == 0; };

void sommet(PileCellules p, cellule_t **c) { *c = &p.tab[p.n - 1]; };

int taille(PileCellules p) { return p.n; };

void print(PileCellules p) {
  int i;
  printf("[ ");
  for (i = 0; i < p.n; i++) {
    if (p.tab[i].command == 123)
      print_c(p.tab[i]);
    else
      printf("%c", p.tab[i].command);
  }
  printf("]");
};

void vider(PileCellules *p) { p->n = 0; };

void empiler(PileCellules *p, cellule_t x) {
  p->tab[p->n] = x;
  p->n++;
};

void depiler(PileCellules *p) { p->n--; };
