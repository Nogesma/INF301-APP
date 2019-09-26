//
// Created by Mano Ségransan on 18/09/2019.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int mod(int a, int b) {
  int ret = a % b;
  if (ret < 0)
    ret += b;
  return ret;
}

int cesar() {
  char *buffer;
  FILE *f = fopen("./message.txt", "r");
  size_t size = 512;
  buffer = (char *)malloc(size);
  getdelim(&buffer, &size, '\0', f);

  char premiereLettre;
  int diff = 'C' - buffer[0];
  int i = 0;

  while (buffer[i] != '\0') {
    if (isalpha(buffer[i])) {
      if (buffer[i] >= 'a')
        premiereLettre = 'a';
      else
        premiereLettre = 'A';

      buffer[i] = premiereLettre + mod(buffer[i] + diff - premiereLettre, 26);
    }
    i++;
  }

  printf("%s", buffer);
  return 0;
}