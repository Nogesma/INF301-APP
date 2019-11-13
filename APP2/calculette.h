#ifndef APP2_CALCULETTE_H
#define APP2_CALCULETTE_H

#include "type_pile.h"
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

void operation(PileCellules *p, int (*f)(int, int));

#endif // APP2_CALCULETTE_H
