#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "calculette.h"
#include "curiosity.h"
#include "listes.h"
#include <ctype.h>

void stop() {
  char enter = '\0';
  printf("Appuyer sur entrée pour continuer...\n");
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
}

void print_c(cellule_t c) {
  cellule_t *c1 = &c;
  while (c1 != NULL) {
    printf("%c", c1->command);
    c1 = c1->suivant;
  }
  printf("; ");
}

void cloneListe(cellule_t *c, cellule_t **x) {
  cellule_t *a = nouvelleCellule();
  *a = *c;
  *x = a;
  while (c->suivant != NULL) {
    cellule_t *b = nouvelleCellule();
    c = c->suivant;
    *b = *c;
    a->suivant = b;
    a = a->suivant;
  }
}

void rotation(PileCellules *p, int n, int x) {
  int i;
  if (x == 0)
    return;
  else {
    cellule_t c = p->tab[p->n - n];
    for (i = p->n - n; i < p->n; i++) {
      p->tab[i] = p->tab[i + 1];
    }
    p->tab[p->n - 1] = c;

    rotation(p, n, x - 1);
  }
};

int interprete(sequence_t *seq, bool debug) {
  cellule_t *c = nouvelleCellule();
  c = seq->tete;

  PileCellules p;
  p.n = 0;

  cellule_t *z = nouvelleCellule();
  cellule_t *a = nouvelleCellule();
  cellule_t *b = nouvelleCellule();
  cellule_t *x = nouvelleCellule();

  while (c != NULL) {

    cellule_t *y = nouvelleCellule();

    int ret = -1;
    switch (c->command) {
    case '\n':
      break;
    case ' ':
      break;
    case '!':
      sommet(p, &x);
      depiler(&p);
      y = x;
      while (y->suivant->suivant != NULL) {
        y = y->suivant;
      }
      y->suivant = c->suivant;
      c->suivant = x->suivant;
      break;
    case '*':
      operation(&p, mul);
      break;
    case '+':
      operation(&p, add);
      break;
    case '-':
      operation(&p, sub);
      break;
    case '?':
      sommet(p, &x);
      depiler(&p);

      sommet(p, &y);
      depiler(&p);

      sommet(p, &z);
      depiler(&p);

      if (z->command == 0)
        a = x;
      else
        a = y;

      while (a->suivant->suivant != NULL) {
        a = a->suivant;
      }
      a->suivant = c->suivant;

      if (z->command == 0)
        c->suivant = x->suivant;
      else
        c->suivant = y->suivant;
      break;
    case 'A':
      ret = avance();
      break;
    case 'B':
      sommet(p, &x);
      depiler(&p);
      if (x->command > 0) {
        y->command = 'B';
        y->suivant = NULL;
        sommet(p, &z);
        depiler(&p);
        cloneListe(z, &b);
        empiler(&p, *b);
        a = z;
        while (a->suivant->suivant != NULL) {
          a = a->suivant;
        }
        a->suivant = y;
        y->suivant = c->suivant;
        c->suivant = z->suivant;
        x->command--;
        empiler(&p, *x);
      } else {
        depiler(&p);
      }
      break;
    case 'C':
      sommet(p, &x);
      cloneListe(x, &y);
      empiler(&p, *y);
      break;
    case 'D':
      droite();
      break;
    case 'G':
      gauche();
      break;
    case 'I':
      depiler(&p);
      break;
    case 'M':
      sommet(p, &x);
      depiler(&p);
      x->command = mesure(x->command);
      x->suivant = NULL;
      empiler(&p, *x);
      break;
    case 'P':
      sommet(p, &x);
      depiler(&p);
      pose(x->command);
      break;
    case 'R':
      sommet(p, &x);
      depiler(&p);

      sommet(p, &y);
      depiler(&p);

      rotation(&p, y->command, x->command);
      break;
    case 'X':
      sommet(p, &x);
      depiler(&p);
      sommet(p, &y);
      depiler(&p);
      empiler(&p, *x);
      empiler(&p, *y);
      break;
    case '{':
      *x = *c;
      y = x->suivant;
      int n = 1;
      while (n != 0) {
        if (y->command == '{')
          n++;
        if (y->command == '}')
          n--;
        if (n == 0) {
          *c = *y;
          y->suivant = NULL;
        } else {
          y = y->suivant;
        }
      }
      empiler(&p, *x);
      break;
    default:
      x->command = atoi(&c->command);
      x->suivant = NULL;
      empiler(&p, *x);
      break;
    }
    c = c->suivant;
    /* Ici on avance tout le temps, à remplacer pour gérer d'autres commandes
     */
    if (ret == VICTOIRE)
      return VICTOIRE; /* on a atteint la cible */
    if (ret == RATE)
      return RATE; /* tombé dans l'eau ou sur un rocher */

    /* Affichage pour faciliter le debug */
    //    afficherCarte();
    //    printf("Programme:");
    //    print_c(*c);
    //    printf("\n");
    //    printf("Pile:\n");
    //    print(p);
    //    printf("\n");
    if (debug)
      stop();
  }

  return CIBLERATEE;
}
