#include "crypt.h"
#include <stdio.h>
#include <string.h>

Sequence init() {
  Sequence seq;
  seq.longueur = 0;
  return seq;
}

Sequence stringToSeq(char *mess) {
  Sequence seq;

  strcpy(seq.chaine, mess);
  seq.longueur = strlen(mess);

  return seq;
}

int indexC(Sequence *cle, char c) {
  int i = 0;
  while (i < cle->longueur) {
    if (cle->chaine[i] == c) {
      return i;
    }
    i++;
  }
  return -1;
}

int ajoutChar(Sequence *cle, char c) {
  if (cle->longueur < LMAX - 1) {
    cle->chaine[cle->longueur] = c;
    cle->chaine[cle->longueur + 1] = '\0';
    cle->longueur = cle->longueur + 1;
    return 0;
  }
  return -1;
}

void decaleFin(Sequence *s, long i) {
  char c = s->chaine[i];
  long j;

  for (j = i; j < s->longueur; j++) {
    s->chaine[j] = s->chaine[j + 1];
  }
  s->chaine[s->longueur - 1] = c;
}

int lectureFichier(FILE *flux, Sequence *message) {
  char c;
  int index = 0;

  while (!feof(flux)) {
    fscanf(flux, "%c", &c);
    message->chaine[index] = c;
    index++;
  }
  message->chaine[index] = '\0';
  message->longueur = index;

  return 0;
}

Sequence crypt(Sequence *mess) {
  Sequence seq;
  Sequence crypt;
  char c = 'a';
  int i = 0;
  int indChar = 0;

  seq = init();
  crypt = init();

  while (i < mess->longueur) {
    c = mess->chaine[i];
    indChar = indexC(&seq, c);
    if (indChar != -1) {
      if (indChar != 0) {
        ajoutChar(&crypt, seq.chaine[indChar - 1]);
      } else {
        ajoutChar(&crypt, seq.chaine[seq.longueur - 1]);
      }
      decaleFin(&seq, indChar);
    } else {
      ajoutChar(&seq, c);
      ajoutChar(&crypt, c);
    }
    i++;
  }
  return crypt;
}

Sequence decrypt(Sequence *mess) {
  Sequence seq;
  Sequence decrypt;
  char c = 'a';
  int i = 0;
  int indChar = 0;

  seq = init();
  decrypt = init();

  while (i < mess->longueur) {
    c = mess->chaine[i];
    indChar = indexC(&seq, c);
    if (indChar != -1) {
      if (indChar == seq.longueur - 1) {
        ajoutChar(&decrypt, seq.chaine[0]);
        decaleFin(&seq, 0);
      } else {
        ajoutChar(&decrypt, seq.chaine[indChar + 1]);
        decaleFin(&seq, indChar + 1);
      }
    } else {
      ajoutChar(&seq, c);
      ajoutChar(&decrypt, c);
    }

    i++;
  }
  return decrypt;
}
