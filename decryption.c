//
// Created by Mano Ségransan on 17/09/2019.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append(char *s, char c) {
  long len = strlen(s);
  s[len] = c;
  s[len + 1] = '\0';
}

void end(char *s, long i) {
  char c = s[i];
  long j;
  for (j = i; j < strlen(s); j++) {
    s[j] = s[j + 1];
  }
  s[j - 1] = c;
}

void decrypt(char c, char *sequence, char *decrypted) {
  long indexInSeq = -1;

  for (long i = 0; i < strlen(sequence); i++)
    if (c == sequence[i])
      indexInSeq = i;

  if (indexInSeq == -1) {
    append(sequence, c);
    append(decrypted, c);
  } else {
    if (indexInSeq == strlen(sequence) - 1) {
      append(decrypted, sequence[0]);
      end(sequence, 0);
    } else {
      append(decrypted, sequence[indexInSeq + 1]);
      end(sequence, indexInSeq + 1);
    }
  }
}

int main() {
  char *encryptedMessage;
  char *decryptedMessage;
  char *sequence;

  FILE *f = fopen("./Nothwood.txt", "r");
  size_t size = 512;
  encryptedMessage = (char *)malloc(size);

  size = getdelim(&encryptedMessage, &size, '\0', f);

  decryptedMessage = (char *)malloc(size);
  sequence = (char *)malloc(128);

  for (long i = 0; i < size; i++) {
    decrypt(encryptedMessage[i], sequence, decryptedMessage);
  }

  printf("%s", decryptedMessage);
  return 0;
}
