//
// Created by Mano Ségransan on 17/09/2019.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append2(char *s, char c) {
  unsigned long len = strlen(s);
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

void encrypt(char c, char *sequence, char *encrypted) {
  long indexInSeq = -1;

  for (long i = 0; i < strlen(sequence); i++)
    if (c == sequence[i])
      indexInSeq = i;

  if (indexInSeq == -1) {
    append2(sequence, c);
    append2(encrypted, c);
  } else {
    if (indexInSeq == 0) {
      append2(encrypted, sequence[strlen(sequence) - 1]);
    } else {
      append2(encrypted, sequence[indexInSeq - 1]);
    }
    end(sequence, indexInSeq);
  }
}

int main() {
  char *encryptedMessage;
  char *message;
  char *sequence;

  FILE *f = fopen("./message.txt", "r");
  FILE *fc = fopen("./cryptedMessage.txt", "w");
  size_t size = 512;
  message = (char *)malloc(size);

  size = getdelim(&message, &size, '\0', f);

  encryptedMessage = (char *)malloc(size);
  sequence = (char *)malloc(128);

  for (long i = 0; i < size; i++) {
    encrypt(message[i], sequence, encryptedMessage);
  }

  fprintf(fc, "%s", encryptedMessage);
  return 0;
}
