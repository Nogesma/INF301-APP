#include "listes.h"
#include <stdio.h>
#include <stdlib.h>

cellule_t *nouvelleCellule(void) {
  cellule_t *c;
  c = (cellule_t *)malloc(sizeof(cellule_t));
  return c;
}