#include "calculette.h"
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

void operation(PileCellules *p, int (*f)(int, int)) {
  cellule_t *a = nouvelleCellule();
  cellule_t *b = nouvelleCellule();
  cellule_t *c = nouvelleCellule();

  sommet(*p, &a);
  depiler(p);
  sommet(*p, &b);
  depiler(p);

  c->command = f(b->command, a->command);
  empiler(p, *c);
}